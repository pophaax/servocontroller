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

using namespace std;

void servoExample() {
  MaestroController* maestro = new MaestroController();
  ServoObject* servo = new ServoObject();
  try {
    maestro->setPort("/dev/ttyACM1");
    
    servo->setController(maestro);
    servo->setChannel(1);
    while(true) {
        int position;
        cout << "Enter position: ";
        cin >> position;
        servo->setPosition(position);
        cout << servo->getPosition() << endl;
        cout << "#Status " << endl;
        cout << "#Servo position > " << 
        servo->getPosition() << endl;
    }
  } catch(const char* error) {
      cout << error << "\n";
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
        cin >> position;
        cout << sensor->getDirection() << endl;
    }
  } catch(const char* error) {
      cout << error << "\n";
  }
  delete sensor;
  delete maestro;
}

int main(int argc, char** argv) {

  servoExample();
  //sensorExample();
  return 0;

}
