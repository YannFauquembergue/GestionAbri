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
    QString data = ""; // Données temporaires
    if (data != NULL) {
        emit onRFIDRead(data);
    }
}
