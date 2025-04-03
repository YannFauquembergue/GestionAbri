#include "AdministratorApp.h"

AdministratorApp::AdministratorApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        AddElementToLogList("ERREUR: Lecture du fichier config impossible.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject obj = doc.object();
    api = new APIManager(obj["host"].toString(), obj["port"].toInt());
    rfidReader = new RFIDReader(this);
    connect(rfidReader, &RFIDReader::onRFIDRead, this, &AdministratorApp::GetRFIDInfo);

    ListAvailablePorts();
    FetchUsers();
}

AdministratorApp::~AdministratorApp()
{
}

void AdministratorApp::RefreshUserCombo()
{
    ui.logList->addItem("Actualisation de la liste des utilisateurs");
    FetchUsers();
}

void AdministratorApp::GetRFIDInfo(QString info)
{
    ui.rfidLogList->addItem("RFID recu : " + info);

}

void AdministratorApp::ListAvailablePorts()
{
    foreach(const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
        ui.moduleCombo->addItem(portInfo.portName());
    }
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
    AddElementToLogList(QString("%1 utilisateurs trouves").arg(users.size()));
    if (users.size() <= 0)
    {
        AddElementToLogList(QString("Le serveur est-il demarre ?").arg(users.size()));
    }
}

void AdministratorApp::AddElementToLogList(QString text)
{
    ui.logList->addItem(text);
    ui.logList->scrollToBottom();
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
        AddElementToLogList("L'utilisateur " + ui.nicknameLineEdit->text() + " a ete ajoute/modifie avec succes !");
        FetchUsers();
    }
    else
    {
        
        AddElementToLogList("ERREUR: Echec de l'ajout/modification de l'utilisateur");
    }
}

void AdministratorApp::OnUserComboSelect(int i)
{
    if (users.size() <= 0) { return; }

    if (ui.userCombo->currentIndex() > 0)
    {
        ui.nicknameLineEdit->setEnabled(false);
        User* user = users[ui.userCombo->currentIndex() - 1];
        ui.nomLineEdit->setText(user->getNom());
        ui.prenomLineEdit->setText(user->getPrenom());
        ui.nicknameLineEdit->setText(user->getNickname());
        ui.rfidLineEdit->setText(user->getRFID());
        ui.passwordLineEdit->setText(user->getPassword());
    }
    else
    {
        ui.nicknameLineEdit->setEnabled(true);
        ui.nomLineEdit->clear();
        ui.prenomLineEdit->clear();
        ui.nicknameLineEdit->clear();
        ui.rfidLineEdit->clear();
        ui.passwordLineEdit->clear();
    }
}

void AdministratorApp::ResetFileUserList()
{
    ui.fileUsersList->clear();
}

void AdministratorApp::AddUsersFromFileList()
{
    if (ui.fileUsersList->rowCount() <= 0)
    {
        AddElementToLogList("ERREUR: La liste des utilisateurs est vide.");
        return;
    }
}

void AdministratorApp::LoadUserFile()
{
    if (ui.fileTextEdit->toPlainText() == NULL)
    {
        AddElementToLogList("ERREUR: Le fichier à charger est vide ou invalide.");
        return;
    }
}

void AdministratorApp::OpenPort()
{
    if (ui.moduleCombo->currentIndex() >= 0)
    {
        port = new QSerialPort(ui.moduleCombo->currentText());
        QObject::connect(port, SIGNAL(readyRead()), this, SLOT(OnSerialPortReadyRead()));
        port->setBaudRate(QSerialPort::Baud9600);
        port->setDataBits(QSerialPort::DataBits::Data8);
        port->setParity(QSerialPort::Parity::NoParity);
        port->setStopBits(QSerialPort::StopBits::OneStop);
        if (port->open(QIODevice::OpenModeFlag::ExistingOnly | QIODevice::OpenModeFlag::ReadWrite))
        {
            AddElementToLogList("Port " + port->portName() + " ouvert !");
        }
        else
        {
            AddElementToLogList("Echec de l'ouverture du port");
        }
    }
}

void AdministratorApp::OnSerialPortReadyRead()
{
    if (port->canReadLine())
    {
        QByteArray data = port->readLine();
        QString rfidTag = QString::fromUtf8(data).trimmed();
        AddElementToLogList("RFID detecte: " + rfidTag);

        emit rfidReader->onRFIDRead(rfidTag);
    }
}
