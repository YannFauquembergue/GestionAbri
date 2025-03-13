#include "AdministratorApp.h"

AdministratorApp::AdministratorApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    api = new APIManager("192.168.64.151", 8080);
    FetchUsers();
}

AdministratorApp::~AdministratorApp()
{
}

void AdministratorApp::GetUserInfo()
{

}

void AdministratorApp::FetchUsers()
{
    QList<User*> users = api->loadUsers();
    ui.userCombo->clear();
    ui.userCombo->addItem("Nouvel utilisateur");
    for (int i = 0; i < users.size(); i++)
    {
        ui.userCombo->addItem(users[i]->nickname + " (" + QString::number(users[i]->id) + ")");
    }
    ui.logList->addItem(QString("%1 utilisateurs trouves").arg(users.size()));
}

void AdministratorApp::AddUser()
{
    User* user = new User(
        ui.prenomLineEdit->text(),
        ui.nomLineEdit->text(),
        ui.nicknameLineEdit->text(),
        ui.rfidLineEdit->text(),
        ui.passwordLineEdit->text()
    );
    if (api->saveUser(user))
    {
        ui.logList->addItem("L'utilisateur " + ui.nicknameLineEdit->text() + " a ete ajoute avec succes !");
    }
}
