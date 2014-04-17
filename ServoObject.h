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

    ServoObject(MaestroController * maestro);
    
    // void loadConfig(cfg);
    void setChannel(int channel){m_channel = Channel;};
    void setMin(int min){m_min = Min;};
    void setMid(int mid){m_mid = Mid;};
    void setMax(int max){m_max = Max;};
    void setRange(int range){m_range = Range/2;};
    
    void setSpeed(unsigned short speed);
    void setAcceleration(unsigned short acceleration);
    void setPosition(unsigned short position);
    
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

#endif

