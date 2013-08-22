#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("pathfinder");
    QApplication::setOrganizationDomain("drinwa.net");
    QApplication::setOrganizationName("drinwa.net");

    MainWindow w;
    w.show();
    
    return a.exec();
}
