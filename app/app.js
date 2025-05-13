const net = require("net");
const readline = require("readline");

// Interface utilisateur
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Classe pour la carte ES1
class CarteES1 {
    constructor(ip, port) {
        this.ip = ip;
        this.port = port;
        this.TCPClient = new net.Socket();
        this.TCPClient.setEncoding('utf8');
        this.TCPClient.connect(port, ip, () => {
            console.log(`Connecté à la carte ES1 sur ${ip}:${port}`);
        });
        this.TCPClient.on("error", (err) => {
            console.error("Erreur de connexion ES1:", err.message);
        });
    }

    writeOutput(id, value) {
        const message = `${id},${value ? 1 : 0}\n`;
        this.TCPClient.write(message);
    }

    close() {
        this.TCPClient.end();
    }
}

// Classe pour la carte ES2
class CarteES2 {
    constructor(ip, port) {
        this.ip = ip;
        this.port = port;
        this.TCPClient = new net.Socket();
        this.TCPClient.setEncoding('utf8');
        this.TCPClient.connect(port, ip, () => {
            console.log(`Connecté à la carte ES2 sur ${ip}:${port}`);
        });
        this.TCPClient.on("error", (err) => {
            console.error("Erreur de connexion ES2:", err.message);
        });
    }

    readState(id, callback) {
        this.TCPClient.write(`READ,${id}\n`);
        this.TCPClient.once("data", (data) => {
            callback(data.trim() === "1");
        });
    }

    close() {
        this.TCPClient.end();
    }
}

// Classe Box
class Box {
    constructor(id, es1, es2) {
        this.id = id;
        this.ES1 = es1;
        this.ES2 = es2;
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
        this.ES2.readState(1, callback);
    }

    getLightState(callback) {
        this.ES2.readState(2, callback);
    }

    getPowerConsumptionState(callback) {
        this.ES2.readState(3, callback);
    }

    close() {
        this.ES1.close();
        this.ES2.close();
    }

    static loadAllBoxes() {
        return [new Box(1, new CarteES1("127.0.0.1", 12345), new CarteES2("127.0.0.1", 12346))];
    }
}

// Création de la box
const box = Box.loadAllBoxes()[0];

function showMenu() {
    console.log('\n=== Menu Box ===');
    console.log('1. Ouvrir la porte');
    console.log('2. Fermer la porte');
    console.log('3. Allumer la lumière');
    console.log('4. Éteindre la lumière');
    console.log('5. Activer l’alimentation');
    console.log('6. Désactiver l’alimentation');
    console.log('7. Quitter');
    rl.question('Choix : ', handleMenu);
}

function handleMenu(choice) {
    switch (choice) {
        case '1': box.openTheDoor(); break;
        case '2': box.closeTheDoor(); break;
        case '3': box.switchOnTheLight(); break;
        case '4': box.turnOffTheLight(); break;
        case '5': box.turnOnThePower(); break;
        case '6': box.turnOffThePower(); break;
        case '7':
            rl.close();
            box.close();
            console.log("Déconnexion...");
            return;
        default:
            console.log('Choix invalide');
    }
    setTimeout(showMenu, 200);
}

// Lancement
showMenu();
