#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QMenu>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->pushButton1->setText(tr("&nihao"));
    ui->pushButton2->setText(tr("帮助(&H)"));
    ui->pushButton2->setIcon(QIcon("../image/help.png"));
    ui->pushButton3->setText(tr("z&oom"));
    QMenu *menu = new QMenu(this);
    menu->addAction(QIcon("../image/zoom-in.png"),tr("放大"));
    menu->addAction(QIcon("../image/zoom-in.png"),tr("缩小"));
    menu->addAction(QIcon("../image/zoom-in.png"),tr("拉拉达拉"));
    ui->pushButton3->setMenu(menu);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton1_clicked()
{

}

void MyWidget::on_pushButton1_toggled(bool checked)
{
    qDebug()<< tr("按钮是否按下：")<<checked;
}
