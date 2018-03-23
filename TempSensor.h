#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H
#include "LM75B.h"
/**
Class TempSensor wordt gebruikt om een instantie van de temperatuur sensor LM75B te initialiseren 
en de huidig temperatuur te kunnen binnenlezen.  
*/
class TempSensor
{
    private:
        LM75B tSensor;  
    public: 
        /**
        * Constructor van class TempSensor voor de initialisatie van de sensor.
        */
        TempSensor();  
        /**
        * Teruggeven van de waarde van de temperatuur sensor. 
        * @return float waarde van de temperatuursensor als kommagetal 
        */
        float getTempValue(); 
};  
#endif