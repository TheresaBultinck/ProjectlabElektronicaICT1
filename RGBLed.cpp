#include "RGBLed.h"

RGBLed :: RGBLed() : redPin(p23), greenPin(p24), bluePin(p25)
{ 
    /**
    Dit zal er voor zorgen dat de RGB Led niet continu wit blijft, als het programma in de mbed zit (en dus aan het draaien is). 
    De RGB Led zal zo enkel oplichten als de master daarnaar vraagt via een request en ook een korte flits geven bij 
    het duwen van de knop op de mbed om het programma in te laden. 
    Deze floatgetallen stellen de kleur zwart voor en geeft dus geen licht. 
    */
    write(1.0,1.0,1.0);    
}

void RGBLed :: write(float red, float green, float blue)
{
    redPin = red; 
    greenPin = green; 
    bluePin = blue; 
}
    

bool RGBLed :: setColor(string color) 
{
    /**
    Om te weten welke kleur is meegegeven als string en dus de kleur moet worden van de LED maken we gebruik van de methode compare. 
    Deze methode vraagt drie argumenten. 
    Eerst van welke positie in de string dat er moet worden begonnen met vergelijken, vervolgens de lengte van de string en 
    als laatste staat er de string zelf waarmee het opgegeven argument moet overeenkomen. 
    */
    if(color.compare(0,3,"RED") == 0)
        write(0.0, 1.0, 1.0);
    else if(color.compare(0,5,"GREEN") == 0)
        write(1.0,0.0,1.0);
    else if(color.compare(0,4,"BLUE") == 0)
        write(1.0,1.0,0.0);
    else if(color.compare(0,6,"ORANGE") == 0)
        write(0.0,0.5,1.0); 
    else if(color.compare(0,6,"PURPLE") == 0)
        write(0.5,1.0,0.5); 
    else if(color.compare(0,5,"WHITE") == 0)
        write(0.0,0.0,0.0);  
    else 
        return false; 
    return true; 
}
