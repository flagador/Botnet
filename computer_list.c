#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "computer_list.h"

extern 
int liste_existe(computer_list_t * const liste){
    if(liste == NULL)
        return 0;
    return 1;
}

extern 
computer_list_t * liste_creer(const int nb){
    computer_list_t * liste;

    if((liste = malloc(sizeof(computer_list_t))) == NULL){
        fprintf(stderr, "liste_creer: debordement memoire lors de la creation d'une liste \n");
        return((computer_list_t *)NULL);
    }

    liste->nb = nb;
    liste->liste = (computer_t **)NULL;
    if(nb > 0){
        if((liste->liste = malloc (sizeof(computer_t *) *nb)) == NULL){
            fprintf(stderr, "liste_creer: debordement memoire lors de la creation d'une liste \n");
            free(liste);
            return ((computer_list_t*)NULL);
        }
    }
    return (liste);
}

extern
void liste_destroy(computer_list_t ** liste){
    int i;
    for(i = 0; i<(*liste)->nb;i++){
        if((*liste)->liste[i]!=NULL)
            (*liste)->liste[i]->detruire(&((*liste)->liste[i]));
    }
    free((*liste)->liste);
    free(*liste);
    return 1;
}
