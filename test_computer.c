#include <stdio.h>
#include "computer.h"

int
main()
{
    computer_t * computer = NULL;

    computer = computer_create(10,11, 0);
    printf("Poid Ordinateurs %d | Puissance Unitaire %d || Status %d\n",computer->weight ,computer->power, computer->status);
    computer->detruire(&computer);
}