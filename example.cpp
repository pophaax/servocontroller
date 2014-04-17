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

/*
 * 
 */

enum heading {
    b3 = -45,
    b2 = -30,
    b1 = -15,
    mid = 0,
    s1 = 15,
    s2 = 30,
    s3 = 45,
    null = -1
};

void mySleep(int sleepMs) {
    usleep(sleepMs * 1000); // usleep takes sleep time in us
}

int main(int argc, char** argv) {

	MaestroController * maestro = new MaestroController();
	
	ServoObject * servo1 = new ServoObject();
	ServoObject * servo2 = new ServoObject();
try {
	maestro->setPort("/dev/ttyACM0");
	servo1->setController(maestro);
	servo2->setController(maestro);
	
    /** Config **/
    servo1->setChannel(0);
    servo1->setMax(8000);
    servo1->setMin(4000);
    servo1->setRange(90);

    servo2->setChannel(1);
    servo2->setMax(8000);
    servo2->setMin(4000);
    servo2->setRange(90);

    servo2->setAcceleration(20);
    servo2->setSpeed(10);

    servo1->setPosition(mid);
    servo2->setPosition(mid);
    cout << "done!" << endl;
    

        int position;
        cout << "Enter position: ";
        cin >> position;
        servo1->setPosition(position);
        servo2->setPosition(position);
        
 //       cout << "#Status " << endl;
//        cout << "serov 1 Position > " << servo1->getPosition() << endl;
//        cout << "serov 2 Position > " << servo2->getPosition() << endl;
//        cout << "#Errors > " << maestro->getStatus(GET_ERROR) << endl;
//    while(1){
//        servo1->setPosition(s3);
//        servo2->setPosition(b3);
//        mySleep(5000);
//        cout << servo1->getPosition() << endl;
//        cout << servo2->getPosition() << endl;
//        servo1->setPosition(b3);
//        servo2->setPosition(s3);
//        mySleep(5000);
//        cout << servo1->getPosition() << endl;
//        cout << servo2->getPosition() << endl;
//        cout << "#Errors > " << maestro->getStatus(GET_ERROR) << endl;
//    }
    
} catch(const char* e) {
	cout << e << "\n";
}
	delete servo1;
	delete servo2;
	delete maestro;
	return 0;
}