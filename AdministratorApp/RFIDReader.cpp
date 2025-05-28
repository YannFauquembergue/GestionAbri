#include "RFIDReader.h"
#include <QDebug>

RFIDReader::RFIDReader(QString serialPortName, int baudRate, QObject* parent)
    : QObject(parent),
    serialPortName(serialPortName),
    baudRate(baudRate),
    ctx(nullptr),
    isConnected(false),
    timer(nullptr)
{
    qDebug() << "[INIT] Initialisation du RFIDReader sur port" << serialPortName;

    ctx = modbus_new_rtu(serialPortName.toStdString().c_str(), baudRate, 'N', 8, 1);
    if (!ctx) {
        qDebug() << "[ERREUR] Échec de création du contexte Modbus RTU.";
        return;
    }

    modbus_set_slave(ctx, 1);
    if (modbus_connect(ctx) == -1) {
        qDebug() << "[ERREUR] Connexion Modbus échouée :" << modbus_strerror(errno);
        modbus_free(ctx);
        ctx = nullptr;
        return;
    }

    isConnected = true;
    qDebug() << "[OK] Connexion Modbus RTU réussie au lecteur RFID sur" << serialPortName;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RFIDReader::readData);
    timer->start(2000);
}

RFIDReader::~RFIDReader()
{
    qDebug() << "[DESTRUCTEUR] Fermeture du lecteur RFID...";
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }

    if (ctx) {
        modbus_close(ctx);
        modbus_free(ctx);
        ctx = nullptr;
    }

    isConnected = false;
}

bool RFIDReader::IsReaderConnected()
{
    return isConnected;
}

void RFIDReader::readData()
{
    if (!isConnected || !ctx) return;

    qDebug() << "[READ] Lecture en cours...";

    uint16_t isNewTag = 0;
    int rc = modbus_read_registers(ctx, 1000, 1, &isNewTag);
    if (rc == -1) {
        qDebug() << "[ERREUR] Lecture registre 1000 (IsNewTag) :" << modbus_strerror(errno);
        modbus_close(ctx);
        modbus_free(ctx);
        ctx = nullptr;
        isConnected = false;
        return;
    }

    if (isNewTag != 1) return;

    uint16_t uidLength = 0;
    rc = modbus_read_registers(ctx, 1001, 1, &uidLength);
    if (rc == -1 || uidLength == 0 || uidLength > 20) {
        qDebug() << "[ERREUR] UID invalide ou lecture échouée :" << modbus_strerror(errno);
        return;
    }

    int numRegisters = (uidLength + 1) / 2;
    uint16_t uidData[10] = { 0 };

    rc = modbus_read_registers(ctx, 1002, numRegisters, uidData);
    if (rc == -1) {
        qDebug() << "[ERREUR] Lecture UID :" << modbus_strerror(errno);
        return;
    }

    QByteArray rfidBytes;
    for (int i = 0; i < numRegisters; ++i) {
        rfidBytes.append((uidData[i] >> 8) & 0xFF);
        rfidBytes.append(uidData[i] & 0xFF);
    }

    QString rfidData = QString::fromUtf8(rfidBytes.left(uidLength).toHex().toUpper());
    qDebug() << "[TAG] RFID détecté :" << rfidData;

    emit onRFIDRead(rfidData);

    // Réinitialisation
    uint16_t resetValue = 0;
    rc = modbus_write_register(ctx, 1000, resetValue);
    if (rc == -1) {
        qDebug() << "[ERREUR] Réinitialisation IsNewTag :" << modbus_strerror(errno);
    }
}
