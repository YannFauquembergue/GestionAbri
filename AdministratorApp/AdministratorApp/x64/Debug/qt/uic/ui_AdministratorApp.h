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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
        AdministratorAppClass->resize(464, 624);
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 441, 141));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(130, 30, 161, 41));
        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(10, 80, 421, 20));
        statusLabel->setScaledContents(false);
        statusLabel->setWordWrap(true);
        statusLabel->setOpenExternalLinks(false);
        statusLine = new QLineEdit(groupBox);
        statusLine->setObjectName(QString::fromUtf8("statusLine"));
        statusLine->setGeometry(QRect(10, 100, 421, 31));
        statusLine->setReadOnly(true);
        AdministratorAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 464, 20));
        AdministratorAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdministratorAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdministratorAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdministratorAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdministratorAppClass->setStatusBar(statusBar);

        retranslateUi(AdministratorAppClass);
        QObject::connect(connectButton, SIGNAL(clicked()), AdministratorAppClass, SLOT(ConnectToDatabase()));

        QMetaObject::connectSlotsByName(AdministratorAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorAppClass)
    {
        AdministratorAppClass->setWindowTitle(QCoreApplication::translate("AdministratorAppClass", "AdministratorApp", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdministratorAppClass", "Connexion", nullptr));
        connectButton->setText(QCoreApplication::translate("AdministratorAppClass", "Connexion \303\240 la BDD", nullptr));
        statusLabel->setText(QCoreApplication::translate("AdministratorAppClass", "Statut", nullptr));
        statusLine->setText(QCoreApplication::translate("AdministratorAppClass", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
