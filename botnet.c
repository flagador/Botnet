#include <stdlib.h>
#include "country.h"

int main()
{
	country_t * test = creer_country_list();
    test->afficher(test);
    test->detruire(&test);
    return 0;
}
