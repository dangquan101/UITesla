#ifndef AUDIOCONTROLER_H
#define AUDIOCONTROLER_H

#include <QObject>

class AudioControler : public QObject
{
    Q_OBJECT
public:
    explicit AudioControler(QObject *parent = nullptr);

signals:
};

#endif // AUDIOCONTROLER_H
