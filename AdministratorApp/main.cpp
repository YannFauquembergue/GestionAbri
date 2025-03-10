#include "AdministratorApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdministratorApp w;
    w.show();
    return a.exec();
}
