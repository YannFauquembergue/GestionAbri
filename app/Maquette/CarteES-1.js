const net = require("net");

class CarteES {
    constructor(host, port) {
        this.host = host;
        this.port = port;
        this.client = new net.Socket();
        this.setupClient();
    }

    setupClient() {
        this.client.connect(this.port, this.host, () => {
            console.log(`Connecté à ${this.host}:${this.port}`);
        });

        this.client.on("data", (data) => {
            console.log("Réponse du serveur :", data.toString());
        });

        this.client.on("close", () => {
            console.log("Connexion fermée");
        });

        this.client.on("error", (err) => {
            console.error("Erreur :", err.message);
        });
    }

    sendMessage(kwSolaire, kwEDF) {
        const message = `${kwSolaire},${kwEDF}`;
        this.client.write(message);
    }

    startSendingData() {
        setInterval(() => {
            const kwSolaire = Math.floor(Math.random() * 101);
            const kwEDF = 100 - kwSolaire;
            this.sendMessage(kwSolaire, kwEDF);
            console.log(`Envoyé: kwSolaire=${kwSolaire}, kwEDF=${kwEDF}`);
        }, 15000);
    }
}

const carte = new CarteES("192.168.64.151", 9090);
carte.startSendingData();
