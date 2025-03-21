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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorAppClass
{
public:
    QWidget *centralWidget;
    QListWidget *logList;
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
    QLabel *userComboLabel;
    QPushButton *refreshComboButton;
    QComboBox *userCombo;
    QLabel *logLabel;
    QGroupBox *moduleBox;
    QLabel *moduleLabel;
    QComboBox *moduleCombo;
    QPushButton *openPortButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
        AdministratorAppClass->resize(730, 438);
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        logList = new QListWidget(centralWidget);
        logList->setObjectName(QString::fromUtf8("logList"));
        logList->setGeometry(QRect(490, 30, 231, 341));
        logList->setAutoScroll(true);
        logList->setMovement(QListView::Static);
        logList->setProperty("isWrapping", QVariant(false));
        logList->setSpacing(1);
        logList->setViewMode(QListView::ListMode);
        logList->setUniformItemSizes(false);
        logList->setWordWrap(true);
        addUserBox = new QGroupBox(centralWidget);
        addUserBox->setObjectName(QString::fromUtf8("addUserBox"));
        addUserBox->setGeometry(QRect(10, 10, 231, 361));
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
        addUserButton->setGeometry(QRect(40, 200, 151, 31));
        rfidLineEdit = new QLineEdit(addUserBox);
        rfidLineEdit->setObjectName(QString::fromUtf8("rfidLineEdit"));
        rfidLineEdit->setGeometry(QRect(10, 170, 101, 21));
        passwordLabel = new QLabel(addUserBox);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(120, 150, 101, 21));
        passwordLabel->setAlignment(Qt::AlignCenter);
        passwordLineEdit = new QLineEdit(addUserBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(120, 170, 101, 21));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        rfidLabel = new QLabel(addUserBox);
        rfidLabel->setObjectName(QString::fromUtf8("rfidLabel"));
        rfidLabel->setGeometry(QRect(10, 150, 101, 21));
        rfidLabel->setAlignment(Qt::AlignCenter);
        userComboLabel = new QLabel(addUserBox);
        userComboLabel->setObjectName(QString::fromUtf8("userComboLabel"));
        userComboLabel->setGeometry(QRect(40, 260, 151, 21));
        userComboLabel->setAlignment(Qt::AlignCenter);
        refreshComboButton = new QPushButton(addUserBox);
        refreshComboButton->setObjectName(QString::fromUtf8("refreshComboButton"));
        refreshComboButton->setGeometry(QRect(40, 320, 151, 31));
        userCombo = new QComboBox(addUserBox);
        userCombo->addItem(QString());
        userCombo->setObjectName(QString::fromUtf8("userCombo"));
        userCombo->setGeometry(QRect(40, 280, 151, 31));
        logLabel = new QLabel(centralWidget);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        logLabel->setGeometry(QRect(496, 10, 221, 21));
        moduleBox = new QGroupBox(centralWidget);
        moduleBox->setObjectName(QString::fromUtf8("moduleBox"));
        moduleBox->setGeometry(QRect(250, 10, 231, 361));
        moduleLabel = new QLabel(moduleBox);
        moduleLabel->setObjectName(QString::fromUtf8("moduleLabel"));
        moduleLabel->setGeometry(QRect(40, 30, 151, 21));
        moduleLabel->setAlignment(Qt::AlignCenter);
        moduleCombo = new QComboBox(moduleBox);
        moduleCombo->setObjectName(QString::fromUtf8("moduleCombo"));
        moduleCombo->setGeometry(QRect(40, 50, 151, 31));
        openPortButton = new QPushButton(moduleBox);
        openPortButton->setObjectName(QString::fromUtf8("openPortButton"));
        openPortButton->setGeometry(QRect(40, 90, 151, 31));
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 20));
        AdministratorAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdministratorAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdministratorAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdministratorAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdministratorAppClass->setStatusBar(statusBar);

        retranslateUi(AdministratorAppClass);
        QObject::connect(addUserButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(AddUser()));
        QObject::connect(userCombo, SIGNAL(currentIndexChanged(int)), AdministratorAppClass, SLOT(OnUserComboSelect(int)));
        QObject::connect(refreshComboButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(RefreshUserList()));
        QObject::connect(openPortButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(OpenPort()));

        QMetaObject::connectSlotsByName(AdministratorAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorAppClass)
    {
        AdministratorAppClass->setWindowTitle(QCoreApplication::translate("AdministratorAppClass", "AdministratorApp", nullptr));
        addUserBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Ajouter/Modifier un utilisateur", nullptr));
        nomLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Nom", nullptr));
        nomLineEdit->setText(QString());
        prenomLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Pr\303\251nom", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Pseudonyme", nullptr));
        addUserButton->setText(QCoreApplication::translate("AdministratorAppClass", "Enregistrer", nullptr));
        rfidLineEdit->setText(QString());
        passwordLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Mot de passe", nullptr));
        passwordLineEdit->setText(QString());
        rfidLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Num\303\251ro RFID", nullptr));
        userComboLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Choix d'utilisateur", nullptr));
        refreshComboButton->setText(QCoreApplication::translate("AdministratorAppClass", "Actualiser", nullptr));
        userCombo->setItemText(0, QCoreApplication::translate("AdministratorAppClass", "Nouvel utilisateur", nullptr));

        logLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Log", nullptr));
        moduleBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Modules USB", nullptr));
        moduleLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Port", nullptr));
        openPortButton->setText(QCoreApplication::translate("AdministratorAppClass", "Ouvrir port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
