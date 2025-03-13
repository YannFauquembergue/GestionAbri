#include <QObject>

#pragma once
class User : public QObject
{
public:
	int id;
	QString prenom;
	QString nom;
	QString nickname;
	QString rfid;
	QString password;

	User(QString prenom, QString nom, QString nickname, QString rfid, QString password, int id = -1);
};

