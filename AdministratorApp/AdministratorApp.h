#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AdministratorApp.h"
#include "RFIDReader.h"
#include "APIManager.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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

    QList<User*> users;

    void FetchUsers();

public slots:
    void RefreshList();
    void AddUser();
    void  OnUserComboSelect(int i);
};
