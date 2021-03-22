#ifndef _VIRUS_H_
#define _VIRUS_H_

#include "country_list.h"

typedef struct
{
	char *name;

	float spreading_rate;
	float research_rate;
} virus_t ;

extern virus_t * virus_create(char name[], float spr_rate, float rsch_rate);
extern void edit_rsch_rate(virus_t * virus, float rsch_rate);
 void edit_spr_rate(virus_t * virus, float spr_rate);
extern void virus_destroy(virus_t **virus);
extern void virus_display(virus_t *virus);
static void infect(unsigned long int nb, country_t *c);
extern void spread_world(virus_t * virus, country_list_t * cl);

#endif

