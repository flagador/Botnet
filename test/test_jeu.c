#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../lib/virus.h"
#include "../lib/upgrade.h"
#include "../lib/jeu.h"
#include "../lib/computer_list.h"
#include "../lib/country_list.h"

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void afficher_pays(country_list_t * cl){
    for(int i=0; i<18; i++){
        afficher_country(cl->liste[i]);
    }
}

void choix(country_list_t * cl, jeu_t * jeu, upgrade_t * upgrade, upgrade_t * cles_usb, upgrade_t * trojan, upgrade_t * fake_ad){
    printf(" 1 \n");
    upgrade_display(upgrade);
    printf(" 2 \n");
    upgrade_display(cles_usb);
    printf(" 3 \n");
    upgrade_display(trojan);
    printf(" 4 \n");
    upgrade_display(fake_ad);
    printf(" 5 : Afficher pays \n");
    printf(" 6 : Ne rien faire \n");

    int choix;
    printf("Quel choix voulez vous faire ?");
    scanf("%i", &choix);
    switch(choix){
        case 1 : buy_upgrade(jeu, upgrade);
        break;
        case 2 : buy_upgrade(jeu, cles_usb);
        break;
        case 3 : buy_upgrade(jeu, trojan);
        break;
        case 4 : buy_upgrade(jeu, fake_ad);
        break;
        case 5 : afficher_pays(cl);
        break;
        case 6 : exit;
        default : printf("pouet pouet");
    } 
}



int main()
{

    virus_t *virus = virus_create("kaboub", 1, 1);
    virus_display(virus);
    long double * proportion;

    upgrade_t *upgrade = upgrade_create("phishing", 30.0, 0.2, 0.2);
    upgrade_t *cles_usb = upgrade_create("clés usb", 15, 0.1, 0.3);
    upgrade_t *trojan = upgrade_create("trojan", 100.0, 0.5, 0.3);
    upgrade_t *fake_ad = upgrade_create("fake ad", 150, 1.0, 1.0);
    //upgrade_display(upgrade);

    jeu_t *jeu = jeu_create(virus, 200.5);
    virus_display(jeu->virus);

   /* printf("Thunes : %f \n", jeu->btc);
    buy_upgrade(jeu, upgrade);

    virus_display(jeu->virus);
    printf("Thunes : %f \n", jeu->btc);*/


    country_list_t * cl = creer_country_list();

    cl->liste[0]->compromised_pcs_cpt = 10;
    while(game_state(cl,jeu)==0)
    {
        choix(cl, jeu, upgrade, cles_usb, trojan, fake_ad);
        spread_world(jeu->virus, cl); 
        mine_btc_world(jeu, cl);
        printf(" * * * * * * * * * * * Thunes : %f \n", jeu->btc);
        
    }
    if(game_state(cl,jeu)==1){
        printf("Vous avez gagné,wow !");
    }


    virus_destroy(&jeu->virus);
    detruire_country_list(&cl); 

    return 0;
}
