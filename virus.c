#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "virus.h"
#include "random_lib.h"

extern virus_t *virus_create(char name[], float spr_rate, float rsch_rate)
{
    virus_t *virus = malloc(sizeof(virus_t));

    virus->name = name;

    virus->spreading_rate = spr_rate;

    virus->research_rate = rsch_rate;

    init_rand();

    return (virus);
}

extern void edit_rsch_rate(virus_t *virus, float rsch_rate)
{
    virus->research_rate = rsch_rate;
}

extern void edit_spr_rate(virus_t *virus, float spr_rate)
{
    virus->spreading_rate = spr_rate;
}

extern void virus_destroy(virus_t **virus)
{
    free((*virus));
    (*virus) = NULL;
}

extern void virus_display(virus_t *virus)
{
    printf("Nom du virus : %s \n", virus->name);
    printf("Taux de propagation : %f \n", virus->spreading_rate);
    printf("Taux de recherche : %f \n", virus->research_rate);
}

static void spread_country(virus_t *virus, country_t *c)
{
    if (c->compromised_pcs_cpt > 0)
    {
        long int nouveaux_cas = loi_normale_int((c->compromised_pcs_cpt / 3) * virus->spreading_rate, (c->compromised_pcs_cpt / 3) / 5);

        if (nouveaux_cas > c->healthy_pcs_cpt)
        {
            c->compromised_pcs_cpt += c->healthy_pcs_cpt;
            c->healthy_pcs_cpt = 0;
        }
        else
        {
            c->compromised_pcs_cpt += nouveaux_cas;
            c->healthy_pcs_cpt -= nouveaux_cas;
        }
        
    }
}

extern void spread_world(virus_t *virus, country_list_t *cl) //propagation du virus
{
    for (int i = 0; i < cl->nb; i++)
    {
        spread_country(virus, cl->liste[i]);
    }
}
