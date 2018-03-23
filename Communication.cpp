#include "Communication.h"

Communication :: Communication() {} 

void Communication :: initialize(char* myIP, char* myID, int myPORT)
{
    ip = myIP; 
    id = myID; 
    port = myPORT; 
    
    /*Initialiseren van de ethernet verbinding. 
    Eerste argument is het statisch IP-adres (variabel, aangezien id nog moet worden gekozen)
    Tweede argument is het subnetmasker van de ethernet verbinding, meer bepaald 255.255.255.0
    Als laatste is er dan de default gateway 192.168.0.1
    */
    eth.init(ip, "255.255.255.0", "192.168.0.1"); 
    /*
    Deze methode zal de ethernet verbinding opzetten. 
    */
    eth.connect();
}

void Communication :: send(Endpoint destination, char* message)
{
    server.bind(port);
    /**
    De server de message laten versturen naar de juiste bestemming.
    De methode sendTo heeft drie argumenten:
        Endpoint &remote = endpoint = bestemming
        char* packet = char* message
        int length = lengte van het packet dat wordt verstuurd --> methode om lengte op te vragen van character array = strlen
    */
    server.sendTo(destination, message, strlen(message)); 
    server.close(); 
}

void Communication :: receive(char* buffer, Endpoint* client)
{
    //Verbinding moet telkens opnieuw worden opgezet en afgesloten
    server.bind(port); 
    /**
    De server de message juist laten ontvangen.
    De methode receiveFrom heeft drie argumenten en deze drie zijn analoog aan de argumenten van de methode sendTo.
    */
    int n = server.receiveFrom(*client, buffer, 512); 
    buffer[n] = '\0';
    server.close(); 
}

string Communication :: process(string request, Endpoint client)
{
    //Deze variabele zal een antwoord vormen op het request dat de master heeft gestuurd naar de slave 
    string response; 
    if(request == "GET /temperature")
    {
        char temperature[8]; 
        sprintf(temperature, "%.2f", temperatureSensor.getTempValue()); 
        response.append("ACK 2.05 ").append(id).append(" ").append(temperature);
    } 
    else if(request == "GET /potentiometer")
    {
        char potentio[8]; //Array waarnaar de gelezen waarde van de potentiometer naartoe wordt geschreven
        sprintf(potentio, "%.0f", (potentiometer.getPotentioValue()*255)); 
        response.append("ACK 2.05 ").append(id).append(" ").append(potentio); 
    } 
    else if(request.compare(0,9,"PUT /LCD ") == 0) {
        /**
        Het scherm zal enkel afdrukken wat er maximaal op mogelijk is.
        Als de character array groter is dan de grootte van het scherm, dan worden de characters die over het limiet gaan niet afgedrukt.
        */
        string text = request.substr(9, 503);
        screen.LCDPrint(text);
        response.append("ACK 2.04 ").append(id);
    }  
    else if(request.compare(0, 9, "PUT /LED ") == 0) {
        /**
        We gebruiken de methode substr, omdat we niet compleet de string request nodig hebben. Enkel hetgeen dat na PUT/LED komt is van belang.
        Analoog voor LCD request en buzzer request. 
        */
        string color = request.substr(9, 6);
        bool valid = led.setColor(color);
        if (valid)
            response.append("ACK 2.04 ").append(id); 
        else
            response.append("ACK 4.0 ").append(id); 
    }
    else if(request.compare(0, 12, "PUT /BUZZER ") == 0) {
        string range = request.substr(12, 5);
        int index = range.find("-");
        
        string start = range.substr(0, index);
        string stop = range.substr(index + 1, 2);

        bool valid = speaker.play(start, stop);
        if(valid)
            response.append("ACK 2.04 ").append(id);
        else
            response.append("ACK 4.0 ").append(id);
    }
    else 
    {
        response.append("ACK 4.0 ").append(id);
    }
    return response;
}
    
    

    


    