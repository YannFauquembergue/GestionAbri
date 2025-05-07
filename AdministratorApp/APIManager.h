#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "User.h"

#pragma once
class APIManager : public QObject
{
private:
	QNetworkAccessManager* accessManager;
	QString ip;
	int port;

	QString lastAPIError;
	QString errorDetails;

	QJsonArray jsonArray;

public:
	APIManager(QString ip, int port, QObject* parent = nullptr);
	User* loadUser(int id);
	QList<User*> loadUsers();
	bool saveUser(User*);
	bool deleteUser(int id);

	QString GetLastAPIError();
	QString GetErrorDetails();
};

