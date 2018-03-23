#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H
#include "mbed.h"
/**
Class Potentiometer wordt gebruikt voor een instantie van een potentiometer te initialiseren 
en de huidige waarde op de potentiometer te kunnen opvragen.
*/
class Potentiometer
{
    private: 
        AnalogIn potentio; 
    public: 
        /**
        * Constructor van de class Potentiometer voor initialisatie van de pinnen van de potentiometer. 
        */
        Potentiometer();
        /**
        * Teruggeven van de waarde op de potentiometer. 
        * @return float waarde van de potentiometer als kommagetal 
        */ 
        float getPotentioValue(); 
    
}; 
#endif 