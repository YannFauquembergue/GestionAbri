#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AdministratorApp.h"
#include "RFIDReader.h"
#include "APIManager.h"

#include <QRegularExpressionValidator>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QMessageBox>

#include <QDebug>

class AdministratorApp : public QMainWindow
{
    Q_OBJECT

public:
    AdministratorApp(QWidget* parent = nullptr);
    ~AdministratorApp();

private:
    Ui::AdministratorAppClass ui;
    RFIDReader * rfidReader;
    APIManager* api;

    QSerialPort* port;
    QList<User*> users;

    void GetRFIDInfo(QString info);

    void ListAvailablePorts();
    void FetchUsers();

    void AddElementToLogList(QString text);

public slots:
    void RefreshUserCombo();
    void AddUser();
    void  OnUserComboSelect(int i);

    void ResetFileUserList();
    void AddUsersFromFileList();
    void LoadUserFile();

    void DeleteUser();

    void OpenPort();

    void OnSerialPortReadyRead();
};
