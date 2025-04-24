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

    // Lecture de 2 registres (4 octets)
    uint16_t tab_reg[2] = { 0 };
    int rc = modbus_read_registers(ctx, 0, 2, tab_reg); // Adresse 0, 2 registres

    if (rc == -1) {
        qDebug() << "Erreur de lecture Modbus : " << modbus_strerror(errno);
        modbus_close(ctx);
        isConnected = false;
        return;
    }

    // Conversion des registres en hex string
    QByteArray rfidBytes;
    for (int i = 0; i < rc; ++i) {
        rfidBytes.append((tab_reg[i] >> 8) & 0xFF);
        rfidBytes.append(tab_reg[i] & 0xFF);
    }

    QString rfidData = QString::fromUtf8(rfidBytes.toHex());
    qDebug() << "RFID lu : " << rfidData;
    emit onRFIDRead(rfidData);
}
