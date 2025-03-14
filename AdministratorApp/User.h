#include <QObject>

#pragma once
class User : public QObject
{
private:
	int id;
	QString prenom;
	QString nom;
	QString nickname;
	QString rfid;
	QString password;

public:
	User(QString prenom, QString nom, QString nickname, QString rfid, QString password, int id = -1);
	int getId();
	QString getPrenom();
	QString getNom();
	QString getNickname();
	QString getRFID();
	QString getPassword();
};

