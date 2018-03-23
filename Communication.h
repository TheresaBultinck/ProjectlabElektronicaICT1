#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include "mbed.h"
#include "EthernetInterface.h"
#include "LCDScreen.h"
#include "TempSensor.h"
#include "RGBLed.h"
#include "Potentiometer.h"
#include "Speaker.h"
#include <string>
/**
Class Communication zal de ethernet verbinding opzetten en zal ook zorgen voor de nodige verwerking van de requests. 
Dit betekent dus dat de requests zullen worden ontvangen, verwerkt en zorgen dat er een response wordt op geformuleerd en verzonden. 
*/
class Communication
{
    private:
        EthernetInterface eth; 
        UDPSocket server;
    
        LCDScreen screen;
        RGBLed led; 
        Speaker speaker; 
        TempSensor temperatureSensor; 
        Potentiometer potentiometer; 
        char *ip, *id; 
        int port; 
     
    public:
        /**
        * Constructor. 
        */
        Communication(); 
        /**
        * Initialiseren van het IP-adres, ID van de mbed en poort waarop zal worden geluisterd.
        * Initialiseren van de ethernet verbinding (ethernet interface) en vervolgens ook de connectie opzetten. 
        * @param ip character array 
        * @param id character array 
        * @param port integer met de waarde van de poort waarop dat moet worden geluisterd
        */
        void initialize(char* ip, char* id, int port); 
        /**
        * Boodschap versturen naar een opgegeven bestemming. 
        * @param destination IP-adres van de mbed waarnaar de boodschap (request) moet worden verstuurd 
        * @param message character array 
        */
        void send(Endpoint destination, char* message); 
        /**
        * Ontvangen van de boodschap (request) van een bepaalde client
        * @param buffer zal de ontvangen requests opslaan van de clients 
        * @param client 
        */
        void receive(char* buffer, Endpoint* client); 
        /**
        * Verwerken van de request. Deze methode zal er voor zorgen dat er gepast gereageerd wordt op de ontvangen requests. 
        * @param request bevat de request dat ontvangen wordt vanuit de master
        * @param client bestemming waarnaar de response (acknowlegdment) moet worden teruggestuurd 
        */
        string process(string request, Endpoint client); 
}; 
#endif 

