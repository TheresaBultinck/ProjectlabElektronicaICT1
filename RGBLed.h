#ifndef RGBLED_H
#define RGBLED_H
#include "mbed.h"
#include <string>
/**
Class RGBLed wordt gebruikt om RGBLed te kunnen laten oplichten 
naar een bepaald kleur dat wordt ingegeven bij de request in de UDP/IP communicatie.
*/
class RGBLed 
{
    private: 
        PwmOut redPin;
        PwmOut greenPin; 
        PwmOut bluePin; 
        /**
        * Drie kommagetallen (float) gebruiken om een kleur te vormen op de RGB Led. 
        * @param red waarde voor de rode pin 
        * @param green waarde voor de groene pin
        * @param blue waarde voor de blauwe pin  
        */
        void write(float red, float green, float blue); 
        
    public: 
        /**
        * Constructor van de class RGBLed voor initialisatie van de pinnen van de LED. 
        */
        RGBLed(); 
        /**
        * RGBLed laten oplichten met het opgegeven string argument met behulp van de methode write. 
        * @param color de naam van de kleur 
        * @return bool false als er een kleur is meegegeven dat niet overeenkomt met de kleuren die kunnen worden gekozen 
            en true als de kleur juist is 
        */
        bool setColor(string color); 
};
#endif 