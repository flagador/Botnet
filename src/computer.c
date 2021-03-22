#include <stdlib.h>
#include <string.h>
#include "../lib/computer.h"


extern int computer_exist( computer_t * const computer)
{
    if (computer == NULL)
        return 0;
    return 1;
}

static
int computer_destroy(computer_t ** computer)
{
    free(*computer);
    return 1;
}

extern 
computer_t * computer_create(int weight ,int power, int status)
{
    computer_t * computer = malloc(sizeof(computer_t));
    computer->detruire = computer_destroy;
    computer->weight = weight;
    computer->power = power;
    computer->status = status;

    return( computer );
}
