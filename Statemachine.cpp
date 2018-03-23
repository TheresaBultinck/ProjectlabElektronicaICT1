#include "Statemachine.h"

Statemachine :: Statemachine() : pc(USBTX, USBRX)
{
    state = INIT_DEVICE; 
    id = MIN_ID; 
    stick.initialize(MIN_ID, MAX_ID); 
}

void Statemachine :: run()
{
    switch(state)
    {
        case INIT_DEVICE: 
        {
            id = stick.update(); 
            screen.LCDLocate(0,0); 
            screen.LCDPrintID(id); 
            if(stick.fire())
            {
                char textID[4]; 
                sprintf(textID, "%d", id); 
                pc.printf("This mbed has the following ID: %s\r\n", textID);  
                string ip; 
                ip.append(BASE_IP).append(textID); 
                char* address = const_cast<char*>(ip.c_str());
                connection.initialize(address, textID, UDP_PORT); 
                state = MODE_SELECT; 
                stick.initialize(0,1); 
                screen.LCDClear(); 
            }
            break; 
        }
        case MODE_SELECT: 
        {
            int mode = stick.update(); 
            screen.LCDLocate(0,0); 
            screen.LCDPrintMode(mode); 
            if(stick.fire())
            {
                if (mode == 0)
                {
                    pc.printf("Mbed mode is SLAVE\r\n"); 
                    state = STATE_SLAVE; 
                }
                else 
                {
                    pc.printf("Mbed mode is MASTER\r\n"); 
                    state = MASTER_DEST;
                } 
                screen.LCDClear(); 
            }
            break; 
        }
        case STATE_SLAVE: 
        {
            pc.printf("----------------------------------------------------------\r\n");  
            pc.printf("%s with 192.168.0.%d\r\n", "SLAVE", id);
            pc.printf("Mbed is now ready to receive\r\n");
            char buffer[512]; 
            Endpoint client; 
            connection.receive(buffer, &client); 
            pc.printf("Request received: %s from %s\r\n", buffer, client.get_address());
            
            string message = connection.process(string(buffer), client);
            /**
            Message is een string en we verwachten in de methode een char*. Vandaar methode c_str() aanroepen, maar daarvan krijgen 
            we een const char* terug. Vandaar nog een casten naar (char*).
            */
            connection.send(client, (char*) message.c_str()); 
            pc.printf("ACK sent: %s\r\n", message); 
            break; 
        }
        case MASTER_DEST:
        {
            char dest[14] = {}; 
            strcpy(dest, "192.168.0."); 
            pc.printf("----------------------------------------------------------\r\n");
            pc.printf("%s with 192.168.0.%d\r\n", "MASTER", id);
            pc.printf("Enter a destination ID: "); 
            while(true) {
                char input = pc.getc();
                //Input printen van zodra beginnen met typen en overgaan naar volgende state wanneer lengte van destination ID bereikt (3 integers)
                pc.printf("%c", input);
                dest[strlen(dest)] = input;
                if(strlen(dest) >= 13)
                    break;
            }
            //Verkregen destination IP wordt gekopieerd naar de destination character array (public) zodat het ook in de andere cases kan worden gebruikt
            strcpy(destination, dest);
            state = STATE_MASTER; 
        }
        case STATE_MASTER: 
        {
            char request[512] = {}; 
            pc.printf("\r\nEnter a request: "); 
            while(true)
            {
                char input = pc.getc();
                pc.printf("%c", input);
                if(input != '\r' && strlen(request) < 512)
                    request[strlen(request)] = input;
                else
                    break;
            }
            Endpoint client;
            client.set_address(destination, UDP_PORT); 
            pc.printf("\nRequest '%s' send to %s:%d \r\n", request, destination, UDP_PORT); 
            connection.send(client, request); 
            char buffer[512]; 
            connection.receive(buffer, &client); 
            pc.printf("ACK received: %s\r\n", buffer); 
            state = MASTER_DEST; 
            break; 
        }   
        default:  
        {
            pc.printf("An error has occured, restarting...\r\n");
            state = INIT_DEVICE;
        }
    }
}