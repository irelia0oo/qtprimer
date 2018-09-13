#include <QToolButton>
#include <QLabel>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QDebug>
#include <QStatusBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction * action_Open = editMenu->addAction(QIcon(":/myImage/image/open.png"),tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl + O"));
    ui->mainToolBar->addAction(action_Open);

    QActionGroup * group = new QActionGroup(this);
    QAction  *action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction * action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
   // ui->mainToolBar->addAction(action_L);
   // ui->mainToolBar->addAction(action_R);
   // ui->mainToolBar->addAction(action_C);
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));;
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    QSpinBox *spinbox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinbox);

    ui->statusBar->showMessage(tr("你好啊，欢迎。"),5000);
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.baidu.com");
    ui->statusBar->addPermanentWidget(permanent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actio_New_triggered()
{
    QTextEdit *edit = new QTextEdit(this);//新建文本编辑器
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);//使用MDdArea类的函数创建子窗口，以文本编辑器为中心部件
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_actionShow_Dock_triggered()
{
    if(ui->dockWidget->isVisible())
        ui->dockWidget->close();
    else
        ui->dockWidget->show();
}


void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actionShow_Dock->changed();
}
