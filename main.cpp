#include "mainwindow.h"
#include <QApplication>




#include "nobordermain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


    NoBorderMain n;

    n.show();

    return a.exec();
}
