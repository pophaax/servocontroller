#include "SensorObject.h"
#include <iostream>

SensorObject::SensorObject() {
 
}

SensorObject::~SensorObject() {

}

void SensorObject::setController(MaestroController* maestro)
{
    m_maestro = maestro;
}

void SensorObject::setChannel(int channel)
{
	m_channel = channel;
}

int SensorObject::getPosition()
{
	m_maestro->writeCommand(GET_POSITION, m_channel, -1);
	return m_maestro->readRespons();
}

int SensorObject::getDirection()
{
	int high = 0, low = 0;
	for (int i = 0; i < 1000; i++) {
		
		if (getPosition() > 100) {
			high++;
		} else {
			low++;
		}
	}
	float percent = ((float)high) / (low+high);
	return (int)(percent*360);
}
