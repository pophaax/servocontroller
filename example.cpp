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
#include "MaestroController.h"

using namespace std;

int main(int argc, char** argv) {

  MaestroController* maestro = new MaestroController();

  ServoObject* servo = new ServoObject();

  try {
    
    maestro->setPort("/dev/ttyACM0");
    
    servo->setController(maestro);
    
    servo->setMin(2000);
    
    servo->setMax(4000);
    
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

  return 0;

}
