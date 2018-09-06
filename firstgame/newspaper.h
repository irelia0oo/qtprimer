#include <QObject>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name): m_name(name){}
   Newspaper(const QString & name,const QDate &date) : m_name(name){}
    void send(){emit newpaper(m_name);}
signals:
     void newpaper(const QString & m_name) const;
private:
   QString m_name;

};
