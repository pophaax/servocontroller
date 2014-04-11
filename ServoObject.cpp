#include "ServoObject.h"

ServoObject::ServoObject(MaestroController* Maestro){
    mMaestro = Maestro;
}

void ServoObject::setSpeed(unsigned short Speed) {
    mSpeed = Speed;
    mMaestro->writeCommand(SET_SPEED, mChannel, Speed);
}

void ServoObject::setAcceleration(unsigned short Acceleration) {
    mAcceleration = Acceleration;
    mMaestro->writeCommand(SET_ACCELERATION, mChannel, Acceleration);
}

void ServoObject::setPosition(unsigned short Position) {

    //double NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin;
    Position = (((Position - mRange) * (mMax - mMin)) / (-mRange - mRange)) + mMin;
    
    mMaestro->writeCommand(SET_POSITION, mChannel, Position);
}

int ServoObject::getPosition() {
    
    mMaestro->writeCommand(GET_POSITION, mChannel, -1);
    return mMaestro->readRespons();
    
}
