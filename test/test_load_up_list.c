#include "../lib/upgrade_list.h"

#include <stdio.h>

int main()
{
    upgrade_list_t *l = upgrade_liste_charger("../datas/upgrade.save");
    printf("upgrade_list créée\n");

    printf("upgrade list : \n");
    afficher_upgrade_list(l);
    upgrade_liste_destroy(&l);
    if(!upgrade_liste_existe(l)){
        printf("Test passé !");
    }
    else{
        printf("L'upgrade list existe toujours : pb");
    }
}