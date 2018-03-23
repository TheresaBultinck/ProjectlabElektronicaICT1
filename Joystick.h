#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "mbed.h"
/**
Class Joystick dient om de joystick te kunnen aansturen en veranderingen van de joystick te kunnen waarnemen. 
*/
class Joystick 
{
    private: 
        BusIn joy; 
        DigitalIn enter; 
        
        /**
        * Minimum waarde is de kleinste waarde waartussen de joystick kan wijzigen en maximum waarde de grootste waarde. 
        * Value is de huidige waarde waar de joystick nu op staat (in geval van ID zal dit te zien zijn op het LCD scherm en 
        voor master en slave hetzelfde maar dan niet met cijfers)
        * Oldstate is om te registreren of de joystick een beweging heeft gemaakt al dan niet. 
        */
        int minimum, maximum, value;
        int oldstate; 

    public: 
        /**
        * Constructor van de class Joystick om de joystick te initialiseren. 
        */
        Joystick(); 
        /**
        * Initialiseren van de minimum en maximum waarden waartussen de joystick de huidige waarde (value) moet kunnen veranderen. 
        * Voor de selectie van een ID is de minimum en maximum waarde 100 en 110. Voor master/slave zijn dat de waarden 0 en 1. 
        * @param minimum kleinste waarde waartussen de joystick kan veranderen 
        * @param maximum grootste waarde waartussen de joystick kan veranderen 
        */
        void initialize(int min, int max); 
        /**
        * Observeren van de bewegingen dat er plaatsvinden met de joystick en als de joystick naar boven en/of naar beneden beweegt, 
        * dan verandert de waarde van joy en is dus niet langer gelijk aan de vorige toestand (oldstate) en verandert waarde value. 
        * @return integer huidige waarde (value)
        */
        int update(); 
        /**
        * Controleren of er op de joystick gedrukt is geweest. 
        * @return bool true als op de joystick is gedrukt en false indien niet op de joystick gedrukt 
        */
        bool fire(); 
    
};
#endif 