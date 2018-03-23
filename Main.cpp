#include "Statemachine.h"
/**
Class Main zal een instantie maken van de Statemachine en vervolgens er voor zorgen dat het programma zal runnen met de methode run. 
*/
int main() {
    Statemachine instance; 
    while(true)
        instance.run();
}