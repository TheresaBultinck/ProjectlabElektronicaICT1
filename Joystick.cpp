#include "Joystick.h"

Joystick :: Joystick() : joy(p15,p12,p13,p16), enter(p14) {}

void Joystick :: initialize(int min, int max)
{
    minimum = min; 
    maximum = max; 
    
    //We stellen de waarde standaard in op de laagste waarde dat werd gedeclareerd
    value = min; 
    //Oldstate bevat de huidige "positie" van de joystick 
    oldstate = joy;
}

int Joystick :: update()
{
    /**Als de joystick verandert is van positie/waarde en dus niet langer gelijk is aan oldstate,
    mag de value veranderen tussen minimum en maximum
    */
    if(joy != oldstate)
    {
        if(joy == 0x1)
        {
            value = value < maximum ? value + 1 : minimum;  
        }
        else if (joy == 0x2)
        {
            value = value > minimum ? value - 1: maximum; 
        }
        oldstate = joy; 
    }
    return value; 
}

bool Joystick :: fire()
{
    if(enter)
        return true; 
    else
        return false; 
}

