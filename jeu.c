#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "virus.c"
#include "upgrade.c"
#include "jeu.h"



extern jeu_t * jeu_create(virus_t *vir, float btc){ //cr�� un jeu
    jeu_t * jeu = malloc(sizeof(jeu_t));

    jeu->virus=vir;

    jeu->btc=btc;

    return(jeu);
}

void buy_upgrade(jeu_t *jeu, upgrade_t *upgrade){ //achat d'un upgrade

    if(jeu->btc>upgrade->price){
        jeu->btc=jeu->btc-upgrade->price; //enleve le prix de l'upgrade � notre argent

        jeu->virus->spreading_rate+=upgrade->spreading_rate;

        jeu->virus->research_rate+=upgrade->research_rate;
        //upgrade_destroy(&upgrade);
    } else {
        printf("Pas assez d'argent \n");

    } 
}

int main(){

    virus_t * virus = virus_create("kaboub", 0.5, 0.5);
    virus_display(virus);

    upgrade_t * upgrade = upgrade_create("phishing", 30.5, 0.2, 0.2);
    upgrade_display(upgrade);

    jeu_t *jeu= jeu_create(virus, 200.5);
    virus_display(jeu->virus);

    printf("Thunes : %f \n", jeu->btc);
    buy_upgrade(jeu, upgrade);

    virus_display(jeu->virus);
    printf("Thunes : %f \n", jeu->btc);


    return 0;
}
