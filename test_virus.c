#include "virus.h"
#include "country_list.h"
#include "stdio.h"
#include "time.h"

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int main()
{
    country_list_t * cl = creer_country_list();
    virus_t * v = virus_create("El virus", 1, 1);

    cl->liste[0]->compromised_pcs_cpt = 10;

    for(int i = 0; i < 70; i++)
    {
        delay(1);
        afficher_country(cl->liste[0]);
        spread_world(v, cl); 
    }

    virus_destroy(&v);
    detruire_country_list(&cl); 
}