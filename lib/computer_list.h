/**
 * @file computer_list.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure computer_list_t et prototypes fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _COMPUTER_LIST_H_
#define _COMPUTER_LIST_H_

#include "computer.h"
/**
 * @struct computer_list_s
 * @brief Structure comprenant un nombre d'ordinateur et une liste de computer_s
 */
typedef struct computer_list_s{
    int nb;
    computer_t ** liste;
}computer_list_t;

extern int liste_existe(computer_list_t *const liste);
extern void liste_destroy(computer_list_t ** liste);
extern computer_list_t * liste_creer(const int nb);

#endif