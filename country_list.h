#define COUNTRY_NUMBER 17
#include "computer_list.h"

typedef struct country_list_s
{
	void(*afficher)(const struct country_list_s * c);
	void(*detruire)(struct country_list_s ** c);
	char * name;

	struct country_list_s * network_connections; 
	computer_list_t * computer_list_t; 

	int power_indicator; 
	int healthy_pcs_cpt;
	int compromised_pcs_cpt; 
} country_list_t ;


extern country_list_t * creer_country_list() ;