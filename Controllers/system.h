#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <QTimer>

class System : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool carLock READ carLock WRITE setCarLock NOTIFY carLockChanged FINAL)
    Q_PROPERTY(int outDoorTemp READ outDoorTemp WRITE setOutDoorTemp NOTIFY outDoorTempChanged FINAL)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged FINAL)
    Q_PROPERTY(QString currentTime READ currentTime WRITE setcurrentTime NOTIFY currentTimeChanged FINAL)
public :
    explicit System(QObject *parent = nullptr);

    bool carLock() const;
     Q_INVOKABLE  void setCarLock(bool newCarLock);

    int outDoorTemp() const;
     Q_INVOKABLE  void setOutDoorTemp(int newOutDoorTemp);

    QString userName() const;
     Q_INVOKABLE  void setUserName(const QString &newUserName);

    QString currentTime() const;
    void setcurrentTime(const QString &newCurrentTime);

public slots:
    void currentTimeTimerTimeout();
signals:
    void carLockChanged();
    void outDoorTempChanged();

    void userNameChanged();

    void currentTimeChanged();

private:
    bool m_carLock;
    int m_outDoorTemp;
    QString m_userName;
    QString m_currentTime;
    QTimer * m_currentTimeTimer;
};

#endif // SYSTEM_H
