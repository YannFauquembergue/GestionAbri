#pragma once
#include <QObject>
#include <QTimer>

class RFIDReader : public QObject
{
    Q_OBJECT

private:
    QTimer* timer;

public:
    RFIDReader(QObject* parent = nullptr);
    ~RFIDReader();

public slots:
    void readData();

signals:
    void onRFIDRead(QString data);
};