#include "ServoObject.h"

ServoObject::setController(MaestroController* maestro)
{
    m_maestro = maestro;
}

void ServoObject::setChannel(int channel)
{
    m_channel = Channel;
};

void ServoObject::setMin(int min)
{
    m_min = Min;
};

void ServoObject::setMid(int mid)
{
    m_mid = Mid;
};

void ServoObject::setMax(int max)
{
    m_max = Max;
};

void ServoObject::setRange(int range)
{
    m_range = Range/2;
};
    
void ServoObject::setSpeed(unsigned short speed) {
    m_speed = speed;
    m_maestro->writeCommand(SET_SPEED, m_channel, speed);
}

void ServoObject::setAcceleration(unsigned short acceleration) {
    m_acceleration = acceleration;
    m_maestro->writeCommand(SET_ACCELERATION, m_channel, acceleration);
}

void ServoObject::setPosition(unsigned short position) {

    //double NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin;
    position = (((position - m_range) * (m_max - m_min)) / (-m_range - m_range)) + m_min;
    
    m_maestro->writeCommand(SET_POSITION, m_channel, position);
}

int ServoObject::getPosition() {
    
    m_maestro->writeCommand(GET_POSITION, m_channel, -1);
    return m_maestro->readRespons();
    
}
