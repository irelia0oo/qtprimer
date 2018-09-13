#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    setTabOrder(ui->lineEdit,ui->spinBox);
    setTabOrder(ui->spinBox,ui->pushButton_2);
    setTabOrder(ui->pushButton_2,ui->checkBox);
}

MyWidget::~MyWidget()
{
    delete ui;
}
