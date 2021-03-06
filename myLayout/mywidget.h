#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_mailLineEdit_textChanged(const QString &arg1);

    void on_pushButton_toggled(bool checked);

private:
    Ui::MyWidget *ui;
    struct kuozhan
    {
        double minx;
        double miny;
        double maxx;
        double maxy;
    };
};

#endif // MYWIDGET_H
