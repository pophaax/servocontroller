#include "MaestroController.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>



MaestroController::MaestroController() {
	ioDeviceHandle = -1;
}

void MaestroController::setPort(const char * portName)
{
    ioDeviceHandlePath = portName;
}
    
void MaestroController::writeCommand(unsigned char type, int channel = -1, int value = -1)
{
    unsigned char command[] = {type, channel, (value & 0x7F), ((value >> 7) & 0x7F) };

    if (isOpenPort() == false)
    {
        openPort();
    }

    if (write(ioDeviceHandle, command, sizeof (command)) == -1)
    {
        perror("[Warning] MaestroController writing");
    }
}

int MaestroController::readRespons()
{
    if (isOpenPort() == false)
    {
        openPort();
    }
    
    unsigned short dataHandle = 0;
    if (read(ioDeviceHandle, &dataHandle, sizeof (dataHandle)) != sizeof (dataHandle))
    {
        perror("[Warning] MaestroController getErrors");
    }
    return dataHandle;
}

void MaestroController::openPort()
{
    ioDeviceHandle = open(ioDeviceHandlePath, O_RDWR | O_NOCTTY);

    struct termios options;
    tcgetattr(ioDeviceHandle, &options);
    options.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    options.c_oflag &= ~(ONLCR | OCRNL);
    tcsetattr(ioDeviceHandle, TCSANOW, &options);

    if (isOpenPort() == false)
    {
        throw "[Error] MaestroController openPort";
    }
}

bool MaestroController::isOpenPort()
{
    if (ioDeviceHandle == -1)
    {
        return false;
    }
    return true;
}

unsigned short MaestroController::getStatus(unsigned char type)
{
    const unsigned char data[] = {type};
    if (write(ioDeviceHandle, data, sizeof (data)) != sizeof (data))
    {
        perror("[Warning] MaestroController getErrors1");
    }
    
    unsigned short status = 0;
    if (read(ioDeviceHandle, &status, sizeof (status)) != sizeof (status))
    {
        perror("[Warning] MaestroController getErrors2");
    }
    return status;
}

MaestroController::~MaestroController()
{
    if (isOpenPort())
    {
        close(ioDeviceHandle);
    }
}
