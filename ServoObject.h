/* 
 * File:   ServoObject.h
 * Author: Joakim
 *
 * Created on 20 March 2014, 11:17
 * The main purpose for this class is to implement methods for default servo behavior.
 * 
 */

#ifndef __SERVOOBJECT_H__
#define	__SERVOOBJECT_H__

#include "MaestroController.h"

class ServoObject {
public:

    ServoObject();
	~ServoObject();
    
    // void loadConfig(cfg);
    void setController(MaestroController * maestro);
    
    void setChannel(int channel);
    void setMin(int min);
    void setMax(int max);
    void setRange(int range);
    
    void setSpeed(unsigned short speed);
    void setAcceleration(unsigned short acceleration);
    void setPosition(unsigned short position);
    
    int getPosition();

private:
    int m_channel;
    int m_min;
    int m_max;
    
    int m_range;
    int m_speed;
    int m_acceleration;
    
    MaestroController * m_maestro;
    
};

#endif

