#ifndef _COUNTRY_H_
#define _COUNTRY_H_

typedef struct 
{
	char * name;

	int power_indicator;

	int healthy_pcs_cpt;
	int compromised_pcs_cpt; 
} country_t ;

extern country_t * init_contries();
extern country_t * count_total_compromised_pcs(country_t * const country);
extern country_t * count_total_healthy_pcs(country_t * const country);

#endif