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

#ifndef __MAESTROCONTROLLER_H__
#define	__MAESTROCONTROLLER_H__

#include <iostream>
#include <string>

//enum COMMAND_BYTE {
//    SET_SPEED = 0x87,
//    SET_ACCELERATION = 0x89,
//    SET_POSITION = 0x84,
//    SET_POSITION_HOME = 0xA2,
//    GET_POSITION = 0x90,
//    GET_MOVING_STATE = 0x93,
//    GET_ERROR = 0xA1
//};

const int SET_SPEED =           0x87;
const int SET_ACCELERATION =    0x89;
const int SET_POSITION =        0x84;
const int SET_POSITION_HOME =   0xA2;
const int GET_POSITION =        0x90;
const int GET_MOVING_STATE =    0x93;
const int GET_ERROR =           0xA1;



class MaestroController {
public:
	MaestroController();
	~MaestroController();

	void setPort(std::string portName);
	void writeCommand(unsigned char type, int channel, int value);
	int readRespons();
	int getError();

private:
	int ioDeviceHandle;
	std::string ioDeviceHandlePath;

	void openPort();
	bool isOpenPort();
};

#endif	/* MAESTROCONTROLLER_H */

