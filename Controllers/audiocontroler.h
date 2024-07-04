#ifndef AUDIOCONTROLER_H
#define AUDIOCONTROLER_H

#include <QObject>

class AudioControler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int volumLevel READ volumLevel WRITE setVolumLevel NOTIFY volumLevelChanged FINAL)
public:
    explicit AudioControler(QObject *parent = nullptr);

    int volumLevel() const;
    Q_INVOKABLE void incrementVolume( const int & val);

public slots:
    void setVolumLevel(int newVolumLevel);

signals:

    void volumLevelChanged();

private:

    int m_volumLevel;
};

#endif // AUDIOCONTROLER_H
