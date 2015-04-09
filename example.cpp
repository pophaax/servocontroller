/* 
 * File:   main.cpp
 * Author: Joakim
 *
 * Created on 20 March 2014, 09:25
 */


#include <unistd.h>

#include <cstdlib>
#include <iostream>

#include "ServoObject.h"
#include "SensorObject.h"
#include "MaestroController.h"


void servoExample() {
  MaestroController* maestro = new MaestroController();
  ServoObject* servo = new ServoObject();
  try {
    maestro->setPort("/dev/ttyACM0");
    
    servo->setController(maestro);
    servo->setChannel(1);
    while(true) {
        int position;
        std::cout << "Enter position: ";
        std::cin >> position;
        servo->setPosition(position);
        std::cout << servo->getPosition() << std::endl;
        std::cout << "#Status " << std::endl;
        std::cout << "#Servo position > " << 
        servo->getPosition() << std::endl;
    }
  } catch(const char* error) {
      std::cout << error << "\n";
  }
  delete servo;
  delete maestro;
}


void sensorExample() {
  MaestroController* maestro = new MaestroController();
  SensorObject* sensor = new SensorObject();
  try {
    maestro->setPort("/dev/ttyACM0");
    sensor->setController(maestro);
    sensor->setChannel(5);
    while(true) {
        int position;
        std::cin >> position;
        std::cout << sensor->getDirection() << std::endl;
    }
  } catch(const char* error) {
      std::cout << error << "\n";
  }
  delete sensor;
  delete maestro;
}

int main(int argc, char** argv) {

  servoExample();
  //sensorExample();
  return 0;

}
