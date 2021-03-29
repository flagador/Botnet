#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/random_lib.h"
#include "../lib/country.h"

/**
 * \file country.c
 *  \brief Modèle de pays.
 *  \author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
*/

/**
 * \brief Créer un pays avec un nom, une puissance indicative (ordre d'idées du nombre de PCs dans le pays) et un identifiant
 * @param name {Nom du pays}
 * @param power_indicator {Puissance indicative -> permet de générer le nombre de PCs suivant une loi normale avec un delta de power_indicator * 100000}
 * @param id {identifiant du pays (numéro de ligne dans country.txt - 1)}
*/
extern country_t *creer_country(char *name, int power_indicator, int id)
{
	country_t *country = malloc(sizeof(country_t));

	country->name = malloc(30 * sizeof(char));

	strcpy(country->name, name);
	country->power_indicator = power_indicator;

	country->computers = malloc(sizeof(computer_list_t));

	country->identifiant = id;

	country->healthy_pcs_cpt = 0;
	country->compromised_pcs_cpt = 0;

	country->healthy_pcs_cpt = loi_normale_int(power_indicator * 100000, (power_indicator * 100000)/5);

	return country;
}


/**
 * @brief Destructeur de country
 * 
 * @param c {country à détruire}
 */
extern void detruire_country(country_t **c)
{
	free((*c)->name);
	free((*c)->computers);
	free((*c)->borders);
	free(*c);
	*c = NULL;
}

/**
 * @brief Affiche le pays au format "Nom : %s | PI : %i  | HP : %lu  | CP : %lu | ID : %i | BO : %i"
 * 
 * @param c 
 */
extern void afficher_country(country_t *c)
{
	printf("Nom : %s | PI : %i  | HP : %lu  | CP : %lu | ID : %i | BO : %i\n", c->name, c->power_indicator, c->healthy_pcs_cpt, c->compromised_pcs_cpt, c->identifiant, c->nb_borders);
	// if (c->nb_borders)
	// {
	// 	printf("Frontières : \n");
	// 	for (int i = 0; i < c->nb_borders; i++)
	// 	{
	// 		printf("%s\n", c->borders[i]->name);
	// 	}
	// }
}
/**
 * @brief Ajouter des frontières à un pays
 * 
 * @param c {Pointeur du pays auquel ajouter les frontières}
 * @param liste_border {Liste de pointeurs de pays (frontières)}
 * @param nb_borders {Nombre d'éléments de la précédente liste}
 */
extern void ajouter_borders(country_t *c, country_t **liste_border, int nb_borders)
{
	c->nb_borders = nb_borders;

	c->borders = malloc(sizeof(country_t *) * nb_borders);

	for (int i = 0; i < c->nb_borders; i++)
	{
		c->borders[i] = liste_border[i];
	}
}