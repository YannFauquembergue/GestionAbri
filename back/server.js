const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const dotenv = require('dotenv');

dotenv.config();

const app = express();

app.use(express.json());
app.use(cors());

const port = 8080;

app.listen( port,
    () => { console.log('Serveur en marche sur le port ' + port); }
);

const bddConnection = mysql.createConnection(
    {
        host: process.env.BDD_HOST,
        database: process.env.BDD_DATABASE,
        user: process.env.BDD_USER,
        password: process.env.BDD_PASSWORD
    }
);

bddConnection.connect(
    function (err) { if (err) throw err; console.log("Connexion à la BDD réussie"); }
);

app.get('/getUser/:id', (req, res) => {
    const userId = parseInt(req.params.id);
    if (isNaN(userId)) {
        return res.status(400).json({ error: "ERREUR: ID utilisateur invalide" });
    }
    console.log("Tentative de récupération d'un utilisateur")
    try {
        bddConnection.query("SELECT * FROM Utilisateur WHERE ?", [userId], (err, results) => {
            if (err) {
                return res.status(500).send({ error: err.message });
            }
            console.log("Utilisateur récupéré avec succès.")
            res.json(results);
        });
    } catch (error) {
        res.status(500).json({"ERREUR SQL: ":error});
    }
})

app.get('/getUsers', (req, res) => {
    console.log("Tentative de récupération des utilisateurs")
    try {
        bddConnection.query("SELECT * FROM Utilisateur", (err, results) => {
            if (err) {
                return res.status(500).send({ error: err.message });
            }
            console.log("Utilisateurs récupérés avec succès.")
            res.json(results);
        });
    } catch (error) {
        res.status(500).json({"ERREUR SQL: ":error});
    }
})

app.get('/test', (req, res) => {
    console.log("Route test appelée")
    res.json({ message: "Réception test !" });
});

app.post('/addUser', (req, res) => {
    console.log("Tentative d'ajout ou de mise à jour d'un utilisateur");

    try {
        const { nom, prenom, nickname, password, rfid } = req.body;
        const checkQuery = `SELECT * FROM Utilisateur WHERE nickname = ?`;
        bddConnection.query(checkQuery, [nickname], (checkError, checkResults) => {
            if (checkError) {
                return res.status(500).json({ error: checkError.message });
            }
            if (checkResults.length > 0) {
                // L'utilisateur existe, on le met à jour
                const updateQuery = `UPDATE Utilisateur SET nom = ?, prenom = ?, password = ?, rfid = ? WHERE nickname = ?`;

                bddConnection.query(updateQuery, [nom, prenom, password, rfid, nickname], (updateError, updateResults) => {
                    if (updateError) {
                        return res.status(500).json({ error: updateError.message });
                    }
                    console.log(`Utilisateur ${nickname} mis à jour avec succès`);
                    res.json({ message: `Utilisateur ${nickname} mis à jour`, results: updateResults });
                });
            } else {
                // L'utilisateur n'existe pas, on l'ajoute
                const insertQuery = `INSERT INTO Utilisateur (nom, prenom, nickname, password, rfid) VALUES (?, ?, ?, ?, ?)`;

                bddConnection.query(insertQuery, [nom, prenom, nickname, password, rfid], (insertError, insertResults) => {
                    if (insertError) {
                        return res.status(500).json({ error: insertError.message });
                    }
                    console.log(`Utilisateur ${nickname} ajouté avec succès`);
                    res.json({ message: `Utilisateur ${nickname} ajouté`, results: insertResults });
                });
            }
        });
    } catch (error) {
        res.status(500).json({ "ERREUR SQL": error.message });
    }
});

