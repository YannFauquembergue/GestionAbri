const net = require("net");

// Serveur simulé pour CarteES2
const serverES2 = net.createServer((socket) => {
    console.log("Client connecté à ES2");

    socket.on("data", (data) => {
        const [command, id] = data.toString().trim().split(",");
        console.log(`Commande reçue pour ES2: Command=${command}, ID=${id}`);
        if (command === "READ") {
            // Simuler la lecture de l'état
            if (id === "1") {
                // Simuler l'état de la porte (par exemple, ouverte)
                socket.write("1\n");
            } else if (id === "2") {
                // Simuler l'état de la consommation électrique (par exemple, active)
                socket.write("1\n");
            }
        }
    });

    socket.on("end", () => {
        console.log("Client déconnecté de ES2");
    });

    socket.on("error", (err) => {
        console.error("Erreur de socket ES2:", err.message);
    });
});

serverES2.listen(12346, "127.0.0.1", () => {
    console.log("Serveur ES2 en écoute sur 127.0.0.1:12346");
});
