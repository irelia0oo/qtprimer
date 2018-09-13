#ifndef MYACTION_H
#define MYACTION_H

#include <QObject>
#include <QWidget>
#include <QWidgetAction>
#include <QLineEdit>
#include <QString>

class QLineEdit;
class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyAction(QObject *parent = 0);
protected:
    QWidget * createWidget(QWidget *parent);
signals:
    void getText(const QString &string);
private slots:
    void sendText();
private:
    QLineEdit *lineEdit;
};

#endif // MYACTION_H
