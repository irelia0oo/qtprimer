#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QLabel *label = new QLabel();
    label->setText("hello");
    label->show();
    return a.exec();
}
