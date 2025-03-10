#include "AdministratorApp.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>


AdministratorApp::AdministratorApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

AdministratorApp::~AdministratorApp()
{
}

void AdministratorApp::ConnectToDatabase()
{
    ui.statusLine->setText("Statut: Tentative de connexion");

    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui.statusLine->setText("ERROR: Lecture du fichier config impossible.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject obj = doc.object();

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(obj["host"].toString());
    database.setPort(obj["port"].toInt());
    database.setDatabaseName(obj["database"].toString());
    database.setUserName(obj["user"].toString());
    database.setPassword(obj["password"].toString());

    if (!database.open())
    {
        ui.stackedWidget->setCurrentIndex(0);
        ui.statusLine->setText("Disconnected");
        ui.logList->addItem("ERREUR: Connexion a la BDD impossible: " + database.lastError().text());
        return;
    }
    ui.stackedWidget->setCurrentIndex(1);
    ui.statusLine->setText("Connected");
    ui.connectButton->setEnabled(false);
    ui.logList->addItem("Connexion a la BDD etablie !");
}

void AdministratorApp::AddUser()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Utilisateur (nom, prenom, nickname, password, rfid) VALUES (:nom, :prenom, :nickname, :password, :rfid)");
    query.bindValue(":nom", ui.nomLineEdit->text());
    query.bindValue(":prenom", ui.prenomLineEdit->text());
    query.bindValue(":nickname", ui.nicknameLineEdit->text());
    query.bindValue(":password", ui.passwordLineEdit->text());
    query.bindValue(":rfid", ui.rfidLineEdit->text());

    if (!query.exec())
    {
        ui.logList->addItem("ERREUR: Ajout de l'utilisateur impossible: " + query.lastError().text());
        return;
    }
    ui.logList->addItem("L'utilisateur " + ui.nicknameLineEdit->text() + " a ete ajoute avec succes !");
}