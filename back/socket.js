const net = require("net");

const HOST = "192.168.64.151"; 
const PORT = 8080; 

const client = new net.Socket();

client.connect(PORT, HOST, () => {
    console.log(`Connecté à ${HOST}:${PORT}`);
    const message = "Connecté";
});

client.on("data", (data) => {
    console.log("Réponse du serveur :", data.toString());
    client.destroy(); 
});

client.on("close", () => {
    console.log("Connexion fermée");
});

client.on("error", (err) => {
    console.error("Erreur :", err.message);
});
