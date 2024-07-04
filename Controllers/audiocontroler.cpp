#include "audiocontroler.h"

AudioControler::AudioControler(QObject *parent)
    : QObject{parent}
    , m_volumLevel(1)
{}

int AudioControler::volumLevel() const
{
    return m_volumLevel;
}

void AudioControler::incrementVolume(const int &val)
{
    int newVolum = m_volumLevel + val;

    if(newVolum >= 100)
        newVolum = 100;

    if(newVolum <= 0)
        newVolum = 0;

    setVolumLevel(newVolum);
}

void AudioControler::setVolumLevel(int newVolumLevel)
{
    if (m_volumLevel == newVolumLevel)
        return;
    m_volumLevel = newVolumLevel;
    emit volumLevelChanged();
}
