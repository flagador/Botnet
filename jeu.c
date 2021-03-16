#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "virus.h"
#include "upgrade.h"
#include "jeu.h"
#include "computer_list.h"
#include "country_list.h"



extern jeu_t *jeu_create(virus_t *vir, float btc)
{ //cr�� un jeu
    jeu_t *jeu = malloc(sizeof(jeu_t));

    jeu->virus = vir;

    jeu->btc = btc;

    jeu->mining_rate=0.5;

    return (jeu);
}

extern void buy_upgrade(jeu_t *jeu, upgrade_t *upgrade)
{ //achat d'un upgrade

    if (jeu->btc >= upgrade->price)
    {
        jeu->btc = jeu->btc - upgrade->price; //enleve le prix de l'upgrade � notre argent

        jeu->virus->spreading_rate += upgrade->spreading_rate;

        jeu->virus->research_rate += upgrade->research_rate;
        //upgrade_destroy(&upgrade);
    }
    else
    {
        printf("Pas assez d'argent \n");
    }
}

void edit_mining_rate(jeu_t * jeu, float rate){ // modifie le taux de minage
    jeu->mining_rate=rate;
}

void mine_btc(jeu_t *jeu, computer_list_t *list) // mine des bitcoins 
{   
    for(int i=0; i<list->nb; i++) 
    {
        if (list->liste[i]->status == 1){

            jeu->btc += (list->liste[i]->power * list->liste[i]->weight * jeu->mining_rate);
        }
    }
}

/*int game_state(country_list_t * list){ // vérifies si on a infecté 51% des ordinateurs du monde
    if(list->compromised_pcs_cpt/(list->healthy_pcs_cpt+list->compromised_pcs_cpt)>=0.51){
        return(1);
    } else {
        return(0);
    }
}
*/

