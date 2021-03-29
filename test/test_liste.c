#include <stdio.h>

#include "../lib/computer_list.h"

int
main()
{
    computer_list_t * liste = NULL;

    //element_t * element = NULL;
    computer_t * computer = NULL;
    //computer_t * x = NULL;

    liste = liste_creer();
    computer = computer_create(20,10,0);
    liste_elem_ecrire(liste , computer);
    computer = computer_create(30,10,0);
    liste_elem_ecrire(liste , computer);


    //computer = computer_create(30,20,0);
    //liste_elem_ecrire(liste , computer);
    //printf("Poid Ordinateurs %d | Puissance Unitaire %d || Status %d\n",computer->weight ,computer->power, computer->status);
    liste->detruire(&liste);

}