#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "upgrade.h"


extern upgrade_t * upgrade_create(char name[], float price, float spr_rate, float rsch_rate){ //créé un upgrade
    upgrade_t * upgrade = malloc(sizeof(upgrade_t));

    upgrade->name=name;

    upgrade->price=&price;

    upgrade->spreading_rate=&spr_rate;

    upgrade->research_rate=&rsch_rate;
    return(upgrade);
}

extern void *upgrade_edit_price(upgrade_t * upgrade, float price){ //modifie le prix du upgrade passé en parametre
    upgrade->price=&price;
}

extern void *upgrade_edit_rsch_rate(upgrade_t * upgrade, float rsch_rate){ //modifie le taux de recherche du upgrade passé en parametre
    upgrade->research_rate=&rsch_rate;
}

extern void *upgrade_edit_spr_rate(upgrade_t * upgrade, float spr_rate){ //modifie le taux de propagation du upgrade passé en parametre
    upgrade->spreading_rate=&spr_rate;
}

static void upgrade_destroy(upgrade_t **upgrade){ //détruie le upgrade
    free((*upgrade));
    (*upgrade)=NULL;
}

static void upgrade_display(upgrade_t *upgrade){ //affiche les données du upgrade
    if(upgrade!=NULL){
        printf("Nom du upgrade : %s \n", upgrade->name);
        printf("Prix : %f \n", *upgrade->price);
        printf("Taux de propagation : %f \n", *upgrade->spreading_rate);
        printf("Taux de recherche : %f \n", *upgrade->research_rate);
    } else {
        printf("Le upgrade n'existe pas");
    }
}



