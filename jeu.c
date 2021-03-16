#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "virus.c"
#include "upgrade.c"
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

void buy_upgrade(jeu_t *jeu, upgrade_t *upgrade)
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
        if (list->element->computer->status == 1){

            jeu->btc += (list->element->computer->power * list->element->computer->weight * jeu->mining_rate);
        }
        list->element=list->element->next;
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

int main()
{

    virus_t *virus = virus_create("kaboub", 0.5, 0.5);
    virus_display(virus);

    upgrade_t *upgrade = upgrade_create("phishing", 30.0, 0.2, 0.2);
    upgrade_t *cles_usb = upgrade_create("clés usb", 15, 0.1, 0.3);
    upgrade_t *trojan = upgrade_create("trojan", 100.0, 0.5, 0.3);
    upgrade_t *fake_ad = upgrade_create("fake ad", 150, 1.0, 1.0);
    upgrade_display(upgrade);

    jeu_t *jeu = jeu_create(virus, 200.5);
    virus_display(jeu->virus);

    printf("Thunes : %f \n", jeu->btc);
    buy_upgrade(jeu, upgrade);

    virus_display(jeu->virus);
    printf("Thunes : %f \n", jeu->btc);

    computer_list_t * list_pc = liste_creer();
    computer_t * c = computer_create(10, 5, 0);
    computer_t * c1 = computer_create(15, 10, 1);
    liste_elem_ecrire(list_pc, c);
    liste_elem_ecrire(list_pc, c1);

    mine_btc(jeu, list_pc);
    printf("Thunes : %f \n", jeu->btc);

    country_list_t * list_country = creer_country_list();
    afficher_country_list(list_country);

    return 0;
}
