/* 
 * File:   MaestroController.h
 * Author: Joakim
 *
 * Created on 20 March 2014, 09:31
 * 
 * The main purpose for this class is to control the maestro USB card that
 * handles communication with the servos. The ServoObject-class is using
 * this class, and with its logic controls the servos.
 * 
 * Uses POSIX functions to send and receive data from a Maestro.
 * NOTE: The Maestro's serial mode must be set to "USB Dual Port".
 */

#ifndef MAESTROCONTROLLER_H
#define	MAESTROCONTROLLER_H

#include <iostream>

//enum COMMAND_BYTE {
//    SET_SPEED = 0x87,
//    SET_ACCELERATION = 0x89,
//    SET_POSITION = 0x84,
//    SET_POSITION_HOME = 0xA2,
//    GET_POSITION = 0x90,
//    GET_MOVING_STATE = 0x93,
//    GET_ERROR = 0xA1
//};

#define SET_SPEED               0x87
#define SET_ACCELERATION        0x89
#define SET_POSITION            0x84
#define SET_POSITION_HOME       0xA2
#define GET_POSITION            0x90
#define GET_MOVING_STATE        0x93
#define GET_ERROR               0xA1

class MaestroController {
public:

    MaestroController(const char * portName) {
        ioDeviceHandle = -1;
        ioDeviceHandlePath = portName;
    }

    void writeCommand(unsigned char type, int channel, int value);
    int readRespons();
    unsigned short getStatus(unsigned char type);

    ~MaestroController();
private:
    int ioDeviceHandle;
    const char *ioDeviceHandlePath;

    void openPort();
    bool isOpenPort();

};

#endif	/* MAESTROCONTROLLER_H */

