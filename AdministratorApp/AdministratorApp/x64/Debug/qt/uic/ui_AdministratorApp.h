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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
<<<<<<< HEAD
#include <QtWidgets/QStackedWidget>
=======
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorAppClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *connectButton;
    QLabel *statusLabel;
    QLineEdit *statusLine;
<<<<<<< HEAD
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *notConnectedLabel;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QPushButton *pushButton;
=======
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
<<<<<<< HEAD
        AdministratorAppClass->resize(511, 592);
=======
        AdministratorAppClass->resize(464, 624);
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
<<<<<<< HEAD
        groupBox->setGeometry(QRect(10, 10, 491, 141));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(170, 30, 161, 41));
=======
        groupBox->setGeometry(QRect(10, 10, 441, 141));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(130, 30, 161, 41));
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 80, 421, 20));
        statusLabel->setScaledContents(false);
        statusLabel->setWordWrap(true);
        statusLabel->setOpenExternalLinks(false);
        statusLine = new QLineEdit(groupBox);
        statusLine->setObjectName(QString::fromUtf8("statusLine"));
<<<<<<< HEAD
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
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 231, 361));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 61, 21));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 101, 21));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 50, 101, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 30, 61, 21));
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 100, 111, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 80, 111, 21));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 130, 151, 31));
        stackedWidget->addWidget(page_2);
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 511, 20));
=======
        statusLine->setGeometry(QRect(10, 100, 421, 31));
        statusLine->setReadOnly(true);
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 464, 20));
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
        AdministratorAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdministratorAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdministratorAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdministratorAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdministratorAppClass->setStatusBar(statusBar);

        retranslateUi(AdministratorAppClass);
        QObject::connect(connectButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(ConnectToDatabase()));

<<<<<<< HEAD
        stackedWidget->setCurrentIndex(1);


=======
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
        QMetaObject::connectSlotsByName(AdministratorAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorAppClass)
    {
        AdministratorAppClass->setWindowTitle(QCoreApplication::translate("AdministratorAppClass", "AdministratorApp", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Connexion", nullptr));
        connectButton->setText(QCoreApplication::translate("AdministratorAppClass", "Connexion \303\240 la BDD", nullptr));
        statusLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Statut", nullptr));
        statusLine->setText(QCoreApplication::translate("AdministratorAppClass", "Disconnected", nullptr));
<<<<<<< HEAD
        notConnectedLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Vous devez vous connecter \303\240 la base de donn\303\251es pour acc\303\251der aux fonctionnalit\303\251s administrateur.", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AdministratorAppClass", "Ajouter un utilisateur", nullptr));
        label->setText(QCoreApplication::translate("AdministratorAppClass", "Nom", nullptr));
        lineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("AdministratorAppClass", "Pr\303\251nom", nullptr));
        label_3->setText(QCoreApplication::translate("AdministratorAppClass", "Pseudonyme", nullptr));
        pushButton->setText(QCoreApplication::translate("AdministratorAppClass", "Enregistrer", nullptr));
=======
>>>>>>> b7b0282154c8f16d8f05aa5a19d8edb3c05fdc63
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
