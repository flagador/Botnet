#include "virus.h"
#include "country_list.h"
#include "stdio.h"
#include <unistd.h>

int main()
{
    country_list_t * cl = creer_country_list();
    virus_t * v = virus_create("El virus", 1, 1);

    cl->liste[0]->compromised_pcs_cpt = 10;

    for(int i = 0; i < 70; i++)
    {
        sleep(1);
        afficher_country(cl->liste[0]);
        spread_world(v, cl); 
    }

    virus_destroy(&v);
    detruire_country_list(&cl); 
}