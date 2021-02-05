#include <stdlib.h>
#include "country_list.h"

int main()
{
	country_list_t * test = creer_country_list();
    test->afficher(test);
    test->detruire(&test);
    return 0;
}
