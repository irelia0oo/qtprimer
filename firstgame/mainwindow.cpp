#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>
#include <QObject>
#include <QFileDialog>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    setWindowTitle("Main Window");
   // ui->setupUi(this);//初始化


    //openAction = new QAction(QIcon(":/images/file_open"),tr("&Open..."),this);
    //openAction->setShortcuts(QKeySequence::Open);
    //openAction->setStatusTip(tr("Open en exsit file"));
    //connect(openAction,&QAction::triggered,this,&MainWindow::open);

    //aaa  = new QAction(QIcon(":/images/file_open"),tr("&Open..."),this);
    //aaa->setShortcuts(QKeySequence::Open);
    //saveAction = new QAction(QIcon(":/images/file_save"),tr("&Save..."),this);
    //closeAction = new QAction(QIcon(":/images/doc-close"),tr("&Close..."),this);



    //QMenu *flie = menuBar()->addMenu(tr("&File"));
    //flie->addAction(openAction);
    //
    //QToolBar *toolBar = addToolBar(tr("File"));
    //toolBar->addAction(openAction);

    statusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    if(QMessageBox::Yes == QMessageBox::question(
                this,
                tr("ques"),
                tr("Are you all right?"),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::Yes)
       )
        QMessageBox::information(this,tr("Em........"),tr("I am OK."));
    else
        QMessageBox::information(this, tr("Em...."), tr("bad idear."));

}

void MainWindow::issave()
{
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes"));
    msgBox.setDetailedText(tr("Differences here ..."));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch(ret)
    {
    case QMessageBox::Save:
        qDebug() << "save document!";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug() <<"Close document";
        break;
    }
}
