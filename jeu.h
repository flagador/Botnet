#ifndef _JEU_H_
#define _JEU_H_
#include "virus.h"
#include "upgrade.h"



typedef struct
{
	virus_t *virus;
    float btc;
    float mining_rate;
} jeu_t ;

extern jeu_t * jeu_create(virus_t *virus, float btc);
extern void buy_upgrade(jeu_t *jeu, upgrade_t *upgrade);

#endif
