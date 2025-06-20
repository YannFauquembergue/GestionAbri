const express = require('express');
const mysql = require('mysql');
const cors = require('cors');

const dotenv = require('dotenv');

const rateLimit = require('express-rate-limit');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');

const axios = require('axios');

const RFIDReader = require('./RFIDReader');

dotenv.config();

const secretKey = process.env.TOKEN_KEY;
const defaultQuota = parseInt(process.env.DEFAULT_QUOTA, 10);

const app = express();

app.use(express.json());
app.use(cors());

const limiter = rateLimit({
    windowMs: 1000,
    max: 10,
    message: { error: "Trop de requêtes, veuillez réessayer plus tard." }
});
app.use(limiter);

const port = process.env.SERVER_PORT;

const reader = new RFIDReader(process.env.RFID_HOST);

// Fonction pour établir la connexion au lecteur RFID TCP
async function ConnectRFID() {
    try {
      await reader.connect()
  
    let lastTag = null;

    setInterval(async () => {
        try {
            const tag = await reader.readRFIDTag(0, 20);

            if (tag && tag.length > 0 && tag !== lastTag) {
            console.log('Tag détecté : ', tag);
            lastTag = tag;

            // Appel de l’API /checkAccess
            try {
                const response = await axios.get(`http://localhost:${port}/checkAccess/${tag}`);
                console.log('Réponse checkAccess:', response.data);
            } catch (apiErr) {
                console.error('Erreur checkAccess:', apiErr.response?.data || apiErr.message);
            }
            }
        } catch (err) {
            console.error('Erreur de lecture RFID :', err);
        }
        }, 2000);
    } catch (err) {
      console.error(err)
    }
  }

  // Fonction pour réinitialiser les quotas si nécessaire
 async function resetQuotasIfNeeded() {
    const now = new Date();
    const isMondayAt2AM = now.getDay() === 1 && now.getHours() === 2;

    if (!isMondayAt2AM) return;

    console.log("Début de la remise à zéro des quotas...");

    const selectQuery = "SELECT id, quota FROM Utilisateur";
    bddConnection.query(selectQuery, (err, users) => {
        if (err) return console.error("Erreur lors de la récupération des utilisateurs:", err);

        users.forEach(user => {
            let newQuota = defaultQuota;
            if (user.quota < 0) {
                newQuota += user.quota;
            }

            const updateQuery = "UPDATE Utilisateur SET quota = ? WHERE id = ?";
            bddConnection.query(updateQuery, [newQuota, user.id], (err) => {
                if (err) console.error(`Erreur mise à jour quota pour user ${user.id}:`, err);
            });
        });

        console.log("Remise à zéro des quotas terminée.");
    });
}
  
ConnectRFID();

// Fonction pour vérifier l'état des box, puis décrémenter le capital des utilisateurs concernés
async function checkBoxStates() {
    try {
        const response = await axios.get('http://localhost:8080/boxes');
        const boxData = response.data;

        const usersToDecrement = [];
        const boxesToIncrement = [];

        boxData.forEach(box => {
            if (box.idUser) {
                usersToDecrement.push(box.idUser);
            }
            if (!box.idUser && box.last_userId) {
                boxesToIncrement.push(box.id);
            }
        });

        if (usersToDecrement.length > 0) {
            await axios.post('http://localhost:8080/decrementQuota', { users: usersToDecrement });
            console.log(`Quotas décrémentés pour: ${usersToDecrement.join(', ')}`);
        }

        if (boxesToIncrement.length > 0) {
            await axios.post('http://localhost:8080/incrementBoxTime', { boxes: boxesToIncrement });
            console.log(`Temps incrémenté pour les boxes: ${boxesToIncrement.join(', ')}`);
        }

    } catch (err) {
        console.error('Erreur dans checkBoxStates:', err.message);
    }
}

// Route pour récupérer les box
app.get('/boxes', (req, res) => {
    const query = "SELECT id, startDate, idUser, last_userId FROM Box";

    bddConnection.query(query, (err, results) => {
        if (err) return res.status(500).json({ error: err.message });

        const boxes = results.map(box => ({
            ...box,
            startDate: box.startDate.toISOString().split('T')[0]
        }));

        res.json(boxes);
    });
});

app.post('/updateBoxUser', (req, res) => {
    const { id, idUser } = req.body;

    if (typeof id !== 'number') {
        return res.status(400).json({ error: "ID de box invalide" });
    }

    const query = "UPDATE Box SET idUser = ? WHERE id = ?";
    bddConnection.query(query, [idUser ?? null, id], (err, result) => {
        if (err) return res.status(500).json({ error: err.message });

        if (result.affectedRows === 0) {
            return res.status(404).json({ error: "Box non trouvé" });
        }

        res.json({ message: `Box ${id} mis à jour avec idUser=${idUser}` });
    });
});

