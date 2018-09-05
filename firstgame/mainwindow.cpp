#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    setWindowTitle("Main Window");

    openAction = new QAction(QIcon(":/images/doc_open"),tr("&Open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip("Open en exsit file");
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *flie = menuBar()->addMenu(tr("&File"));
    flie->addAction(openAction);

    QToolBar *toolBar = addToolBar(("&File"));
    toolBar->addAction(openAction);

    statusBar();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("hahaha"));
}
