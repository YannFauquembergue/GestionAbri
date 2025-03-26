const express = require('express');
const mysql = require('mysql2');
const cors = require('cors');
const dotenv = require('dotenv');
const rateLimit = require('express-rate-limit');
const jwt = require('jsonwebtoken');

dotenv.config();
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

    jwt.verify(token, process.env.JWT_SECRET, (err, decoded) => {
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
        res.json(results[0]);
    });
});

app.get('/getUsers', verifyToken, (req, res) => {
    console.log("Tentative de récupération de tous les utilisateurs");
    
    const query = "SELECT * FROM Utilisateur";
    bddConnection.query(query, (err, results) => {
        if (err) return res.status(500).json({ error: err.message });
        res.json(results);
    });
});

app.get('/test', (req, res) => {
    console.log("Route test appelée");
    res.json({ message: "Réception test !" });
});

app.post('/addUser', verifyToken, (req, res) => {
    console.log("Tentative d'ajout ou mise à jour d'un utilisateur");
    
    const { nom, prenom, nickname, password, rfid } = req.body;
    if (!nom || !prenom || !nickname || !password || !rfid) {
        return res.status(400).json({ error: "Informations incomplètes" });
    }

    const checkQuery = "SELECT * FROM Utilisateur WHERE nickname = ?";
    bddConnection.query(checkQuery, [nickname], (err, results) => {
        if (err) return res.status(500).json({ error: err.message });

        if (results.length > 0) {
            const updateQuery = "UPDATE Utilisateur SET nom = ?, prenom = ?, password = ?, rfid = ? WHERE nickname = ?";
            bddConnection.query(updateQuery, [nom, prenom, password, rfid, nickname], (err) => {
                if (err) return res.status(500).json({ error: err.message });
                console.log(`Utilisateur ${nickname} mis à jour`);
                res.json({ message: `Utilisateur ${nickname} mis à jour` });
            });
        } else {
            const insertQuery = "INSERT INTO Utilisateur (nom, prenom, nickname, password, rfid) VALUES (?, ?, ?, ?, ?)";
            bddConnection.query(insertQuery, [nom, prenom, nickname, password, rfid], (err) => {
                if (err) return res.status(500).json({ error: err.message });
                console.log(`Utilisateur ${nickname} ajouté`);
                res.json({ message: `Utilisateur ${nickname} ajouté` });
            });
        }
    });
});


app.listen(port, () => {
    console.log(`Serveur démarré sur le port ${port}`);
});
