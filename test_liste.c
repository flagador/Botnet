#include <stdio.h>

#include "computer_list.h"

int
main()
{
    computer_list_t * liste = NULL;
    
    computer_t * computer = computer_create(10,50,0);
    computer_t * computer_1 = computer_create(22,80,0);
    printf("%d ::: ", liste_existe(liste));
    liste = liste_creer(8);
    liste_elem_ecrire(liste ,computer,0);
    liste_elem_ecrire(liste ,computer_1,0);


    
    printf("%d ::: ", liste_existe(liste));
    //printf("Poid Ordinateurs %d | Puissance Unitaire %d || Status %d\n",computer->weight ,computer->power, computer->status);
    //computer->detruire(&computer);
}