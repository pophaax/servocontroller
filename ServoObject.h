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
    void setChannel(int Channel){mChannel = Channel;};
    void setMin(int Min){mMin = Min;};
    void setMid(int Mid){mMid = Mid;};
    void setMax(int Max){mMax = Max;};
    void setRange(int Range){mRange = Range/2;};
    
    void setSpeed(unsigned short value);
    void setAcceleration(unsigned short value);
    void setPosition(unsigned short value);
    
    int getPosition();

private:
    int mChannel;
    int mMin;
    int mMid;
    int mMax;
    
    int mRange;
    int mSpeed;
    int mAcceleration;
    
    MaestroController * mMaestro;
    
};

#endif	/* SERVOOBJECT_H */

