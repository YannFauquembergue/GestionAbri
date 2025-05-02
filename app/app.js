const net = require("net");

// Classe pour la carte ES1 permettant d'écrire sur un Output (sortie)
class CarteES1 {
    constructor(ip, port) {
        this.ip = ip;
        this.port = port;
        this.TCPClient = new net.Socket();
        this.TCPClient.connect(port, ip, () => {
            console.log(`Connecté à la carte ES1 sur ${ip}:${port}`);
        });

        this.TCPClient.on("error", (err) => {
            console.error("Erreur de connexion ES1:", err.message);
        });
    }

    writeOutput(id, value) {
        const message = `${id},${value ? 1 : 0}\n`;
        this.TCPClient.write(message, (err) => {
            if (err) {
                console.error("Erreur d'envoi de données ES1:", err);
            } else {
                console.log(`Commande envoyée à ES1: ${message.trim()}`);
            }
        });
    }
}

// Classe pour la carte ES2 permettant de lire l'état des différentes Input (Actionneur ou Capteur)
class CarteES2 {
    constructor(ip, port) {
        this.ip = ip;
        this.port = port;
        this.TCPClient = new net.Socket();
        this.TCPClient.connect(port, ip, () => {
            console.log(`Connecté à la carte ES2 sur ${ip}:${port}`);
        });

        this.TCPClient.on("error", (err) => {
            console.error("Erreur de connexion ES2:", err.message);
        });
    }

    readState(id, callback) {
        this.TCPClient.write(`READ,${id}\n`, (err) => {
            if (err) {
                console.error("Erreur d'envoi de requête ES2:", err);
            } else {
                console.log(`Requête envoyée à ES2: READ,${id}`);
            }
        });

        this.TCPClient.once("data", (data) => {
            console.log(`Réponse reçue de ES2: ${data.toString().trim()}`);
            callback(data.toString().trim() === "1");
        });
    }
}

class Box {
    constructor(id, es1, es2) {
        this.id = id;
        this.ES1 = es1;
        this.ES2 = es2;
    }

    assignUser(user) {
        this.user = user;
    }

    openTheDoor() {
        this.ES1.writeOutput(1, true);
        console.log("Porte ouverte");
    }

    closeTheDoor() {
        this.ES1.writeOutput(1, false);
        console.log("Porte fermée");
    }

    switchOnTheLight() {
        this.ES1.writeOutput(2, true);
        console.log("Lumière allumée");
    }

    turnOffTheLight() {
        this.ES1.writeOutput(2, false);
        console.log("Lumière éteinte");
    }

    turnOnThePower() {
        this.ES1.writeOutput(3, true);
        console.log("Alimentation activée");
    }

    turnOffThePower() {
        this.ES1.writeOutput(3, false);
        console.log("Alimentation désactivée");
    }

    getDoorState(callback) {
        this.ES2.readState(1, (state) => {
            console.log(`État de la porte: ${state ? "Ouverte" : "Fermée"}`);
            callback(state);
        });
    }

    getPowerConsumptionState(callback) {
        this.ES2.readState(2, (state) => {
            console.log(`Consommation électrique: ${state ? "Active" : "Inactive"}`);
            callback(state);
        });
    }

    static loadAllBoxes() {
        return [new Box(1, new CarteES1("192.168.1.100", 12345), new CarteES2("192.168.1.101", 12346))];
    }
}

// Définition des IP et ports pour la simulation
const IP_ES1 = "127.0.0.1";
const PORT_ES1 = 12345;
const IP_ES2 = "127.0.0.1";
const PORT_ES2 = 12346;

// Création des instances simulées
const es1 = new CarteES1(IP_ES1, PORT_ES1);
const es2 = new CarteES2(IP_ES2, PORT_ES2);
const box = new Box(1, es1, es2);

// Tests
console.log("Démarrage des tests...");
box.turnOnThePower()
