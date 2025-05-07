const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const dotenv = require('dotenv');
const rateLimit = require('express-rate-limit');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcrypt');

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

const port = 8080;

const reader = new RFIDReader(process.env.RFID_HOST);

async function ConnectRFID() {
    try {
      await reader.connect()
  
      const tag = await reader.readRFIDTag(1000, 10)
      console.log('Tag lu :', tag)
    } catch (err) {
      console.error(err)
    }
  }

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

const verifyToken = (req, res, next) => {
    const token = req.headers['authorization'];
    if (!token) return res.status(403).json({ error: "Accès refusé, token manquant" });

    jwt.verify(token, secretKey, (err, decoded) => {
        if (err) return res.status(401).json({ error: "Token invalide" });
        req.user = decoded;
        next();
    });
};

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


app.get('/test', (req, res) => {
    console.log("Route test appelée");
    res.json({ message: "Réception test !" });
});

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

app.listen(port, () => {
    console.log(`Serveur démarré sur le port ${port}`);
    setInterval(resetQuotasIfNeeded, 60 * 60 * 1000);
});
