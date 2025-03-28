const net = require("net");

// Serveur simulé pour CarteES1
const serverES1 = net.createServer((socket) => {
    console.log("Client connecté à ES1");

    socket.on("data", (data) => {
        const [id, value] = data.toString().trim().split(",");
        console.log(`Commande reçue pour ES1: ID=${id}, Value=${value}`);
        // Simuler l'action (par exemple, allumer une lumière)
        if (id === "1" && value === "1") {
            console.log("Porte ouverte");
        } else if (id === "1" && value === "0") {
            console.log("Porte fermée");
        } else if (id === "2" && value === "1") {
            console.log("Lumière allumée");
        } else if (id === "2" && value === "0") {
            console.log("Lumière éteinte");
        } else if (id === "3" && value === "1") {
            console.log("Alimentation activée");
        } else if (id === "3" && value === "0") {
            console.log("Alimentation désactivée");
        }
    });

    socket.on("end", () => {
        console.log("Client déconnecté de ES1");
    });

    socket.on("error", (err) => {
        console.error("Erreur de socket ES1:", err.message);
    });
});

serverES1.listen(12345, "127.0.0.1", () => {
    console.log("Serveur ES1 en écoute sur 127.0.0.1:12345");
});
