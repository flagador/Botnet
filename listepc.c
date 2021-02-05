#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listepc.h"

extern 
int liste_existe(liste_t * const liste){
    if(liste == NULL)
        return 0;
    return 1;
}

extern 
liste_t * liste_creer(const int nb){
    liste_t * liste;

    if((liste = malloc(sizeof(liste_t))) == NULL){
        fprintf(stderr, "liste_creer: debordement memoire lors de la creation d'une liste \n");
        return((liste_t *)NULL);
    }

    liste->nb = nb;
    liste->liste = (objet_t **)NULL;
    if(nb > 0){
        if((liste->liste = malloc (sizeof(objet_t *) *nb)) == NULL){
            fprintf(stderr, "liste_creer: debordement memoire lors de la creation d'une liste \n");
            free(liste);
            return ((liste_t*)NULL);
        }
    }
    return (liste);
}

/*
static
err_t liste_destroy(liste_t ** liste){
    int i;
    for(i = 0; i<(*liste)->nb;i++){
        if((*liste)->liste[i]!=NULL)
            (*liste)->liste[i]->detruire(&((*liste)->liste[i]));
    }
    free((*liste)->liste);
    free(*liste);
    return 1;
}
*/
