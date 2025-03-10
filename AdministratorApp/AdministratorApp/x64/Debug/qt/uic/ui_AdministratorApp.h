/********************************************************************************
** Form generated from reading UI file 'AdministratorApp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORAPP_H
#define UI_ADMINISTRATORAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorAppClass
{
public:
    QWidget *centralWidget;
    QGroupBox *connectBox;
    QPushButton *connectButton;
    QLabel *statusLabel;
    QLineEdit *statusLine;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *notConnectedLabel;
    QWidget *page_2;
    QGroupBox *addUserBox;
    QLabel *nomLabel;
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLabel *prenomLabel;
    QLineEdit *nicknameLineEdit;
    QLabel *nicknameLabel;
    QPushButton *addUserButton;
    QLineEdit *rfidLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *rfidLabel;
    QListWidget *logList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
        AdministratorAppClass->resize(750, 598);
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectBox = new QGroupBox(centralWidget);
        connectBox->setObjectName(QString::fromUtf8("connectBox"));
        connectBox->setGeometry(QRect(10, 10, 491, 141));
        connectButton = new QPushButton(connectBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(170, 30, 161, 41));
        statusLabel = new QLabel(connectBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 80, 421, 20));
        statusLabel->setScaledContents(false);
        statusLabel->setWordWrap(true);
        statusLabel->setOpenExternalLinks(false);
        statusLine = new QLineEdit(connectBox);
        statusLine->setObjectName(QString::fromUtf8("statusLine"));
        statusLine->setGeometry(QRect(10, 100, 471, 31));
        statusLine->setReadOnly(true);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 159, 491, 391));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        notConnectedLabel = new QLabel(page);
        notConnectedLabel->setObjectName(QString::fromUtf8("notConnectedLabel"));
        notConnectedLabel->setGeometry(QRect(16, 12, 461, 351));
        notConnectedLabel->setTextFormat(Qt::AutoText);
        notConnectedLabel->setAlignment(Qt::AlignCenter);
        notConnectedLabel->setWordWrap(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        addUserBox = new QGroupBox(page_2);
        addUserBox->setObjectName(QString::fromUtf8("addUserBox"));
        addUserBox->setGeometry(QRect(0, 10, 231, 361));
        nomLabel = new QLabel(addUserBox);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));
        nomLabel->setGeometry(QRect(30, 30, 61, 21));
        nomLabel->setAlignment(Qt::AlignCenter);
        nomLineEdit = new QLineEdit(addUserBox);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));
        nomLineEdit->setGeometry(QRect(10, 50, 101, 21));
        prenomLineEdit = new QLineEdit(addUserBox);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));
        prenomLineEdit->setGeometry(QRect(120, 50, 101, 21));
        prenomLabel = new QLabel(addUserBox);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));
        prenomLabel->setGeometry(QRect(140, 30, 61, 21));
        prenomLabel->setAlignment(Qt::AlignCenter);
        nicknameLineEdit = new QLineEdit(addUserBox);
        nicknameLineEdit->setObjectName(QString::fromUtf8("nicknameLineEdit"));
        nicknameLineEdit->setGeometry(QRect(60, 100, 111, 21));
        nicknameLabel = new QLabel(addUserBox);
        nicknameLabel->setObjectName(QString::fromUtf8("nicknameLabel"));
        nicknameLabel->setGeometry(QRect(60, 80, 111, 21));
        nicknameLabel->setAlignment(Qt::AlignCenter);
        addUserButton = new QPushButton(addUserBox);
        addUserButton->setObjectName(QString::fromUtf8("addUserButton"));
        addUserButton->setGeometry(QRect(40, 210, 151, 31));
        rfidLineEdit = new QLineEdit(addUserBox);
        rfidLineEdit->setObjectName(QString::fromUtf8("rfidLineEdit"));
        rfidLineEdit->setGeometry(QRect(10, 180, 101, 21));
        passwordLabel = new QLabel(addUserBox);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(120, 160, 101, 21));
        passwordLabel->setAlignment(Qt::AlignCenter);
        passwordLineEdit = new QLineEdit(addUserBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(120, 180, 101, 21));
        rfidLabel = new QLabel(addUserBox);
        rfidLabel->setObjectName(QString::fromUtf8("rfidLabel"));
        rfidLabel->setGeometry(QRect(10, 160, 101, 21));
        rfidLabel->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_2);
        logList = new QListWidget(centralWidget);
        logList->setObjectName(QString::fromUtf8("logList"));
        logList->setGeometry(QRect(510, 20, 231, 511));
        logList->setAutoScroll(true);
        logList->setMovement(QListView::Static);
        logList->setProperty("isWrapping", QVariant(false));
        logList->setSpacing(2);
        logList->setViewMode(QListView::ListMode);
        logList->setUniformItemSizes(false);
        logList->setWordWrap(true);
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 20));
        AdministratorAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdministratorAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdministratorAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdministratorAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdministratorAppClass->setStatusBar(statusBar);

        retranslateUi(AdministratorAppClass);
        QObject::connect(connectButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(ConnectToDatabase()));
        QObject::connect(addUserButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(AddUser()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdministratorAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorAppClass)
    {
        AdministratorAppClass->setWindowTitle(QCoreApplication::translate("AdministratorAppClass", "AdministratorApp", nullptr));
        connectBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Connexion", nullptr));
        connectButton->setText(QCoreApplication::translate("AdministratorAppClass", "Connexion \303\240 la BDD", nullptr));
        statusLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Statut", nullptr));
        statusLine->setText(QCoreApplication::translate("AdministratorAppClass", "Disconnected", nullptr));
        notConnectedLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Vous devez vous connecter \303\240 la base de donn\303\251es pour acc\303\251der aux fonctionnalit\303\251s administrateur.", nullptr));
        addUserBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Ajouter un utilisateur", nullptr));
        nomLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Nom", nullptr));
        nomLineEdit->setText(QString());
        prenomLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Pr\303\251nom", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Pseudonyme", nullptr));
        addUserButton->setText(QCoreApplication::translate("AdministratorAppClass", "Enregistrer", nullptr));
        rfidLineEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Mot de passe", nullptr));
        rfidLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Num\303\251ro RFID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
