/**
 * @file country.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure country_s et prototypes fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _COUNTRY_H_
#define _COUNTRY_H_

#include "computer_list.h"
/**
 * @struct country_s
 * @brief Structure contenant une liste de frontières, un nombre de frontières, un nom, identifiant, une liste d'orfinateurs, un indictauer de puissance, un compteur de pc sains et de pc compromis
 * 
 */
typedef struct country_s {

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