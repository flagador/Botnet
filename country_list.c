#include "country_list.h"
#include <stdio.h>
#include <stdlib.h>

//TODO : country connexions

static void afficher_country_list(const country_list_t * c){

	for(int i = 0; i<COUNTRY_NUMBER; i++){
		printf("Nom : %s | PI : %i  | HP : %i  | CP : %i |\n", (c+i)->name, c[i].power_indicator, c[i].healthy_pcs_cpt, c[i].compromised_pcs_cpt);
	}
}

extern void detruire_country_list(country_list_t ** c){
	for(int i = 0; i<COUNTRY_NUMBER; i++){
		free((*c)[i].name);		
	}
	free(*c);
	*c = NULL;
}

extern country_list_t * creer_country_list(){


	country_list_t * country_list = malloc(sizeof(country_list_t)*COUNTRY_NUMBER);

	FILE * fichier;

	fichier = fopen("./datas/countrylist", "r");

	for(int i=0; i<COUNTRY_NUMBER; i++){
		
		(country_list+i)->name = malloc(30*sizeof(char));

		fscanf(fichier, "\n%[^,], %i",(country_list+i)->name, &((country_list+i)->power_indicator));
		(country_list+i)->healthy_pcs_cpt = 0;
		(country_list+i)->healthy_pcs_cpt = 0;

	} 

	fclose(fichier);

	country_list->afficher = afficher_country_list; 
	country_list->detruire = detruire_country_list;

	return country_list;
}

