#include <stdio.h>
#include <stdlib.h>
#include "../lib/country_list.h"
#include "../lib/config.h"

/**
 * \file country_list.c
 *  \brief Liste de pays, et opérations (créateur, destructeur) qui y sont associés.
 *  \author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
*/

/**
 * @brief Affiche les pays au même format que country.afficher_country
 * 
 * @param c {Pointeur de liste de pays}
 */
extern void afficher_country_list(const country_list_t *c)
{

	for (int i = 0; i < c->nb; i++)
	{
		afficher_country(c->liste[i]);
	}
}

/**
 * @brief Destructeur de country_list
 * 
 * @param c {Pointeur de liste de pays}
 */
extern void detruire_country_list(country_list_t **c)
{
	for (int i = 0; i < (*c)->nb; i++)
	{
		detruire_country(&(*c)->liste[i]);
	}
	free(*c);
	*c = NULL;
}

//Compte les frontières grâce au fichier texte "borders"
int compter_borders(int id_country)
{
	FILE *fichier;
	fichier = fopen("../datas/borders", "r");

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

//initialise les borders de c grâce au fichier texte borders
void set_borders(country_list_t *c)
{
	FILE *fichier;
	fichier = fopen("../datas/borders", "r");
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


/**
 * @brief Créateur de la country_list, à partir du fichier data/countrylist
 * 
 * @return country_list_t* 
 */
extern country_list_t *creer_country_list()
{
	printf("Création de country list...\n");

	int country_nb = compter_lignes("../datas/countrylist") + 1;

	printf("Lignes comptées ! (%i)\n", country_nb);

	country_list_t *country_list = malloc(sizeof(country_list_t));

	country_list->liste = malloc(sizeof(country_t) * country_nb);

	FILE *fichier;

	fichier = fopen("../datas/countrylist", "r");

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

extern void save_country_list(country_list_t *cl){
	FILE *fichier;
	fichier = fopen("../datas/countrylistSAVE", "w");
	for(int i=0; i<cl->nb; i++){
		fprintf(fichier,"%lu %lu \n", cl->liste[i]->healthy_pcs_cpt,cl->liste[i]->compromised_pcs_cpt);
	}
	fclose(fichier);
	printf("Sauvegarde de la country list");
}

extern void load_country_list(country_list_t *cl){
	FILE *fichier;
	fichier = fopen("../datas/countrylistSAVE", "r");
	int read;
	int i=0;
	do
	{

		read = fscanf(fichier, "%lu %lu \n", &cl->liste[i]->healthy_pcs_cpt, &cl->liste[i]->compromised_pcs_cpt);
		i++;

	} while (read != EOF);
	fclose(fichier);
}


extern float count_compromised_pcs(country_list_t * list){
    float compromised_pcs=0;
    for(int i=0; i<list->nb; i++){
        compromised_pcs+=list->liste[i]->compromised_pcs_cpt;
    }
	return compromised_pcs;
}

extern float count_healthy_pcs(country_list_t * list){
    float healthy_pcs=0;
    for(int i=0; i<list->nb; i++){
        healthy_pcs+=list->liste[i]->healthy_pcs_cpt;
    }
	return healthy_pcs;
}

extern float compromised_healthy_proportion(country_list_t * list){
	float cp_pcs = count_compromised_pcs(list);
	float ht_pcs = count_healthy_pcs(list);
	return(cp_pcs/(cp_pcs+ht_pcs));
}