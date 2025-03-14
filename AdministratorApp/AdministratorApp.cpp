#include "AdministratorApp.h"

AdministratorApp::AdministratorApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui.logList->addItem("ERREUR: Lecture du fichier config impossible.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject obj = doc.object();
    api = new APIManager(obj["host"].toString(), obj["port"].toInt());
    FetchUsers();
}

AdministratorApp::~AdministratorApp()
{
}

void AdministratorApp::RefreshList()
{
    ui.logList->addItem("Actualisation de la liste des utilisateurs");
    FetchUsers();
}

void AdministratorApp::FetchUsers()
{
    users = api->loadUsers();
    ui.userCombo->clear();
    ui.userCombo->addItem("Nouvel utilisateur");
    for (int i = 0; i < users.size(); i++)
    {
        ui.userCombo->addItem(users[i]->getNickname() + " (" + QString::number(users[i]->getId()) + ")");
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
        ui.logList->addItem("L'utilisateur " + ui.nicknameLineEdit->text() + " a ete ajoute/modifie avec succes !");
        FetchUsers();
    }
    else
    {
        ui.logList->addItem("ERREUR: Echec de l'ajout/modification de l'utilisateur");
    }
}

void AdministratorApp::OnUserComboSelect(int i)
{
    if (users.size() <= 0) { return; }

    if (ui.userCombo->currentIndex() > 0)
    {
        User* user = users[ui.userCombo->currentIndex() - 1];
        ui.nomLineEdit->setText(user->getNom());
        ui.prenomLineEdit->setText(user->getPrenom());
        ui.nicknameLineEdit->setText(user->getNickname());
        ui.rfidLineEdit->setText(user->getRFID());
        ui.passwordLineEdit->setText(user->getPassword());
    }
    else
    {
        ui.nomLineEdit->clear();
        ui.prenomLineEdit->clear();
        ui.nicknameLineEdit->clear();
        ui.rfidLineEdit->clear();
        ui.passwordLineEdit->clear();
    }
}
