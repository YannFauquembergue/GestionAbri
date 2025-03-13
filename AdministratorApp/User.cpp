#include "User.h"

User::User(QString prenom, QString nom, QString nickname, QString rfid, QString password, int id)
{
	this->id = id;
	this->prenom = prenom;
	this->nom = nom;
	this->nickname = nickname;
	this->rfid = rfid;
	this->password = password;
}
