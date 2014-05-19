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
	int upBitCount = 0, lowBitCount = 0;
	float total = 0;
	int counter = 0;
	bool init = true;
	int timesLeft = 10;
	for (int i = 0; i < 50; i++) {
		if(init) {
			init = false;
			while (getPosition() > 100);
			while (getPosition() < 100);
		}


		while (getPosition() > 100) {
			upBitCount++;
		}

		while (getPosition() < 100) {
			lowBitCount++;
		}

		//std::cout << "lowBits: " << lowBitCount << "\n" << "highBits: " << upBitCount << "\n";
		//std::cout << "percentage: " << (((float)upBitCount) / (lowBitCount+upBitCount)) << "\n";
		if ((lowBitCount+upBitCount) != 0) {
			total += (((float)upBitCount) / (lowBitCount+upBitCount));
			counter++;
		}
	}

	return (int)((total/counter)*360);
}