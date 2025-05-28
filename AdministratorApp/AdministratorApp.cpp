#include "AdministratorApp.h"

AdministratorApp::AdministratorApp(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QFile file("config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Lecture du fichier config pour les informations confidentielles
        AddElementToLogList("ERREUR: Lecture du fichier config impossible.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject obj = doc.object();
    api = new APIManager(obj["host"].toString(), obj["port"].toInt()); // Définition d'une instance pour la gestion de l'API
    rfidReader = new RFIDReader(obj["rfidHost"].toString(), obj["rfidPort"].toInt(), this); // Définition d'une instance pour les lectures de données d'une carte RFID
    /*
    if (rfidReader->IsReaderConnected())
    {
        AddElementToLogList("Lecteur RFID connecte !");
    }
    else
    {
        AddElementToLogList("AVERTISSEMENT: Lecteur RFID non connecte !");
    }
    */
    connect(rfidReader, &RFIDReader::onRFIDRead, this, &AdministratorApp::GetRFIDInfo);

    ListAvailablePorts(); // Affichage des ports USB disponibles
    FetchUsers(); // Affichage des utilisateurs de la BDD
}

AdministratorApp::~AdministratorApp()
{
}

// Fonction slot pour actualiser la liste des utilisateurs
void AdministratorApp::RefreshUserCombo()
{
    ui.logList->addItem("Actualisation de la liste des utilisateurs");
    FetchUsers();
}

// Fonction pour la lecture d'informations RFID, et pour l'ajouter dans la console log RFID
void AdministratorApp::GetRFIDInfo(QString info)
{
    ui.rfidLogList->addItem("RFID recu : " + info);
    ui.rfidLogList->scrollToBottom();
}

// Fonction pour lister les ports disponibles
void AdministratorApp::ListAvailablePorts()
{
    ui.moduleCombo->clear();
    foreach(const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
        ui.moduleCombo->addItem(portInfo.portName());
    }
}

// Fonction pour récupérer les utilisateurs de la BDD et les listers
void AdministratorApp::FetchUsers()
{
    users = api->loadUsers();
    if (api->GetLastAPIError() == "LOAD-USERS")
    {
        AddElementToLogList(QString("Erreur lors de la recuperation des utilisateurs: " + api->GetErrorDetails()));
    }
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

// Fonction pour ajouter un élément dans la console log
void AdministratorApp::AddElementToLogList(QString text)
{
    ui.logList->addItem(text);
    ui.logList->scrollToBottom();
}

// Fonction pour ajouter un utilisateur en fonction des informations inscrites sur l'application
void AdministratorApp::AddUser()
{
    QString prenom = ui.prenomLineEdit->text().trimmed();
    QString nom = ui.nomLineEdit->text().trimmed();
    QString nickname = ui.nicknameLineEdit->text().trimmed();
    QString rfid = ui.rfidLineEdit->text().trimmed();
    QString password = ui.passwordLineEdit->text();

    if (prenom.isEmpty() || nom.isEmpty() || nickname.isEmpty() || rfid.isEmpty() || password.isEmpty()) {
        AddElementToLogList("ERREUR: Tous les champs doivent être remplis.");
        return;
    }

    // Limitations RegEx
    QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\-\s]+$"); // Lettres (accents inclus, majuscules et minuscules), traits d'union et espaces autorisés
    QRegularExpression nicknameRegex("^[A-Za-z0-9_]{3,20}$"); // Lettres (majuscules et minuscules), chiffres et underscores autorisés, et entre 3 et 20 caractères
    QRegularExpression passwordRegex("^.{6,}$"); // Au moins 6 caractères requis
    QRegularExpression rfidRegex("^[A-Za-z0-9]{4,200}$"); // Lettres (majuscules et minuscules) et chiffres autorisés

    if (!nameRegex.match(prenom).hasMatch() || !nameRegex.match(nom).hasMatch() ||
        !nicknameRegex.match(nickname).hasMatch() ||
        !passwordRegex.match(password).hasMatch() ||
        !rfidRegex.match(rfid).hasMatch()) {
        AddElementToLogList("ERREUR: Format de champ invalide.");
        return;
    }

    User* user = new User(
        prenom,
        nom,
        nickname,
        rfid,
        password,
        ui.adminCheckBox->isChecked()
    );

    if (api->saveUser(user))
    {
        AddElementToLogList("L'utilisateur " + nickname + " a ete ajoute/modifie avec succes !");
        FetchUsers(); // Rafraîchir la liste après ajout
    }
    else
    {
        AddElementToLogList("ERREUR: Echec de l'ajout/modification de l'utilisateur");
    }
}

// Fonction slot pour combler les informations utilisateurs en fonction de l'index de l'utilisateur sélectionné
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
        ui.passwordLineEdit->clear();
        ui.adminCheckBox->setChecked(user->getIsAdmin());
    }
    else
    {
        ui.nicknameLineEdit->setEnabled(true);
        ui.nomLineEdit->clear();
        ui.prenomLineEdit->clear();
        ui.nicknameLineEdit->clear();
        ui.rfidLineEdit->clear();
        ui.passwordLineEdit->clear();
        ui.adminCheckBox->setChecked(false);
    }
}

// Fonction slot pour réinitialiser la liste des utilisateurs importés depuis un fichier CSV
void AdministratorApp::ResetFileUserList()
{
    ui.fileUsersList->clearContents();
    ui.fileUsersList->setRowCount(0);
}

