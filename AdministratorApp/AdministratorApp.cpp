#include "AdministratorApp.h"

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

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("192.168.64.151");
    database.setPort(3306);
    database.setDatabaseName("Abri");
    database.setUserName("abriUser");
    database.setPassword("Pewpew020305???!");

    if (!database.open())
    {
        ui.statusLine->setText("ERROR: " + database.lastError().text());
        return;
    }
    ui.statusLine->setText("Connected");
}
