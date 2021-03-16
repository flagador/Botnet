#ifndef _UPGRADE_H_
#define _UPGRADE_H_

typedef struct
{
	char *name;

	float price;
	float research_rate;
	float spreading_rate;
} upgrade_t ;

extern upgrade_t *upgrade_create(char name[], float price, float spr_rate, float rsch_rate);

#endif
