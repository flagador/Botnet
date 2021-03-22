#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../lib/virus.h"
#include "../lib/country_list.h"

int main()
{
    country_list_t * cl = creer_country_list();
    virus_t * v = virus_create("El virus", 1, 1);

    cl->liste[0]->compromised_pcs_cpt = 10;

    for(int i = 0; i < 1000; i++)
    {
        sleep(1);
        system("clear");
        afficher_country_list(cl);
        spread_world(v, cl); 
    }

    virus_destroy(&v);
    detruire_country_list(&cl); 
}