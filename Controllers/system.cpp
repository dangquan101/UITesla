#include "system.h"
#include <QDateTime>

System::System(QObject *parent)
    : QObject{parent}
    , m_carLock(true)
    , m_outDoorTemp(64)
    , m_userName("quan")
{
    m_currentTimeTimer = new QTimer(this);
    m_currentTimeTimer->setInterval(500);
    m_currentTimeTimer->setSingleShot(true);  // Sử dụng singleShot nếu chỉ muốn chạy một lần
    connect(m_currentTimeTimer, &QTimer::timeout, this, &System::currentTimeTimerTimeout);

    currentTimeTimerTimeout();  // Gọi lần đầu để khởi động chu kỳ
}

bool System::carLock() const
{
    return m_carLock;
}

void System::setCarLock(bool newCarLock)
{
    if (m_carLock == newCarLock)
        return;
    m_carLock = newCarLock;
    emit carLockChanged();
}

int System::outDoorTemp() const
{
    return m_outDoorTemp;
}

void System::setOutDoorTemp(int newOutDoorTemp)
{
    if (m_outDoorTemp == newOutDoorTemp)
        return;
    m_outDoorTemp = newOutDoorTemp;
    emit outDoorTempChanged();
}

QString System::userName() const
{
    return m_userName;
}

void System::setUserName(const QString &newUserName)
{
    if (m_userName == newUserName)
        return;
    m_userName = newUserName;
    emit userNameChanged();
}

QString System::currentTime() const
{
    return m_currentTime;
}

void System::setcurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void System::currentTimeTimerTimeout()
{
    QDateTime dateTime = QDateTime::currentDateTime();  // Sử dụng thời gian hiện tại
    QString currentTime = dateTime.toString("hh:mm ap");  // Định dạng thời gian

    setcurrentTime(currentTime);

    m_currentTimeTimer->start();  // Khởi động lại bộ đếm thời gian, nếu bạn muốn tiếp tục cập nhật
}
