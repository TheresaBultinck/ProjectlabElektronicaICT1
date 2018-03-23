#include "TempSensor.h"

TempSensor :: TempSensor() : tSensor(p28, p27) { }

float TempSensor :: getTempValue()
{
    return tSensor.read(); 
}