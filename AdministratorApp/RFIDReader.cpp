#include "RFIDReader.h"

RFIDReader::RFIDReader(QObject* parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RFIDReader::readData);
    timer->start(2000);
}

RFIDReader::~RFIDReader()
{
    timer->stop();
    delete timer;
}

void RFIDReader::readData()
{
    QString data = "123456789ABC"; // Données temporaires
    emit onRFIDRead(data);
}
