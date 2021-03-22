#include <stdio.h>
#include <stdlib.h>
#include "../lib/country_list.h"

extern void afficher_country_list(const country_list_t *c)
{

	for (int i = 0; i < c->nb; i++)
	{
		afficher_country(c->liste[i]);
	}
}

extern void detruire_country_list(country_list_t **c)
{
	for (int i = 0; i < (*c)->nb; i++)
	{
		detruire_country(&(*c)->liste[i]);
	}
	free(*c);
	*c = NULL;
}

int compter_borders(int id_country)
{
	FILE *fichier;
	fichier = fopen("datas/borders", "r");

	int id_country_found, id_border;
	char tete;
	int cpt = 0;

	tete = fscanf(fichier, "%i :", &id_country_found);
	while (tete != EOF)
	{
		// printf("\nCountry found : %i", id_country_found);
		if (id_country_found != id_country)
		{
			do
			{
				fscanf(fichier, "%c", &tete);
				// printf("tete : %c", tete);
			} while (tete != '\n');
		}
		else
		{
			fscanf(fichier, "%i ", &id_border);
			// printf("coutryfound is good, border = %i\n", id_border);

			while (id_border != -1)
			{
				cpt++;
				fscanf(fichier, "%i ", &id_border);
			}
			return cpt;
		}
		tete = fscanf(fichier, "%i :", &id_country_found);
	}
}

void set_borders(country_list_t *c)
{
	FILE *fichier;
	fichier = fopen("datas/borders", "r");
	int border, country, tete, nb_borders, i;
	//pour tout le fichier
	tete = fscanf(fichier, "%i :", &country);
	while (tete != EOF)
	{

		//récupération du premier caractère de la première ligne
		nb_borders = compter_borders(country);

		//on crée un tableau de pointeurs vers les pays
		country_t *borders[nb_borders];

		i = 0;
		do
		{
			tete = fscanf(fichier, "%i", &border);
			if (border != -1)
			{
				borders[i] = c->liste[border];
				i++;
			}

		} while (border != -1 && tete != EOF);

		ajouter_borders(c->liste[country], borders, nb_borders);
		tete = fscanf(fichier, "%i :", &country);
	}
}

int compter_lignes(char *n_fichier)
{
	FILE *fichier;

	fichier = fopen(n_fichier, "r");

	int cpt = 0;
	int read;
	char tete;

	do
	{
		tete = fgetc(fichier);
		if (tete == '\n')
			cpt++;
	} while (!feof(fichier));

	return cpt;
}

extern country_list_t *creer_country_list()
{
	printf("Création de country list...\n");

	int country_nb = compter_lignes("./datas/countrylist") + 1;

	printf("Lignes comptées ! (%i)\n", country_nb);

	country_list_t *country_list = malloc(sizeof(country_list_t));

	country_list->liste = malloc(sizeof(country_t) * country_nb);

	FILE *fichier;

	fichier = fopen("./datas/countrylist", "r");

	int i = 0;
	int read;
	char name[30];
	int power_indicator;

	country_t *country;
	do
	{

		read = fscanf(fichier, "\n%[^,], %i", name, &power_indicator);

		country = creer_country(name, power_indicator, i);

		country_list->liste[i] = country;
		i++;

	} while (read != EOF);

	fclose(fichier);

	country_list->nb = country_nb;

	set_borders(country_list);

	return country_list;
}
