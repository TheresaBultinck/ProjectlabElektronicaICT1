#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "mbed.h"
#include "Communication.h"
#include "Joystick.h"
#include <string>

#define BASE_IP "192.168.0."
#define UDP_PORT 4000

#define MIN_ID 100
#define MAX_ID 110

typedef enum {INIT_DEVICE, MODE_SELECT, STATE_SLAVE, MASTER_DEST, STATE_MASTER} STATE; 

class Statemachine 
{
    private:
        LCDScreen screen; 
        Serial pc; 
        Joystick stick; 
        
        Communication connection; 
        STATE state; 
        
        int id;
        char destination[14]; 
         
    public:
        /**
        * Constructor voor initialisatie van de componenten.  
        */
        Statemachine();
        
        /**
        * Alle states zullen worden overlopen en voor elke state een specifieke implementatie zal worden voorzien.
        */
        void run(); 
        
};
#endif 