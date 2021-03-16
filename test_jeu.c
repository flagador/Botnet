#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "virus.h"
#include "upgrade.h"
#include "jeu.h"
#include "computer_list.h"
#include "country_list.h"
#include "time.h"

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

    /*computer_list_t * list_pc = liste_creer(10);
    computer_t * c = computer_create(10, 5, 0);
    computer_t * c1 = computer_create(15, 10, 1);
    liste_elem_ecrire(list_pc, c);
    liste_elem_ecrire(list_pc, c1);

    mine_btc(jeu, list_pc);
    printf("Thunes : %f \n", jeu->btc);*/

    country_list_t * cl = creer_country_list();

    cl->liste[0]->compromised_pcs_cpt = 10;

    for(int i = 0; i < 50; i++)
    {
        spread_world(jeu->virus, cl); 
        mine_btc_world(jeu, cl);
        printf(" * * * * * * * * * * * Thunes : %f \n", jeu->btc);
    }

    buy_upgrade(jeu, trojan);
    printf(" * * * * * * * * * * * Thunes : %f \n", jeu->btc);

    virus_destroy(&jeu->virus);
    detruire_country_list(&cl); 

    return 0;
}
