/**
 * @file config.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Ensemble de fonctions d'aide générale
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "../lib/config.h"
#include <stdio.h>

/**
 * @brief Compte les lignes d'un fichier
 * 
 * @param n_fichier Fichier dans lequel compter les lignes
 * @return int Nombre de lignes
 */
extern int compter_lignes(char *n_fichier)
{
    FILE *fichier;

    fichier = fopen(n_fichier, "r");

    int cpt = 0;
    int read;
    char tete;

    do
    {
        tete = fgetc(fichier);
        if (tete == '\n')
            cpt++;
    } while (!feof(fichier));

    return cpt;
}
