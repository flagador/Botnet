#include "../lib/upgrade_list.h"
#include <stdlib.h>
#include <stdio.h>
#include "../lib/config.h"

extern int upgrade_liste_existe(upgrade_list_t *const liste)
{
    return liste == NULL;
}

extern int upgrade_liste_destroy(upgrade_list_t **liste)
{
    for (int i = 0; i < (*liste)->nb; i++)
    {
        upgrade_destroy((*liste)->liste + i);
    }
    free(*liste);
    *liste = 0;
    return 0;
}

extern void afficher_upgrade_list(const upgrade_list_t *l)
{
    for (int i = 0; i < l->nb; i++)
    {
        printf("%i : ", i);
        upgrade_display(l->liste[i]);
        printf("\n");
    }
}

extern int upgrade_liste_sauv(upgrade_list_t *liste, char *path)
{
    FILE *f;

    f = fopen(path, "w");

    if (f == NULL)
    {
        printf("Erreur dans l'ouverture de %s\n", path);
        return -1;
    }
    for (int i = 0; i < liste->nb; i++)
    {
        fprintf(f, "%s, %f %f %f\n", liste->liste[i]->name, liste->liste[i]->price, liste->liste[i]->research_rate, liste->liste[i]->spreading_rate);
    }

    fclose(f);
    return 0;
}

extern upgrade_list_t *upgrade_liste_charger(char *nom_file)
{
    int nb_lignes = compter_lignes(nom_file);

    upgrade_list_t *l = upgrade_liste_creer(nb_lignes);

    char nom[50];
    float price, res_rate, sprd_rate;

    FILE *f;

    f = fopen(nom_file, "r");

    if (f == NULL)
    {
        printf("Erreur dans l'ouverture de %s\n", nom_file);
        return NULL;
    }
    

    for (int i = 0; i < nb_lignes; i++)
    {
        fscanf(f, "%[^,], %f %f %f\n", nom, &price, &res_rate, &sprd_rate);
        l->liste[i] = upgrade_create(nom, price, sprd_rate, res_rate);
    }
    return l;
}

extern upgrade_list_t *upgrade_liste_creer(const int nb)
{
    upgrade_list_t *l = malloc(sizeof(upgrade_list_t));
    l->nb = nb;
    l->liste = malloc(sizeof(upgrade_t *) * nb);

    for (int i = 0; i < nb; i++)
    {
        l->liste[i] = NULL;
    }

    return l;
}
