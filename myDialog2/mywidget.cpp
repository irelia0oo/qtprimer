#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>

#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()//修改颜色
{
    //方法一：
    //QColorDialog dialog(Qt::red,this);//创建对象
    //dialog.setOption(QColorDialog::ShowAlphaChannel);//显示alpha对象
    //dialog.exec();//以模态方式运行对话框
    //QColor color = dialog.currentColor();//获取当前有颜色
    //qDebug()<<"color:"<<color;//输出当前颜色

    //方法二：
    QColor color = QColorDialog::getColor(Qt::blue,this,tr("选择一个靓丽的颜色"),QColorDialog::ShowAlphaChannel);
    qDebug()<<"color:"<<color;
}

void MyWidget::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("文件对话框"),".","*.txt;;*.h;;*.cpp");
    qDebug()<<"fileName:"<<fileName;


    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),".", "*.*");
    qDebug()<<"fileNames:"<<fileNames;
}
