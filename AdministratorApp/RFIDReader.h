#include <QObject>
#include <QTimer>

#include "Include/Modbus/modbus.h"

class RFIDReader : public QObject
{
    Q_OBJECT

public:
    explicit RFIDReader(QString serialPortName, int baudRate = 9600, QObject* parent = nullptr);
    ~RFIDReader();

    bool IsReaderConnected();

signals:
    void onRFIDRead(QString rfid);

private slots:
    void readData();

private:
    QString serialPortName;
    int baudRate;
    modbus_t* ctx;
    bool isConnected;
    QTimer* timer;
};