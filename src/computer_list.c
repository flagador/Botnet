/**
 * @file computer_list.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Definie les fonction primitives pour le type computer_list_t
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../lib/computer_list.h"

/**
 * @brief Retourne vrai si la computer_list_t passée en paramètre éxiste
 * 
 * @param liste 
 * @return int 
 */
extern 
int liste_existe(computer_list_t * const liste){
    if(liste == NULL)
        return 0;
    return 1;
}

/**
 * @brief Créer et retourne une computer_list_t
 * 
 * @param nb 
 * @return computer_list_t* 
 */
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

/**
 * @brief Détruit la computer_list_t passée en paramètre
 * 
 * @param liste 
 */
extern
void liste_destroy(computer_list_t ** liste){
    free((*liste)->liste);
    free(*liste);
    *liste = NULL;
}
