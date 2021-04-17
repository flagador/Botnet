#include "../lib/config.h"
#include <stdio.h>

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
