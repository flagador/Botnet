#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "virus.h"


extern virus_t * virus_create(char * name, float *spr_rate, float *rsch_rate){
    virus_t * virus = malloc(sizeof(virus_t));

    virus->name=malloc(strlen(name)+1);
    strcpy(virus->name,name);

    virus->spreading_rate= malloc(sizeof(float));
    virus->spreading_rate=spr_rate;

    virus->research_rate= malloc(sizeof(float));
    virus->research_rate=rsch_rate;
    return(virus);
}

static void virus_destroy(virus_t **virus){
    free((*virus)->name);
    free((*virus)->spreading_rate);
    free((*virus)->research_rate);
    virus=NULL;
}

int main(){

}


