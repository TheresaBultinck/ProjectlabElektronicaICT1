#include "Potentiometer.h"

Potentiometer :: Potentiometer() : potentio(p19) { }

float Potentiometer :: getPotentioValue()
{
    return potentio; 
}