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
            // 1. Générer deux consommations réalistes
            const kwhSolaire = (Math.random() * (5 - 0.5) + 0.5).toFixed(2); // entre 0.5 et 5 kWh
            const kwhEDF = (Math.random() * (7 - 1) + 1).toFixed(2);         // entre 1 et 7 kWh

            // 2. Calculer les pourcentages
            const total = parseFloat(kwhSolaire) + parseFloat(kwhEDF);
            const pourcentageSolaire = ((kwhSolaire / total) * 100).toFixed(1);
            const pourcentageEDF = ((kwhEDF / total) * 100).toFixed(1);

            // 3. Envoyer les données
            this.sendMessage(kwhSolaire, khwEDF);
            console.log(`Envoyé: Solaire=${kwhSolaire}kWh (${pourcentageSolaire}%), EDF=${kwhEDF}kWh (${pourcentageEDF}%)`);
        }, 15000);
    }
}

const carte = new CarteES("192.168.64.151", 9090);
carte.startSendingData();
