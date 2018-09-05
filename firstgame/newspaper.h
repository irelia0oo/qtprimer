#include <QObject>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name): m_name(name){}
    void send(){emit newpaper(m_name);}
signals:
     void newpaper(const QString & m_name);
private:
   QString m_name;

};