app.post('/openBox', (req, res) => {
    const { id } = req.body;

    if (typeof id !== 'number') {
        return res.status(400).json({ error: "ID de box invalide" });
    }

    // Simulation de l'ouverture du box
    console.log(`Ouverture simulée du box ${id}`);
    res.json({ message: `Box ${id} ouvert (simulation)` });
});

app.post('/decrementQuota', (req, res) => {
    const { users } = req.body;

    if (!Array.isArray(users) || users.length === 0) {
        return res.status(400).json({ error: "Liste d'utilisateurs invalide ou vide" });
    }

    const query = "UPDATE Utilisateur SET quota = quota - 1 WHERE id IN (?)";
    bddConnection.query(query, [users], (err, results) => {
        if (err) return res.status(500).json({ error: err.message });
        res.json({ message: "Quota décrémenté", affected: results.affectedRows });
    });
});


app.post('/incrementBoxTime', (req, res) => {
    const { boxes } = req.body;

    if (!Array.isArray(boxes) || boxes.length === 0) {
        return res.status(400).json({ error: "Liste de box invalide ou vide" });
    }
    const getUsersQuery = "SELECT last_userId FROM Box WHERE id IN (?)";
    bddConnection.query(getUsersQuery, [boxes], (err, results) => {
        if (err) return res.status(500).json({ error: err.message });

        const userIds = results.map(row => row.last_userId);
        if (userIds.length === 0) return res.status(404).json({ error: "Aucun utilisateur trouvé" });

        const updateUserQuery = "UPDATE Utilisateur SET temps_energie_renouvelable = IFNULL(temps_energie_renouvelable, 0) + 1 WHERE id IN (?)";
        bddConnection.query(updateUserQuery, [userIds], (err, updateResults) => {
            if (err) return res.status(500).json({ error: err.message });
            res.json({ message: "Temps incrémenté pour les utilisateurs", affected: updateResults.affectedRows });
        });
    });
});

// Etablissement de la connexion à la base de données
const bddConnection = mysql.createConnection({
    host: process.env.BDD_HOST,
    database: process.env.BDD_DATABASE,
    user: process.env.BDD_USER,
    password: process.env.BDD_PASSWORD
});

bddConnection.connect((err) => {
    if (err) throw err;
    console.log("Connexion à la BDD établie");
});

// Constante pour vérification par token
const verifyToken = (req, res, next) => {
    const token = req.headers['authorization'];
    if (!token) return res.status(403).json({ error: "Accès refusé, token manquant" });

    jwt.verify(token, secretKey, (err, decoded) => {
        if (err) return res.status(401).json({ error: "Token invalide" });
        req.user = decoded;
        next();
    });
};

// Route pour récupérer un utilisateur par id
app.get('/getUser/:id', verifyToken, (req, res) => {
    const userId = parseInt(req.params.id);
    if (isNaN(userId)) {
        return res.status(400).json({ error: "ID utilisateur invalide" });
    }

    console.log(`Tentative de récupération de l'utilisateur ID: ${userId}`);
    
    const query = "SELECT * FROM Utilisateur WHERE id = ?";
    bddConnection.query(query, [userId], (err, results) => {
        if (err) return res.status(500).json({ error: err.message });
        if (results.length === 0) return res.status(404).json({ error: "Utilisateur non trouvé" });

        const user = results[0];
        delete user.password; // Ne pas envoyer le password hashé
        res.json(user);
    });
});

// Route pour récupérer tous les utilisateurs de la base de données
app.get('/getUsers', (req, res) => {
    console.log("Tentative de récupération de tous les utilisateurs");
    
    const query = "SELECT * FROM Utilisateur";
    bddConnection.query(query, (err, results) => {
        if (err) return res.status(500).json({ error: err.message });

        const users = results.map(user => {
            delete user.password; // Supprimer le mot de passe pour chaque utilisateur
            return user;
        });

        res.json(users);
    });
});

// Route pour supprimer un utilisateur sélectionné par id
app.delete('/deleteUser/:id', (req, res) => {
    const userId = parseInt(req.params.id);
    if (isNaN(userId)) {
        return res.status(400).json({ error: "ID utilisateur invalide" });
    }

    console.log(`Tentative de suppression de l'utilisateur ID: ${userId}`);
    
    const query = "DELETE FROM Utilisateur WHERE id = ?";
    bddConnection.query(query, [userId], (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message });
        }

        if (results.affectedRows === 0) {
            return res.status(404).json({ error: "Utilisateur non trouvé ou déjà supprimé" });
        }

        res.json({ message: "Utilisateur supprimé avec succès", id: userId });
    });
});

