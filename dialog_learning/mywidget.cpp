#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>
//#include <QWizard>

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
    QString fileName = QFileDialog::getOpenFileName(this,tr("文件对话框"),".","*.txt *.h *.cpp");
    qDebug()<<"fileName:"<<fileName;


    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),".", "*.*");
    qDebug()<<"fileNames:"<<fileNames;
}

void MyWidget::on_pushButton_2_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
        ui->pushButton_2->setFont(font);
    else
        qDebug() <<tr("没有选择字体");
}

void MyWidget::on_pushButton_5_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this,tr("请输入文本内容"),tr("请输入用户名"),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)
        qDebug()<<"strinh:"<<string;

    int value1 = QInputDialog::getInt(this,tr("请输入整数"),tr("-500到500之间"),100,-500,500,10,&ok);
    if(ok)
        qDebug()<<"value1:"<<value1;

    double value2 = QInputDialog::getDouble(this,tr("请输入浮点数"),tr("-100到100之间"),0.00,-100,100,2,&ok);
    if(ok)
        qDebug()<<"value2:"<<value2;

    QStringList items;
    items<<tr("a")<<tr("b")<<tr("啊哈哈");
    QString item = QInputDialog::getItem(this,tr("输入条目对话框"),tr("请选择一个条目"),items,0,true,&ok);
    if(ok)
        qDebug()<<"item:"<<item;
}

void MyWidget::on_pushButton_3_clicked()
{
    int ret1 = QMessageBox::question(this,tr("问题对话框"),
                                     tr("你交接QT么"),QMessageBox::Yes,QMessageBox::No);
    if(ret1 == QMessageBox::Yes )
        qDebug()<<tr("问题");

    int ret2 = QMessageBox::information(this,tr("提示对话框"),
                                        tr("这事QT书籍"),QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok)
        qDebug()<<tr("提示！");

    int ret3 = QMessageBox::warning(this,tr("警告对话框"),
                                    tr("不能提前结束"),QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort)
        qDebug()<<tr("警告");

    int ret4 = QMessageBox::critical(this,tr("严重错误对话框"),
                                     tr("发现一个严重错误，选择要关闭所有文件。"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll)
        qDebug()<<tr("错误");

    QMessageBox::about(this,tr("关于对话框"),
                       tr("yefeilinux.com致力于QT开关和普及工作"));
}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,50000,this);
    dialog.setWindowTitle(tr("进度对话框"));//设置标题
    dialog.setWindowModality(Qt::WindowModal);//设置对话框为模态
    dialog.show();
    for(int i = 0; i < 50000;i++)//演示文件复制进度
    {
        dialog.setValue(i);//设置当前进度条
        QCoreApplication::processEvents();//避免界面冻结
        if(dialog.wasCanceled())
            break;//按下取消按钮 中断
    }
    dialog.setValue(50000);
    qDebug()<<tr("复制结束");
}

void MyWidget::on_pushButton_9_clicked()
{
    QErrorMessage *dialog = new QErrorMessage(this);
    dialog->setWindowTitle("错误信息对话框");
    dialog->showMessage(tr("具体错误信息是什么"));
}

QWizardPage * MyWidget::createpage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}
QWizardPage * MyWidget::createpage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}
QWizardPage * MyWidget::createpage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(this->createpage1());
    wizard.addPage(this->createpage2());
    wizard.addPage(this->createpage3());
    wizard.exec();
}
