#include "country.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "random_lib.h"

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

extern void detruire_country(country_t **c)
{
	free((*c)->name);
	free((*c)->computers);
	free((*c)->borders);
	free(*c);
	*c = NULL;
}

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

extern void ajouter_borders(country_t *c, country_t **liste_border, int nb_borders)
{
	c->nb_borders = nb_borders;

	c->borders = malloc(sizeof(country_t *) * nb_borders);

	for (int i = 0; i < c->nb_borders; i++)
	{
		c->borders[i] = liste_border[i];
	}
}