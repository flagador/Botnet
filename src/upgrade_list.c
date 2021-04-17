#include "../lib/upgrade_list.h"
#include <stdlib.h>
#include <stdio.h>

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

extern int upgrade_liste_sauv(upgrade_list_t *liste)
{
    FILE *f = fopen("../datas/upgrade.save", "w");
    for (int i = 0; i < liste->nb; i++)
    {
        fprintf("%s, %d %d %d \n", liste->liste[i]->name, liste->liste[i]->price, liste->liste[i]->research_rate, liste->liste[i]->spreading_rate);
    }
    fclose(f);
    return 0;
}

extern upgrade_list_t * upgrade_liste_creer(const int nb)
{
    upgrade_list_t *l = malloc(sizeof(upgrade_list_t));
    
    l->liste = malloc(sizeof(upgrade_t*) * nb);

    for (int i = 0; i < nb; i++)
    {
        l->liste[i] = NULL;
    }

    return l;
}
