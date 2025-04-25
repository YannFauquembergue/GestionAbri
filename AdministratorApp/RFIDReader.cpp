#include "RFIDReader.h"
#include <QDebug>

RFIDReader::RFIDReader(QString ip, int port, QObject* parent) : QObject(parent), ip(ip), port(port), ctx(nullptr), isConnected(false)
{
    ctx = modbus_new_tcp(ip.toStdString().c_str(), port);
    if (ctx && modbus_connect(ctx) != -1) {
        isConnected = true;
        qDebug() << "Connexion Modbus TCP réussie au lecteur RFID.";
    }
    else {
        qDebug() << "Échec de la connexion Modbus TCP : " << modbus_strerror(errno);
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RFIDReader::readData);
    timer->start(2000); // Lecture toutes les 2 secondes
}

RFIDReader::~RFIDReader()
{
    timer->stop();
    delete timer;

    if (ctx) {
        modbus_close(ctx);
        modbus_free(ctx);
        ctx = nullptr;
        isConnected = false;
    }
}

bool RFIDReader::IsReaderConnected()
{
    return isConnected;
}

void RFIDReader::readData()
{
    if (!isConnected || ctx == nullptr)
        return;

    uint16_t isNewTag = 0;
    // Lire le registre IsNewTag (adresse 1000)
    int rc = modbus_read_registers(ctx, 1000, 1, &isNewTag);
    if (rc == -1) {
        qDebug() << "Erreur de lecture IsNewTag : " << modbus_strerror(errno);
        modbus_close(ctx);
        isConnected = false;
        return;
    }

    if (isNewTag == 1) {
        uint16_t uidLength = 0;
        // Lire la longueur de l'UID (adresse 1001)
        rc = modbus_read_registers(ctx, 1001, 1, &uidLength);
        if (rc == -1) {
            qDebug() << "Erreur de lecture UID Length : " << modbus_strerror(errno);
            return;
        }

        // Calculer le nombre de registres à lire pour l'UID
        int numRegisters = (uidLength + 1) / 2; // Chaque registre contient 2 octets
        uint16_t uidData[10] = { 0 }; // Assure une taille suffisante

        // Lire l'UID
        rc = modbus_read_registers(ctx, 1002, numRegisters, uidData);
        if (rc == -1) {
            qDebug() << "Erreur de lecture UID : " << modbus_strerror(errno);
            return;
        }

        // Convertir les données UID en hexa
        QByteArray rfidBytes;
        for (int i = 0; i < numRegisters; ++i) {
            rfidBytes.append((uidData[i] >> 8) & 0xFF);
            rfidBytes.append(uidData[i] & 0xFF);
        }

        QString rfidData = QString::fromUtf8(rfidBytes.left(uidLength).toHex().toUpper());
        qDebug() << "RFID lu : " << rfidData;
        emit onRFIDRead(rfidData);

        // Réinitialiser le registre IsNewTag à 0
        uint16_t resetValue = 0;
        rc = modbus_write_register(ctx, 1000, resetValue);
        if (rc == -1) {
            qDebug() << "Erreur de réinitialisation IsNewTag : " << modbus_strerror(errno);
        }
    }
}
