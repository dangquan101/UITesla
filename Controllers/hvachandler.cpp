#include "hvachandler.h"

HVACHandler::HVACHandler(QObject *parent)
    : QObject{parent}
    , m_targetTemperature(70)
{}

int HVACHandler::targetTemperature() const
{
    return m_targetTemperature;
}

void HVACHandler::incrementTargetTemperature(const int &val)
{
    int newTargetTemp = m_targetTemperature + val;
    settargetTemperature( newTargetTemp );
}

void HVACHandler::settargetTemperature(int newTargetTemperature)
{
    if (m_targetTemperature == newTargetTemperature)
        return;
    m_targetTemperature = newTargetTemperature;
    emit targetTemperatureChanged();
}
