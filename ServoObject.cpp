#include "ServoObject.h"
#include <iostream>

ServoObject::ServoObject() {

}

ServoObject::~ServoObject() {
	
}

void ServoObject::setController(MaestroController* maestro)
{
    m_maestro = maestro;
}

void ServoObject::setChannel(int channel)
{
    m_channel = channel;
}

void ServoObject::setMin(int min)
{
    m_min = min;
}

void ServoObject::setMax(int max)
{
    m_max = max;
}
    
void ServoObject::setSpeed(unsigned short speed) {
    m_speed = speed;
    m_maestro->writeCommand(SET_SPEED, m_channel, speed);
}

void ServoObject::setAcceleration(unsigned short acceleration) {
    m_acceleration = acceleration;
    m_maestro->writeCommand(SET_ACCELERATION, m_channel, acceleration);
}

void ServoObject::setPosition(unsigned short percentage) {

//    if(percentage > 100) {
//        percentage = 100;
//    } else if(percentage < 0) {
//        percentage = 0;
//    }
     
//    unsigned short position = ((percentage * 0.01) * (m_max - m_min)) + m_min;

    m_maestro->writeCommand(SET_POSITION, m_channel, percentage);

}

int ServoObject::getPosition() {
    m_maestro->writeCommand(GET_POSITION, m_channel, -1);
	return m_maestro->readRespons();
    
}
