#include <stdlib.h>
#include <virus.h>
#DEFINE SPREADING_RATE 0.1


extern virus_t * virus_creer(char name){
    virus_t virus = malloc(sizeof(virus_t));
    virus->name=name;
    virus->spreading_rate
}

void main(){
    virus_creer("covid");
}
