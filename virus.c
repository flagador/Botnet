#include <stdlib.h>
#include "virus.h"
#define SPREADINGRATE 0.1


extern virus_t * virus_creer(char * name){
    virus_t * virus = malloc(sizeof(virus_t));
    virus->name=name;
    virus->spreading_rate= SPREADINGRATE;
    return(virus);
}


