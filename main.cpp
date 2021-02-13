#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   //Q_INIT_RESOURCE(basicdrawing); //i don t know wat s this should i add it

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
