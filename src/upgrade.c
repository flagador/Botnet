#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/upgrade.h"


extern upgrade_t *upgrade_create(char name[], float price, float spr_rate, float rsch_rate){ //cr�� un upgrade
    upgrade_t * upgrade = malloc(sizeof(upgrade_t));

    upgrade->name=name;

    upgrade->price=price;

    upgrade->spreading_rate=spr_rate;

    upgrade->research_rate=rsch_rate;
    return(upgrade);
}

extern void upgrade_edit_price(upgrade_t * upgrade, float price){ //modifie le prix du upgrade pass� en parametre
    upgrade->price=price;
}

extern void upgrade_edit_rsch_rate(upgrade_t * upgrade, float rsch_rate){ //modifie le taux de recherche du upgrade pass� en parametre
    upgrade->research_rate=rsch_rate;
}

extern void upgrade_edit_spr_rate(upgrade_t * upgrade, float spr_rate){ //modifie le taux de propagation du upgrade pass� en parametre
    upgrade->spreading_rate=spr_rate;
}

static void upgrade_destroy(upgrade_t **upgrade){ //d�truie le upgrade
    free((*upgrade));
    (*upgrade)=NULL;
}

extern void upgrade_display(upgrade_t *upgrade){ //affiche les donn�es du upgrade
    if(upgrade!=NULL){
        printf("Nom du upgrade : %s \n", upgrade->name);
        printf("Prix : %f \n", upgrade->price);
        printf("Taux de propagation : %f \n", upgrade->spreading_rate);
        printf("Taux de recherche : %f \n", upgrade->research_rate);
    } else {
        printf("Le upgrade n'existe pas");
    }
}

/*void main(){
    upgrade_t *op = upgrade_create("kebab",32.5,0.2,0.5);
    upgrade_display(op);
    upgrade_edit_rsch_rate(op, 0.5);
    upgrade_display(op);
}*/

