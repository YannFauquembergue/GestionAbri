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
            this.sendMessage("Connecté");
        });

        this.client.on("data", (data) => {
            console.log("Réponse du serveur :", data.toString());
            this.client.destroy();
        });

        this.client.on("close", () => {
            console.log("Connexion fermée");
        });

        this.client.on("error", (err) => {
            console.error("Erreur :", err.message);
        });
    }

    sendMessage(message) {
        this.client.write(message);
    }
}

// Exemple d'utilisation
// const carte = new CarteES("192.168.64.151", 8080);
