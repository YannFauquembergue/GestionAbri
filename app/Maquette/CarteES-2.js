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

    // Simulation des capteurs pour les 8 box
    readDigitalInputsFromCard() {
        // Simule 8 entrées numériques avec valeurs aléatoires (0 ou 1)
        return Array.from({ length: 8 }, () => Math.round(Math.random()));
    }

    // Retourne le statut courant de chaque box
    getBoxesCurrentStatus() {
        const sensors = this.readDigitalInputsFromCard();

        const statusList = sensors.map((value, index) => ({
            idBox: index + 1,
            currentStatus: value === 1
        }));

        return statusList;
    }
}

// Utilisation
const carte = new CarteES("192.168.64.151", 9090);

// Exemple d'appel toutes les 10 secondes pour afficher le statut
setInterval(() => {
    const status = carte.getBoxesCurrentStatus();
    console.log("Statut des box :", JSON.stringify(status, null, 2));
}, 10000);
