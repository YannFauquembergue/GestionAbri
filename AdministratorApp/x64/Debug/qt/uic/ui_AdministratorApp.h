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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdministratorAppClass)
    {
        if (AdministratorAppClass->objectName().isEmpty())
            AdministratorAppClass->setObjectName(QString::fromUtf8("AdministratorAppClass"));
        AdministratorAppClass->resize(600, 400);
        menuBar = new QMenuBar(AdministratorAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        AdministratorAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdministratorAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AdministratorAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AdministratorAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AdministratorAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AdministratorAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AdministratorAppClass->setStatusBar(statusBar);

        retranslateUi(AdministratorAppClass);

        QMetaObject::connectSlotsByName(AdministratorAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorAppClass)
    {
        AdministratorAppClass->setWindowTitle(QCoreApplication::translate("AdministratorAppClass", "AdministratorApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorAppClass: public Ui_AdministratorAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORAPP_H
