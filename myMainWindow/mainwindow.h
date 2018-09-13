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
    ~MainWindow();

private slots:
    void on_actio_New_triggered();

    void on_actionShow_Dock_triggered();



    void on_dockWidget_visibilityChanged(bool visible);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
