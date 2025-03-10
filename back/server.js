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

app.get(
    '/getUsers',
    (req, res) => {
        try {
            bddConnection.query("SELECT * FROM Utilisateur", (err, results) => {
                if (err) {
                    return res.status(500).send({ error: err.message });
                }
                res.json(results);
            });
        } catch (error) {
            res.status(500).json({"ERREUR BDD: ":error});
        }
    }
)

app.post(
    '/addUser',
    (req, res) => {
        try {
            const query = `INSERT INTO Utilisateur (nom, prenom, nickname, password) VALUES (?, ?, ?, ?)`;
            bddConnection.query(query, [req.body.nom, req.body.prenom, req.body.nickname, req.body.password], (error, results) => {
                if (error) {
                    return res.status(500).json({ error: error.message });
                }
                res.json(results);
            });
        } catch (error) {
            res.status(500).json({"ERREUR BDD: ":error});
        }
    }
);

