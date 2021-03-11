#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h> 
#include "virus.h"



extern virus_t *virus_create(char name[], float spr_rate, float rsch_rate){
    virus_t * virus = malloc(sizeof(virus_t));

    virus->name=name;

    virus->spreading_rate=spr_rate;

    virus->research_rate=rsch_rate;
    return(virus);
}

extern void edit_rsch_rate(virus_t * virus, float rsch_rate){
    virus->research_rate=rsch_rate;
}

extern void edit_spr_rate(virus_t * virus, float spr_rate){
    virus->spreading_rate=spr_rate;
}

static void virus_destroy(virus_t **virus){
    free((*virus));
    (*virus)=NULL;
}

static void virus_display(virus_t *virus){
    printf("Nom du virus : %s \n", virus->name);
    printf("Taux de propagation : %f \n", virus->spreading_rate);
    printf("Taux de recherche : %f \n", virus->research_rate);
}

static int spreads(virus_t *virus){ //à combien d'ordinateurs le virus va-t-il se propager
    return((int)virus->spreading_rate*(rand()%10));
}

/*int main(){
    srand(time(0)); 
    virus_t * virus = virus_create("covid",3.1,2.5);
    printf("kebab");
    virus_display(virus);
    edit_spr_rate(virus, 2.1);
    virus_display(virus);
    printf("%d\n", spreads(virus));
}*/


