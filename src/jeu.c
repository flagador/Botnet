/**
 * @file jeu.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Permet de créer un jeu, de miner des bitcoins, acheter des upgrades
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/virus.h"
#include "../lib/upgrade.h"
#include "../lib/jeu.h"
#include "../lib/computer_list.h"
#include "../lib/country_list.h"


/**
 * @brief Créer un jeu_t avec le virus_t passé en paramètre et la somme de bitcoins de départ
 * 
 * @param vir 
 * @param btc 
 * @return jeu_t* 
 */
extern jeu_t *jeu_create(virus_t *vir, float btc)
{ //cr�� un jeu
    jeu_t *jeu = malloc(sizeof(jeu_t));

    jeu->virus = vir;

    jeu->btc = btc;

    jeu->mining_rate=0.5;

    return (jeu);
}

/**
 * @brief Permet l'achat d'un upgrade passé en paramètre, déduit son prix à notre argent
 * 
 * @param jeu 
 * @param upgrade 
 */
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

/**
 * @brief Primitive de modification du taux de minage
 * 
 * @param jeu 
 * @param rate 
 */
void edit_mining_rate(jeu_t * jeu, float rate){ // modifie le taux de minage
    jeu->mining_rate=rate;
}

/**
 * @brief Ajoute à notre argent la somme minée par les ordinateurs du pays passé en paramètre
 * 
 * @param jeu 
 * @param country 
 */
extern void mine_btc_country(jeu_t *jeu, country_t * country) // mine des bitcoins 
{   
    jeu->btc+= 0.01*country->power_indicator * country->compromised_pcs_cpt* jeu->mining_rate;
            
}

/**
 * @brief Execute la fonction mine_btc_country pour chaque pays le la liste de pays passée en paramètre
 * 
 * @param jeu 
 * @param list 
 */
extern void mine_btc_world(jeu_t *jeu, country_list_t * list){
    for(int i=0; i<list->nb; i++){
        mine_btc_country(jeu, list->liste[i]);
    } 
}

extern int game_state(country_list_t * list, jeu_t *jeu){ // vérifies si on a infecté 51% des ordinateurs du monde
    float healthy_pcs=0;
    float compromised_pcs=0;
    long double proportion;
    for(int i=0; i<list->nb; i++){
        healthy_pcs+=list->liste[i]->healthy_pcs_cpt;
        compromised_pcs+=list->liste[i]->compromised_pcs_cpt;
    }
    proportion= compromised_pcs/(compromised_pcs+healthy_pcs);
    printf("Pc infectes : %f Pc clean %f", compromised_pcs, healthy_pcs);
    printf("\n \n Proportion pc infectes %Lf \n \n", proportion);
    
    if(proportion>=0.51){
        return(1);
    } /*else if(){
        return(-1);
    }*/ else{
        return(0);
    }
}


