#include "mainwindow.h"
#include <QApplication>
#include <QLabel>//标签
#include <QpushButton>
#include <qDebug>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "reader.h"
#include "newspaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*
    Newspaper newspaper("Newspaper A");
    Reader reader;
   //QObject::connect(&newspaper,&Newspaper::newpaper,&reader,&Reader::receiveNewspaper);
    //此处有重载
    //QObject::connect(
    //            &newspaper,
    //            SIGNAL(newpaper(QString,QDate)),
    //            &reader,
    //            SLOT(receiveNewspaper(QString,QDate)));
    QObject::connect(
                &newspaper,
                (void(Newspaper::*)(const QString &,const QDate &))&Newspaper::newpaper,
                &reader,
                &Reader::receiveNewspaper);
    newspaper.send();
    */
    w.show();
    return a.exec();
}
