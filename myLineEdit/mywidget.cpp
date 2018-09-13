#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QValidator>
#include <QCompleter>
#include <QDateTime>
#include <QDateTimeEdit>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QValidator *qvalidator = new QIntValidator(100,999,this);
    ui->lineEdit_3->setValidator(qvalidator);

    QStringList wordlist;
    wordlist<<"QT"<<"QT Creator"<<tr("你好");
    QCompleter *completer = new QCompleter(wordlist,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_4->setCompleter(completer);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setDisplayFormat(tr("yyyy年MM月dd日ddd HH时mm分ss秒"));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdit_2_returnPressed()
{
    ui->lineEdit_3->setFocus();
    qDebug()<<ui->lineEdit_2->text();
    qDebug()<<ui->lineEdit_2->displayText();
}
