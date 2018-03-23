#ifndef LCDSCREEN_H
#define LCDSCREEN_H
#include "C12832.h"
#include "mbed.h"
#include <string>
/**
Class LCDScreen bevat LCD scherm van de mbed en al naargelang de functie 
strings gaat weergeven op het scherm. 
*/
class LCDScreen
{
    private: 
        C12832 screen; 
    
    public: 
        /**
        * Constructor van de class LCDScreen dat zorgt voor initialisatie van het scherm. 
        */
        LCDScreen(); 
        /**
        * Lokaliseren op het scherm van waar de tekst moet terechtkomen. 
        * @param x waarde van waar de eerste letter op de x-as (horizontaal) wordt geplaatst
        * @param y waarde van de positie op de y-as (verticaal) waar de eerste letter komt 
        */
        void LCDLocate(int x, int y);
        /**
        * Printen van tekst op LCD scherm.
        * @param text tekst dat moet op het scherm terechtkomen (tekst meegegeven met de request)  
        */
        void LCDPrint(string text); 
        /**
        * Printen van ID op het scherm zodat je de ID ziet veranderen als je de joystick beweegt. 
        * @param id 
        */
        void LCDPrintID(int id); 
        /**
        * Printen van de huidige mode (MASTER/SLAVE). 
        * @param mode als 0 wordt meegeven is het SLAVE dat wordt afgedrukt en 1 voor MASTER af te printen
        */
        void LCDPrintMode(int mode); 
        /**
        * Opruimen van LCD scherm zodanig dat het scherm terug leeg is. 
        */
        void LCDClear(); 
}; 
#endif