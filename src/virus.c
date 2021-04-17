/**
 * @file virus.c
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Primitives sur l'objet virus_t, fonctions d'infections et de propagation du virus
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../lib/virus.h"
#include "../lib/random_lib.h"
#include "../lib/config.h"
/**
 * @brief Créer un objet virus_t
 * 
 * @param name 
 * @param spr_rate 
 * @param rsch_rate 
 * @return virus_t* 
 */
extern virus_t *virus_create(char name[], float spr_rate, float rsch_rate)
{
    virus_t *virus = malloc(sizeof(virus_t));

    virus->name = name;

    virus->spreading_rate = spr_rate;

    virus->research_rate = rsch_rate;

    init_rand();

    return (virus);
}

extern void save_virus(virus_t *virus){
    FILE *fichier;
	fichier = fopen("../datas/virusSAVE", "w");
	fprintf(fichier,"%f %f", virus->research_rate, virus->spreading_rate);
	fclose(fichier);
	printf("Sauvegarde du virus");
}

extern void load_virus(virus_t *virus){
    FILE *fichier;
	fichier = fopen("../datas/virusSAVE", "r");
	fscanf(fichier,"%f %f", &virus->research_rate, &virus->spreading_rate);
	fclose(fichier);
	printf("Chargement du virus");
}

/**
 * @brief Modifies le taux de recherche du virus
 * 
 * @param virus 
 * @param rsch_rate 
 */
extern void edit_rsch_rate(virus_t *virus, float rsch_rate)
{
    virus->research_rate = rsch_rate;
}

/**
 * @brief Modifies le taux de propagation du virus
 * 
 * @param virus 
 * @param spr_rate 
 */
extern void edit_spr_rate(virus_t *virus, float spr_rate)
{
    virus->spreading_rate = spr_rate;
}

/**
 * @brief Détruit un objet virus_t
 * 
 * @param virus 
 */
extern void virus_destroy(virus_t **virus)
{
    free((*virus));
    (*virus) = NULL;
}

/**
 * @brief Affiche un objet virus_t
 * 
 * @param virus 
 */
extern void virus_display(virus_t *virus)
{
    printf("Nom du virus : %s \n", virus->name);
    printf("Taux de propagation : %f \n", virus->spreading_rate);
    printf("Taux de recherche : %f \n", virus->research_rate);
}

/**
 * @brief Infecte des PCs dans un pays donné, en gérant les différents cas (HP < nb)
 * 
 * @param nb Nombre de PCs à infecter
 * @param c Pointeur du pays dans lesquels il faut infecter les PCs
 */
static void infect(unsigned long int nb, country_t *c)
{
    if (nb > c->healthy_pcs_cpt)
    {
        c->compromised_pcs_cpt += c->healthy_pcs_cpt;
        c->healthy_pcs_cpt = 0;
    }
    else
    {
        c->compromised_pcs_cpt += nb;
        c->healthy_pcs_cpt -= nb;
    }
}

/**
 * @brief Propage le virus dans un pays donné, en fonction du nombre de PCs compromis de ce dernier. Gère les fuites aux frontières aussi
 * 
 * @param virus Virus qui se propage
 * @param c Pays dans lequel le virus se propage
 */
static void spread_country(virus_t *virus, country_t *c)
{
    if (c->compromised_pcs_cpt > 0)
    {
        long int nouveaux_cas = loi_normale_int((c->compromised_pcs_cpt * BOTNET_EXPENSION_MEDIANE) * virus->spreading_rate, (c->compromised_pcs_cpt * BOTNET_EXPENSION_MEDIANE) * BOTNET_EXPENSION_ECART_TYPE);

        if (test_bernoulli(c->compromised_pcs_cpt / (c->healthy_pcs_cpt + c->compromised_pcs_cpt) * BOTNET_BORDER_LEAK))
        {
            int infected_country = random_in(c->nb_borders);
            printf("%s is infected !", c->borders[infected_country]->name);
            infect(5, c->borders[infected_country]);
        }
        infect(nouveaux_cas, c);
    }
}

/**
 * @brief Etendre le botnet au monde
 * 
 * @param virus Virus à étendre
 * @param cl Liste de pays dans lequel le virus s'étend
 */
extern void spread_world(virus_t *virus, country_list_t *cl) //propagation du virus
{
    for (int i = 0; i < cl->nb; i++)
    {
        spread_country(virus, cl->liste[i]);
    }
}