app.get('/checkAccess/:rfid', async (req, res) => {
    const userRFID = parseInt(req.params.rfid);
    if (isNaN(userRFID)) {
        return res.status(400).json({ error: "RFID utilisateur invalide" });
    }

    const userQuery = "SELECT id, quota, last_acces_to_box FROM Utilisateur WHERE rfid = ?";
    bddConnection.query(userQuery, [userRFID], async (err, results) => {
        if (err) {
            return res.status(500).json({ error: err.message });
        }

        if (results.length === 0) {
            return res.status(404).json({ error: "Utilisateur non trouvé" });
        }

        const { id: userId, quota, last_acces_to_box } = results[0];

        const currentTime = new Date();
        const lastAccess = new Date(last_acces_to_box);
        const diffHours = (currentTime - lastAccess) / (1000 * 60 * 60);

        const allowedDelay = parseFloat(process.env.PERM_ACCESS_TIME || "24"); // par défaut 24h
        if (diffHours > allowedDelay) {
            return res.status(403).json({
                error: `Accès refusé : plus de ${allowedDelay}h depuis le dernier accès.`,
                quota
            });
        }

        // Rechercher un box disponible dans la base de données
        const boxQuery = "SELECT id FROM Box WHERE idUser IS NULL LIMIT 1";
        bddConnection.query(boxQuery, async (boxErr, boxResults) => {
            if (boxErr) {
                return res.status(500).json({ error: boxErr.message });
            }

            if (boxResults.length === 0) {
                return res.status(503).json({ error: "Aucun box disponible pour le dépôt de vélo" });
            }

            const availableBoxId = boxResults[0].id;

            try {
                // Mise à jour du box via l'API
                await axios.post('http://localhost:8080/updateBoxUser', {
                    id: availableBoxId,
                    idUser: userId
                });

                // Ouverture du box
                await axios.post('http://localhost:8080/openBox', { id: availableBoxId });

                return res.status(200).json({
                    message: "Vélo déposé avec succès, box ouvert",
                    boxId: availableBoxId,
                    quota
                });
            } catch (updateErr) {
                console.error("Erreur mise à jour/ouverture box :", updateErr.message);
                return res.status(500).json({ error: "Erreur lors de la procédure de dépôt" });
            }
        });
    });
});

// Route de test
app.get('/test', (req, res) => {
    console.log("Route test appelée");
    res.json({ message: "Réception test !" });
});

// Route poru ajouter un utilisateur
app.post('/addUser', async (req, res) => {
    console.log("Tentative d'ajout ou mise à jour d'un utilisateur");
    
    const { nom, prenom, nickname, password, rfid } = req.body;
    if (!nom || !prenom || !nickname || !password || !rfid) {
        return res.status(400).json({ error: "Informations incomplètes" });
    }

    try {
        const hashedPassword = await bcrypt.hash(password, 10);

        const token = jwt.sign({ nickname }, secretKey, { expiresIn: '7d' });

        const checkQuery = "SELECT * FROM Utilisateur WHERE nickname = ?";
        bddConnection.query(checkQuery, [nickname], (err, results) => {
            if (err) return res.status(500).json({ error: err.message });

            if (results.length > 0) {
                const updateQuery = "UPDATE Utilisateur SET nom = ?, prenom = ?, password = ?, rfid = ?, token = ? WHERE nickname = ?";
                bddConnection.query(updateQuery, [nom, prenom, hashedPassword, rfid, token, nickname], (err) => {
                    if (err) return res.status(500).json({ error: err.message });
                    console.log(`Utilisateur ${nickname} mis à jour`);
                    res.json({ message: `Utilisateur ${nickname} mis à jour`, token });
                });
            } else {
                const insertQuery = "INSERT INTO Utilisateur (nom, prenom, nickname, password, rfid, token) VALUES (?, ?, ?, ?, ?, ?)";
                bddConnection.query(insertQuery, [nom, prenom, nickname, hashedPassword, rfid, token], (err) => {
                    if (err) return res.status(500).json({ error: err.message });
                    console.log(`Utilisateur ${nickname} ajouté`);
                    res.json({ message: `Utilisateur ${nickname} ajouté`, token });
                });
            }
        });
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: "Erreur lors du hashage du mot de passe" });
    }
});

// Mettre le serveur en écoute sur le port sélectionné
app.listen(port, () => {
    console.log(`Serveur démarré sur le port ${port}`);
    setInterval(resetQuotasIfNeeded, 60 * 60 * 1000);
    setInterval(checkBoxStates, 60 * 1000);
});
