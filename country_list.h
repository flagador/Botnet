#ifndef _COUNTRY_LIST_H_
#define _COUNTRY_LIST_H_

#include "country.h"

typedef struct country_list_s
{
	int nb;

	country_t** liste; 

} country_list_t ;

extern country_list_t * creer_country_list() ;
extern void afficher_country_list(const country_list_t * c);
extern void detruire_country_list(country_list_t ** c);

#endif