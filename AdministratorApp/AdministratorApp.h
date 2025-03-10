#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AdministratorApp.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class AdministratorApp : public QMainWindow
{
    Q_OBJECT

public:
    AdministratorApp(QWidget* parent = nullptr);
    ~AdministratorApp();

private:
    Ui::AdministratorAppClass ui;
    QSqlDatabase database;

public slots:
    void ConnectToDatabase();

    void AddUser();
};
