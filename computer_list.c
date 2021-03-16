#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "computer_list.h"


extern 
int liste_elem_ecrire(computer_list_t * liste, computer_t * const elem){
    if(liste->element==NULL){
        element_t * new;
        new = malloc(sizeof(element_t));
        new->computer = elem;
        new->next = new;
        new->prev = new;
        liste->element = new;
        liste->nb++;

        
    }else{
        element_t * new;
        new = malloc(sizeof(element_t));
        new->computer = elem;
        new->prev = liste->element->prev;
        new->next = liste->element;
        liste->element->prev = new;
        new->prev->next = new;
        liste->nb++;
    }
    
    
    
    /*
    
    if(liste->computer == NULL){
        liste->computer = elem;
        liste->next = liste;
        liste->prev = liste;
    }else{
        element_t * new;
        new = malloc(sizeof(element_t));
        new->computer = elem;
        new->prev = liste;
        new->next = liste->next;
        liste->next = new;

    }*/
    return 1;
}

extern
computer_t * get_element(int num, element_t * liste){
    element_t * buff;
    int i;
    buff = liste;
    for(i = 0; i<num; i++){
        buff = liste->next;
    }
    return (buff->computer);
}

extern 
computer_list_t * liste_creer(){
    computer_list_t * liste;

    if((liste = malloc(sizeof(computer_list_t))) == NULL){
        fprintf(stderr, "liste_creer: debordement memoire lors de la creation d'une liste \n");
        return((computer_list_t *)NULL);
    }
    liste->detruire = liste_destroy;
    liste->nb=0;
    liste->element = NULL;

    return (liste);
}


static
int liste_destroy(computer_list_t ** liste){
    element_t * elem;
    element_t * next;
    int i;
    elem = (*liste)->element;
    for(i=0 ;i<(*liste)->nb; i++){ 
        elem->computer->detruire(&(elem->computer));
        next=elem->next;
        free(elem);
        elem=next;
    }
    free(*liste);
    liste = NULL;
    return 1;
}

