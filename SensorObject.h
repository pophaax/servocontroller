#ifndef __SENSOROBJECT_H__
#define	__SENSOROBJECT_H__

#include "MaestroController.h"

class SensorObject {
public:

    SensorObject();
	~SensorObject();

    // void loadConfig(cfg);
    void setController(Actuator * maestro);
	void setChannel(int channel);

    int getDirection();

private:
	int getPosition();
    int m_channel;
    Actuator * m_maestro;

};

#endif
