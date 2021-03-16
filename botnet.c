#include <stdlib.h>
#include <stdio.h>
#include "country_list.h"

int main()
{    
	country_list_t * test = creer_country_list();
    afficher_country_list(test);
    detruire_country_list(&test);
    return 0;
}
