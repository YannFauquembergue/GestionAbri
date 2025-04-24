#include <QObject>
#include <QTimer>

#include "Include/Modbus/modbus.h"

class RFIDReader : public QObject
{
    Q_OBJECT

private:
    QString ip;
    int port;

    QTimer* timer;
    modbus_t* ctx;
    bool isConnected;

public:
    RFIDReader(QString ip, int port, QObject* parent = nullptr);
    ~RFIDReader();

    bool IsReaderConnected();

public slots:
    void readData();

signals:
    void onRFIDRead(QString data);
};