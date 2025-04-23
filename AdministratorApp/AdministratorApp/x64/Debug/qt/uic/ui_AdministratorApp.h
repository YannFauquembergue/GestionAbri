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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QGroupBox *loadUsersBox;
    QPushButton *loadFileButton;
    QTableWidget *fileUsersList;
    QTextEdit *fileTextEdit;
    QPushButton *saveFileUsersButton;
    QPushButton *resetFileListButton;
    QLabel *label;
    QListWidget *rfidLogList;
    QLabel *rfidLogLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
        AdministratorAppClass->resize(789, 617);
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        logList = new QListWidget(centralWidget);
        logList->setObjectName(QString::fromUtf8("logList"));
        logList->setGeometry(QRect(10, 370, 381, 181));
        logList->setAutoScroll(true);
        logList->setMovement(QListView::Static);
        logList->setProperty("isWrapping", QVariant(false));
        logList->setSpacing(1);
        logList->setViewMode(QListView::ListMode);
        logList->setUniformItemSizes(false);
        logList->setWordWrap(true);
        addUserBox = new QGroupBox(centralWidget);
        addUserBox->setObjectName(QString::fromUtf8("addUserBox"));
        addUserBox->setGeometry(QRect(10, 10, 231, 341));
        nomLabel = new QLabel(addUserBox);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));
        nomLabel->setGeometry(QRect(30, 150, 61, 21));
        nomLabel->setAlignment(Qt::AlignCenter);
        nomLineEdit = new QLineEdit(addUserBox);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));
        nomLineEdit->setGeometry(QRect(10, 170, 101, 21));
        prenomLineEdit = new QLineEdit(addUserBox);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));
        prenomLineEdit->setGeometry(QRect(120, 170, 101, 21));
        prenomLabel = new QLabel(addUserBox);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));
        prenomLabel->setGeometry(QRect(140, 150, 61, 21));
        prenomLabel->setAlignment(Qt::AlignCenter);
        nicknameLineEdit = new QLineEdit(addUserBox);
        nicknameLineEdit->setObjectName(QString::fromUtf8("nicknameLineEdit"));
        nicknameLineEdit->setGeometry(QRect(60, 210, 111, 21));
        nicknameLabel = new QLabel(addUserBox);
        nicknameLabel->setObjectName(QString::fromUtf8("nicknameLabel"));
        nicknameLabel->setGeometry(QRect(60, 190, 111, 21));
        nicknameLabel->setAlignment(Qt::AlignCenter);
        addUserButton = new QPushButton(addUserBox);
        addUserButton->setObjectName(QString::fromUtf8("addUserButton"));
        addUserButton->setGeometry(QRect(40, 300, 151, 31));
        rfidLineEdit = new QLineEdit(addUserBox);
        rfidLineEdit->setObjectName(QString::fromUtf8("rfidLineEdit"));
        rfidLineEdit->setGeometry(QRect(10, 270, 101, 21));
        passwordLabel = new QLabel(addUserBox);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(120, 250, 101, 21));
        passwordLabel->setAlignment(Qt::AlignCenter);
        passwordLineEdit = new QLineEdit(addUserBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(120, 270, 101, 21));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        rfidLabel = new QLabel(addUserBox);
        rfidLabel->setObjectName(QString::fromUtf8("rfidLabel"));
        rfidLabel->setGeometry(QRect(10, 250, 101, 21));
        rfidLabel->setAlignment(Qt::AlignCenter);
        userComboLabel = new QLabel(addUserBox);
        userComboLabel->setObjectName(QString::fromUtf8("userComboLabel"));
        userComboLabel->setGeometry(QRect(40, 30, 151, 21));
        userComboLabel->setAlignment(Qt::AlignCenter);
        refreshComboButton = new QPushButton(addUserBox);
        refreshComboButton->setObjectName(QString::fromUtf8("refreshComboButton"));
        refreshComboButton->setGeometry(QRect(60, 90, 111, 21));
        userCombo = new QComboBox(addUserBox);
        userCombo->addItem(QString());
        userCombo->setObjectName(QString::fromUtf8("userCombo"));
        userCombo->setGeometry(QRect(40, 50, 151, 31));
        logLabel = new QLabel(centralWidget);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        logLabel->setGeometry(QRect(10, 350, 221, 21));
        moduleBox = new QGroupBox(centralWidget);
        moduleBox->setObjectName(QString::fromUtf8("moduleBox"));
        moduleBox->setGeometry(QRect(610, 10, 171, 341));
        moduleLabel = new QLabel(moduleBox);
        moduleLabel->setObjectName(QString::fromUtf8("moduleLabel"));
        moduleLabel->setGeometry(QRect(10, 30, 151, 21));
        moduleLabel->setAlignment(Qt::AlignCenter);
        moduleCombo = new QComboBox(moduleBox);
        moduleCombo->setObjectName(QString::fromUtf8("moduleCombo"));
        moduleCombo->setGeometry(QRect(10, 50, 151, 31));
        openPortButton = new QPushButton(moduleBox);
        openPortButton->setObjectName(QString::fromUtf8("openPortButton"));
        openPortButton->setGeometry(QRect(30, 90, 111, 21));
        loadUsersBox = new QGroupBox(centralWidget);
        loadUsersBox->setObjectName(QString::fromUtf8("loadUsersBox"));
        loadUsersBox->setGeometry(QRect(250, 10, 351, 341));
        loadFileButton = new QPushButton(loadUsersBox);
        loadFileButton->setObjectName(QString::fromUtf8("loadFileButton"));
        loadFileButton->setGeometry(QRect(120, 90, 111, 21));
        fileUsersList = new QTableWidget(loadUsersBox);
        if (fileUsersList->columnCount() < 7)
            fileUsersList->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        fileUsersList->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        fileUsersList->setObjectName(QString::fromUtf8("fileUsersList"));
        fileUsersList->setGeometry(QRect(10, 130, 331, 171));
        fileUsersList->horizontalHeader()->setDefaultSectionSize(100);
        fileTextEdit = new QTextEdit(loadUsersBox);
        fileTextEdit->setObjectName(QString::fromUtf8("fileTextEdit"));
        fileTextEdit->setGeometry(QRect(50, 50, 261, 31));
        saveFileUsersButton = new QPushButton(loadUsersBox);
        saveFileUsersButton->setObjectName(QString::fromUtf8("saveFileUsersButton"));
        saveFileUsersButton->setGeometry(QRect(50, 310, 121, 21));
        resetFileListButton = new QPushButton(loadUsersBox);
        resetFileListButton->setObjectName(QString::fromUtf8("resetFileListButton"));
        resetFileListButton->setGeometry(QRect(180, 310, 121, 21));
        label = new QLabel(loadUsersBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 261, 21));
        rfidLogList = new QListWidget(centralWidget);
        rfidLogList->setObjectName(QString::fromUtf8("rfidLogList"));
        rfidLogList->setGeometry(QRect(410, 370, 371, 181));
        rfidLogList->setAutoScroll(true);
        rfidLogList->setMovement(QListView::Static);
        rfidLogList->setProperty("isWrapping", QVariant(false));
        rfidLogList->setSpacing(1);
        rfidLogList->setViewMode(QListView::ListMode);
        rfidLogList->setUniformItemSizes(false);
        rfidLogList->setWordWrap(true);
        rfidLogLabel = new QLabel(centralWidget);
        rfidLogLabel->setObjectName(QString::fromUtf8("rfidLogLabel"));
        rfidLogLabel->setGeometry(QRect(410, 350, 221, 21));
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 20));
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
        QObject::connect(refreshComboButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(RefreshUserCombo()));
        QObject::connect(openPortButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(OpenPort()));
        QObject::connect(loadFileButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(LoadUserFile()));

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
        refreshComboButton->setText(QCoreApplication::translate("AdministratorAppClass", "Actualiser liste", nullptr));
        userCombo->setItemText(0, QCoreApplication::translate("AdministratorAppClass", "Nouvel utilisateur", nullptr));

        logLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Log", nullptr));
        moduleBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Module RFID", nullptr));
        moduleLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Port", nullptr));
        openPortButton->setText(QCoreApplication::translate("AdministratorAppClass", "Ouvrir port", nullptr));
        loadUsersBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Charger des utilisateurs", nullptr));
        loadFileButton->setText(QCoreApplication::translate("AdministratorAppClass", "Charger fichier", nullptr));
        QTableWidgetItem *___qtablewidgetitem = fileUsersList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdministratorAppClass", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = fileUsersList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdministratorAppClass", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = fileUsersList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdministratorAppClass", "Pseudonyme", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = fileUsersList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdministratorAppClass", "Mot de passe", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = fileUsersList->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdministratorAppClass", "Identifiant RFID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = fileUsersList->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AdministratorAppClass", "Admin ?", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = fileUsersList->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AdministratorAppClass", "Quota", nullptr));
        saveFileUsersButton->setText(QCoreApplication::translate("AdministratorAppClass", "Enregistrer utilisateurs", nullptr));
        resetFileListButton->setText(QCoreApplication::translate("AdministratorAppClass", "R\303\251initialiser liste", nullptr));
        label->setText(QCoreApplication::translate("AdministratorAppClass", "Fichier CSV \303\240 charger", nullptr));
        rfidLogLabel->setText(QCoreApplication::translate("AdministratorAppClass", "RFID log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
