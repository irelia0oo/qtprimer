#include "mainwindow.h"
#include <QApplication>
#include <QLabel>//标签
#include <QpushButton>
#include <qDebug>

#include "reader.h"
#include "newspaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}

//QPushButton button("Qiut");
/*
//QObject::connect(&button,&QPushButton::clicked,&QApplication::quit);
//最常用形式：connect(sender,   signal,receiver, slot);
//参数说明： 1 发出信号的对象  2 发出的信号 3 接收信号的对象 4 接收后做的操作
//QObject::connect(&button,&QPushButton::clicked,[](bool){qDebug() << "you clickde me!";});
//button.show();
*/

/*
Newspaper newspaper("Newspaper A");
Reader reader;
QObject::connect(&newspaper,&Newspaper::newpaper,&reader,&Reader::receiveNewspaper);
newspaper.send();
//发送者和接收者都需要是 QObject 的子类（当然，槽函数是全局函数、Lambda 表达式等无需接收者的时候除外）；
//使用 signals 标记信号函数，信号是一个函数声明，返回 void，不需要实现函数代码；
//槽函数是普通的成员函数，作为成员函数，会受到 public、private、protected 的影响；
//使用 emit 在恰当的位置发送信号；
//使用 QObject::connect() 函数连接信号和槽。
*/
