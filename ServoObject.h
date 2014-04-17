/* 
 * File:   ServoObject.h
 * Author: Joakim
 *
 * Created on 20 March 2014, 11:17
 * The main purpose for this class is to implement methods for default servo behavior.
 * 
 */

#ifndef SERVOOBJECT_H
#define	SERVOOBJECT_H

#include "MaestroController.h"

class ServoObject {
public:

    ServoObject(MaestroController * Maestro);
    
    // void loadConfig(cfg);
    void setChannel(int Channel){m_channel = Channel;};
    void setMin(int Min){m_min = Min;};
    void setMid(int Mid){m_mid = Mid;};
    void setMax(int Max){m_max = Max;};
    void setRange(int Range){m_range = Range/2;};
    
    void setSpeed(unsigned short value);
    void setAcceleration(unsigned short value);
    void setPosition(unsigned short value);
    
    int getPosition();

private:
    int m_channel;
    int m_min;
    int m_mid;
    int m_max;
    
    int m_range;
    int m_speed;
    int m_acceleration;
    
    MaestroController * m_maestro;
    
};

#endif	/* SERVOOBJECT_H */

