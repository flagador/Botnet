/**
 * @file computer.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Le fichier computer.c définie les fonctions primitives de la structure computer_t
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "../lib/computer.h"

/**
 * @brief Retourne vrai si l'ordinateur passé en parametre existe
 * @param computer {Pointeur sur un computer_t}
*/
extern int computer_exist( computer_t * const computer)
{
    if (computer == NULL)
        return 0;
    return 1;
}

/**
 * @brief Supprime l'ordinateur passé en paramètre
 * @param computer {Double pointeur sur un computer_t}
*/
static
int computer_destroy(computer_t ** computer)
{
    free(*computer);
    return 1;
}

/**
 * @brief Créer un objet computer_t
 * 
 * @param weight 
 * @param power puissance de l'ordinateur
 * @param status status : infecte ou non
 * @return computer_t* 
 */
extern 
computer_t * computer_create(int weight ,int power, int status)
{
    computer_t * computer = malloc(sizeof(computer_t));
    computer->detruire = computer_destroy;
    computer->weight = weight;
    computer->power = power;
    computer->status = status;

    return( computer );
}
