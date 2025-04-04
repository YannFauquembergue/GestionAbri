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
    console.log("Tentative d'ajout d'un utilisateur")
    try {
        const query = `INSERT INTO Utilisateur (nom, prenom, nickname, password, rfid) VALUES (?, ?, ?, ?, ?)`;
        bddConnection.query(query, [req.body.nom, req.body.prenom, req.body.nickname, req.body.password, req.body.rfid], (error, results) => {
            if (error) {
                return res.status(500).json({ error: error.message });
            }
            console.log("Utilisateur " + req.body.nickname + " ajouté avec succès");
            res.json(results);
        });
    } catch (error) {
       res.status(500).json({"ERREUR SQL: ":error});
    }
});

