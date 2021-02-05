#define COUNTRY_NUMBER 17


typedef struct country_s
{
	void(*afficher)(const struct country_s * c);
	void(*detruire)(struct country_s ** c);
	char * name;

	struct country_s * network_connections; 

	int power_indicator; 
	int healthy_pcs_cpt;
	int compromised_pcs_cpt; 
} country_t ;


extern country_t * creer_country_list() ;