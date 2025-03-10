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

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(obj["host"].toString());
    database.setPort(obj["port"].toInt());
    database.setDatabaseName(obj["database"].toString());
    database.setUserName(obj["user"].toString());
    database.setPassword(obj["password"].toString());

    if (!database.open())
    {
        ui.statusLine->setText("ERROR: " + database.lastError().text());
        return;
    }
    ui.statusLine->setText("Connected");
}
