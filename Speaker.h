#ifndef SPEAKER_H
#define SPEAKER_H
#include "mbed.h"
#include <string>
/**
Class Speaker wordt gebruikt om bepaalde frequenties te kunnen laten afspelen op de speaker van de mbed. 
De frequenties waartussen de toon moet worden afgespeeld, wordt opgegeven aan de hand van twee nummers (zie tabel buzzer tunes).
*/
class Speaker
{
    private:
        PwmOut speakerPin; 
        /**
        Maken van statische arrays van de frequenties, lengtes en delays. Wel goed opletten bij de argumenten, 
        argumenten zullen gaan van 1 tot 17, terwijl de array geïndexeerd is van 0 tot 16. Vandaar zal in de methodes telkens één 
        van worden afgetrokken. 
        */
        static int frequency[17], length[17], delay[17];
         
    public:
        /**
        * Constructor van de class Speaker voor initialisatie van de buzzer. 
        */
        Speaker(); 
        /**
        * Geluid laten afspelen tussen een opgegeven startpunt en opgegeven eindpunt. 
        * @param start begin waarde waarvan het geluid moet worden afgespeeld (waarde komt overeen met bepaalde frequentie - zie tabel) 
        * @param stop eindwaarde waartussen het geluid zal worden afgespeeld 
        * De argumenten zijn strings en geen integers, omdat de request van de gebruiker als string zal worden binnengelezen en de nummers dus ook.
        * @return bool false als de gegeven start -en stopwaarde niet overeenkomen met de mogelijkheden uit de tabel en 
            true als de nummers wel terug te vinden zijn in de tabel 
        */
        bool play(string start, string stop);  
};
#endif 