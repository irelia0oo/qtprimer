#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QCompleter>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    /*
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);
    layout->setContentsMargins(0,0,50,100);
    setLayout(layout);
    */
    /*
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(ui->fontComboBox,0,0,1,2);
    layout->addWidget(ui->pushButton,0,2,1,1);
    layout->addWidget(ui->textEdit,1,0,1,3);
    setLayout(layout);
    */

    //QStringList wordlist;
    //
    //wordlist<<"@163.com"<<"@qq.com"<<"@139.com";
    //QCompleter *completer = new QCompleter(wordlist,this);
    //completer->setCaseSensitivity(Qt::CaseInsensitive);
    //ui->mailLineEdit->setCompleter(completer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_mailLineEdit_textChanged(const QString &arg1)
{
    qDebug()<<arg1;

    QStringList wordlist;
    wordlist<<arg1 + "@163.com"<< arg1 + "@qq.com"<< arg1 + "@139.com";
    QCompleter *completer = new QCompleter(wordlist,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->mailLineEdit->setCompleter(completer);
}

void MyWidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if(checked)
        ui->pushButton->setText(tr("隐藏可扩展窗口"));
    else
        ui->pushButton->setText(tr("显示可扩展窗口"));
}
