#include <QObject>
#include <QTimer>

#pragma once
class RFIDReader : public QObject
{
private:
	QTimer timer;

public:
	void onRFIDRead(QString data);

public slots:
	void readData();
};

