#include "LCDScreen.h"

LCDScreen :: LCDScreen() : screen(p5, p7, p6, p8, p11) { }

void LCDScreen :: LCDLocate(int x, int y)
{
    screen.locate(x, y); 
}

void LCDScreen :: LCDPrint(string text)
{
    screen.locate(0,0); 
    screen.cls(); 
    screen.printf("%s", text); 
}

void LCDScreen :: LCDPrintID(int id)
{
    screen.printf("Mbed ID: %d", id); 
}

void LCDScreen :: LCDPrintMode(int mode)
{
     screen.printf("Mbed mode: %s", mode == 0 ? "SLAVE " : "MASTER"); 
}

void LCDScreen :: LCDClear()
{
    screen.cls(); 
}