#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void issave();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void open();
    QAction *openAction;
};

#endif // MAINWINDOW_H
