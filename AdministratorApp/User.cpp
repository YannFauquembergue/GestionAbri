#include "User.h"

User::User(QString prenom, QString nom, QString nickname, QString rfid, QString password, bool isAdmin, int quota, int id)
{
	this->id = id;
	this->prenom = prenom;
	this->nom = nom;
	this->nickname = nickname;
	this->rfid = rfid;
	this->password = password;
	this->isAdmin = isAdmin;
	this->quota = quota;
}

int User::getId()
{
	return id;
}

QString User::getPrenom()
{
	return prenom;
}

QString User::getNom()
{
	return nom;
}

QString User::getNickname()
{
	return nickname;
}

QString User::getRFID()
{
	return rfid;
}

QString User::getPassword()
{
	return password;
}

bool User::getIsAdmin()
{
	return isAdmin;
}

int User::getQuota()
{
	return quota;
}
