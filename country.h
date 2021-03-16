#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include "computer_list.h"

typedef struct country_s {

	computer_list_t * computer_list_t; 

    struct country_s** borders;

	int nb_borders;

    char * name;

    int identifiant;

	computer_list_t * computers; 

	int power_indicator;
	
	unsigned long int healthy_pcs_cpt;
	unsigned long int compromised_pcs_cpt;

} country_t;

extern country_t * creer_country(char * name, int power_indicator, int id);

extern void detruire_country(country_t **c);

extern void afficher_country(country_t * c);

extern void ajouter_borders(country_t * c, country_t ** liste_border, int nb_borders);

#endif