/**
 * @file jeu.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure jeu_t , prototypes de fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _JEU_H_
#define _JEU_H_
#include "virus.h"
#include "upgrade.h"


/**
 * @struct jeu_t
 * @brief Structure contenant un virus, une quantité de bitcoins et un taux de minage
 * 
 * 
 */
typedef struct
{
	virus_t *virus;
    float btc;
    float mining_rate;
} jeu_t ;

extern jeu_t * jeu_create(virus_t *virus, float btc);
extern void buy_upgrade(jeu_t *jeu, upgrade_t *upgrade);
extern void mine_btc_country(jeu_t *jeu, country_t * country);
extern void mine_btc_world(jeu_t *jeu, country_list_t *list);
extern int game_state(country_list_t * list, jeu_t *jeu);
#endif
