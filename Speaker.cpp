#include "Speaker.h"

int Speaker :: frequency[17] = { 110, 110, 110, 98, 130, 110, 98, 130, 110, 165, 165, 165, 175, 130, 104, 98, 130 }; 
int Speaker :: length[17] = {480, 480, 480, 360, 120, 480, 360, 120, 960, 480, 480, 480, 360, 120, 480, 360, 120}; 
int Speaker :: delay[17] = {100, 100, 100, 75, 100, 100, 75, 100, 100, 100, 100, 100, 75, 100, 100, 75, 100}; 

Speaker :: Speaker() : speakerPin(p26) {}

bool Speaker :: play(string start, string stop)
{
    /**
    String argumenten moeten worden omgevormd naar integers om te kunnen gebruiken in de gedefinieerde arrays.
    Dit kan gebeuren aan de hand van de methode atoi() (in library std) die strings zal omzetten naar integers, maar atoi() verwacht als argument 
    een pointer naar een character van arrays. Vandaar wordt functie c_str() aangeroepen op de argumenten start en stop. 
    */
    int begin = std::atoi(start.c_str());
    int end = std::atoi(stop.c_str());
    
    /**
    Opgegeven argumenten komen niet overeen met de mogelijke waarden in de tabel. 
    */
    if(end < begin || begin < 1 || begin > 17 || end < 1 || end > 17)
        return false;
    for(int i = begin; i <= end; i++) {
        speakerPin.period(1.0 / frequency[i-1]);
        speakerPin = 0.5; 
        //Delen door 1000, want werken in milliseconden
        wait(length[i-1]/1000.0);
        speakerPin = 0.0;
        wait(delay[i-1]/1000.0);
    }
    return true;
}