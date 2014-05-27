#ifndef __SENSOROBJECT_H__
#define	__SENSOROBJECT_H__

#include "MaestroController.h"

class SensorObject {
public:

    SensorObject();
	~SensorObject();

    // void loadConfig(cfg);
    void setController(MaestroController * maestro);
	void setChannel(int channel);

    int getDirection();

private:
	int getPosition();
    int m_channel;
    MaestroController * m_maestro;

};

#endif