// Fonction slot pour ajouter les utilisateurs importés depuis un fichier CSV
void AdministratorApp::AddUsersFromFileList()
{
    int rowCount = ui.fileUsersList->rowCount();
    if (rowCount <= 0) {
        AddElementToLogList("ERREUR: La liste des utilisateurs est vide.");
        return;
    }

    int usersAdded = 0;
    for (int row = 0; row < rowCount; ++row) {
        QString nom = ui.fileUsersList->item(row, 0)->text();
        QString prenom = ui.fileUsersList->item(row, 1)->text();
        QString nickname = ui.fileUsersList->item(row, 2)->text();
        QString password = ui.fileUsersList->item(row, 3)->text();
        QString rfid = ui.fileUsersList->item(row, 4)->text();
        QString isAdminStr = ui.fileUsersList->item(row, 5)->text().toLower();
        QString quotaStr = ui.fileUsersList->item(row, 6)->text();

        bool isAdmin = (isAdminStr == "oui" || isAdminStr == "yes" || isAdminStr == "1");
        int quota = quotaStr.toInt();

        // Limitations RegEx
        QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\-\\s]+$"); // Lettres, traits d'union et espaces autorisés
        QRegularExpression nicknameRegex("^[A-Za-z0-9_]{3,20}$"); // Lettres, chiffres et underscores autorisés, et entre 3 et 20 caractères
        QRegularExpression passwordRegex("^.{6,}$"); // Au moins 6 caractères requis
        QRegularExpression rfidRegex("^[A-Za-z0-9]{4,32}$"); // Lettres et chiffres autorisés, entre 4 et 32 caractères

        if (!nameRegex.match(prenom).hasMatch() || !nameRegex.match(nom).hasMatch() ||
            !nicknameRegex.match(nickname).hasMatch() ||
            !passwordRegex.match(password).hasMatch() ||
            !rfidRegex.match(rfid).hasMatch()) {
            AddElementToLogList("ERREUR: Format de champ invalide.");
            return;
        }

        User* user = new User(prenom, nom, nickname, rfid, password, isAdmin, quota);

        if (api->saveUser(user)) {
            AddElementToLogList("Utilisateur ajoute/mis a jour: " + nickname);
            usersAdded++;
        }
        else {
            AddElementToLogList("ERREUR: Echec de l'ajout/la mise a jour de " + nickname);
        }

        delete user;
    }

    AddElementToLogList(QString::number(usersAdded) + " utilisateur(s) ajoute(s)/mis a jour depuis le fichier.");
    FetchUsers(); // Rafraîchir la liste après ajout
}

// Fonction slot pour charger un fichier CSV
void AdministratorApp::LoadUserFile()
{
    QString filePath = ui.fileTextEdit->toPlainText();
    if (filePath.isEmpty()) {
        AddElementToLogList("ERREUR: Le chemin du fichier est vide.");
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        AddElementToLogList("ERREUR: Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream in(&file);
    QString headerLine = in.readLine();

    ui.fileUsersList->setRowCount(0);

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList values = line.split(',', Qt::SkipEmptyParts);
        if (values.size() < 7) {
            AddElementToLogList("ERREUR: Ligne CSV invalide, données insuffisantes.");
            continue;
        }

        ui.fileUsersList->insertRow(row);
        for (int col = 0; col < 7; ++col) {
            QString value = values[col].trimmed();
            if (col == 5) {
                value = (value == "1") ? "Oui" : "Non";
            }
            QTableWidgetItem* item = new QTableWidgetItem(value);
            ui.fileUsersList->setItem(row, col, item);
        }
        ++row;
    }

    file.close();
    AddElementToLogList(QString::number(row) + " utilisateurs charges depuis le fichier.");
}

// Fonction pour supprimer un utilisateur
void AdministratorApp::DeleteUser()
{
    int index = ui.userCombo->currentIndex();
    if (index <= 0 || users.isEmpty()) {
        AddElementToLogList("Aucun utilisateur selectionne pour la suppression.");
        return;
    }

    User* user = users[index - 1];
    int userId = user->getId();
    QString userName = user->getNickname();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
        "Voulez-vous vraiment supprimer l'utilisateur '" + userName + "' ?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (api->deleteUser(userId)) {
            AddElementToLogList("Utilisateur '" + userName + "' supprime avec succes.");
            FetchUsers();
        }
        else {
            AddElementToLogList("ERREUR: Echec de la suppression de l'utilisateur '" + userName + "': " + api->GetErrorDetails());
        }
    }
    else {
        AddElementToLogList("Suppression annulee.");
    }
}


// Fonction slot pour ouvrir le port sélectionné sur l'application
void AdministratorApp::OpenPort()
{
    if (ui.moduleCombo->currentIndex() >= 0)
    {
        QString portName = ui.moduleCombo->currentText();
        rfidReader = new RFIDReader(portName, 9600); // 9600 est la valeur par défaut dans ta classe
        if (rfidReader->IsReaderConnected())
        {
            AddElementToLogList("Lecteur RFID en marche sur " + portName + " !");
        }
        else
        {
            AddElementToLogList("Échec de la connexion au lecteur RFID.");
        }
    }
}

// Fonction slot pour lire les informations du port ouvert
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
