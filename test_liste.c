#include <stdio.h>

#include "computer_list.h"

int
main()
{
    liste_t * liste = NULL;

    printf("%d ::: ", liste_existe(liste));

    liste = liste_creer(8);
    
    printf("%d ::: ", liste_existe(liste));
    //printf("Poid Ordinateurs %d | Puissance Unitaire %d || Status %d\n",computer->weight ,computer->power, computer->status);
    //computer->detruire(&computer);
}