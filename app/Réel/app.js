const net = require("net");
const readline = require("readline");

//Interface utilisateur CLI
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

//Classe Carte physique ETH-IO32
class CarteETHIO32 {
    constructor(ip, port) {
        this.ip = ip;
        this.port = port;
        this.TCPClient = new net.Socket();
        this.TCPClient.setEncoding('utf8');
        this.TCPClient.connect(port, ip, () => {
            console.log(`Connecté à la carte ETH-IO32 sur ${ip}:${port}`);
        });
        this.TCPClient.on("error", (err) => {
            console.error("Erreur de connexion :", err.message);
        });
    }

    writeOutput(id, value) {
        const cmd = value ? `relay on ${id}\n` : `relay off ${id}\n`;
        this.TCPClient.write(cmd);
    }

    readInput(id, callback) {
        const cmd = `gpio read ${id}\n`;
        this.TCPClient.write(cmd);
        this.TCPClient.once("data", (data) => {
            const response = data.trim();
            callback(response === "1");
        });
    }

    close() {
        this.TCPClient.end();
    }
}

//Classe Box logique
class Box {
    constructor(id, carte) {
        this.id = id;
        this.carte = carte;
    }

    openTheDoor() {
        this.carte.writeOutput(1, true);
        console.log("Porte ouverte");
    }

    closeTheDoor() {
        this.carte.writeOutput(1, false);
        console.log("Porte fermée");
    }

    switchOnTheLight() {
        this.carte.writeOutput(2, true);
        console.log("Lumière allumée");
    }

    turnOffTheLight() {
        this.carte.writeOutput(2, false);
        console.log("Lumière éteinte");
    }

    turnOnThePower() {
        this.carte.writeOutput(3, true);
        console.log("Alimentation activée");
    }

    turnOffThePower() {
        this.carte.writeOutput(3, false);
        console.log("Alimentation désactivée");
    }

    getDoorState(callback) {
        this.carte.readInput(1, (state) => {
            console.log("État de la porte :", state ? "OUVERTE" : "FERMÉE");
            callback && callback(state);
        });
    }

    getLightState(callback) {
        this.carte.readInput(2, (state) => {
            console.log("État de la lumière :", state ? "ALLUMÉE" : "ÉTEINTE");
            callback && callback(state);
        });
    }

    getPowerConsumptionState(callback) {
        this.carte.readInput(3, (state) => {
            console.log("État de l’alimentation :", state ? "ACTIVE" : "INACTIVE");
            callback && callback(state);
        });
    }

    close() {
        this.carte.close();
    }

    static loadAllBoxes() {
        return [new Box(1, new CarteETHIO32("192.168.0.100", 23))]; //Remplace IP/port
    }
}

//Lancement du programme

const box = Box.loadAllBoxes()[0];

function showMenu() {
    console.log('\n=== Menu Box ===');
    console.log('1. Ouvrir la porte');
    console.log('2. Fermer la porte');
    console.log('3. Allumer la lumière');
    console.log('4. Éteindre la lumière');
    console.log('5. Activer l’alimentation');
    console.log('6. Désactiver l’alimentation');
    console.log('7. État de la porte');
    console.log('8. État de la lumière');
    console.log('9. État de l’alimentation');
    console.log('0. Quitter');
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
        case '7': box.getDoorState(); break;
        case '8': box.getLightState(); break;
        case '9': box.getPowerConsumptionState(); break;
        case '0':
            rl.close();
            box.close();
            console.log("Déconnexion...");
            return;
        default:
            console.log('Choix invalide');
    }
    setTimeout(showMenu, 300);
}

showMenu();


// Remplace "192.168.0.100" et le port par ceux de ta carte.
// Vérifie dans la doc de ta carte si la commande gpio read X est bien la bonne pour lire un pin.