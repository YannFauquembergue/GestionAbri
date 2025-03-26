const net = require("net");
const mysql = require("mysql");
const dotenv = require("dotenv");

dotenv.config();

const PORT = 9090;

const bddConnection = mysql.createConnection({
    host: process.env.BDD_HOST,
    database: process.env.BDD_DATABASE,
    user: process.env.BDD_USER,
    password: process.env.BDD_PASSWORD
});

bddConnection.connect((err) => {
    if (err) {
        console.error("Erreur de connexion à la BDD:", err);
        process.exit(1);
    }
    console.log("Connexion à la BDD réussie");
});

const server = net.createServer((socket) => {
    console.log("Client connecté");

    socket.on("data", (data) => {
        try {
            const message = data.toString().trim();
            const [kwSolaire, kwEDF] = message.split(",");
            console.log(`Reçu: kwSolaire=${kwSolaire}, kwEDF=${kwEDF}`);

            const query = "UPDATE Consommation SET kwSolaire = ?, kwEDF = ? LIMIT 1";
            bddConnection.query(query, [kwSolaire, kwEDF], (err) => {
                if (err) {
                    console.error("Erreur SQL:", err);
                    socket.write("Erreur SQL\n");
                } else {
                    console.log("Données mises à jour en BDD");
                    socket.write("Données reçues et stockées\n");
                }
            });
        } catch (error) {
            console.error("Erreur lors du traitement des données:", error);
            socket.write("Erreur de traitement\n");
        }
    });

    socket.on("close", () => {
        console.log("Client déconnecté");
    });

    socket.on("error", (err) => {
        console.error("Erreur socket:", err.message);
    });
});

function afficherConsommation() {
    const query = "SELECT kwSolaire, kwEDF FROM Consommation LIMIT 1";
    bddConnection.query(query, (err, results) => {
        if (err) {
            console.error("Erreur lors de la récupération des données:", err);
            return;
        }
        if (results.length > 0) {
            console.log(`Valeurs actuelles: kwSolaire=${results[0].kwSolaire}, kwEDF=${results[0].kwEDF}`);
        } else {
            console.log("Aucune donnée disponible");
        }
    });
}

server.listen(PORT, () => {
    console.log(`Serveur TCP en écoute sur le port ${PORT}`);
    setInterval(afficherConsommation, 5000);
});
