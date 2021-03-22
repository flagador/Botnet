/**
 * @file country_list.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure country_list_t et prototypes fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _COUNTRY_LIST_H_
#define _COUNTRY_LIST_H_

#include "country.h"

/**
 * @struct country_list_s
 * @brief Structure contenant un nombre de pays et une liste de country_s
 * 
 */
typedef struct country_list_s
{
	int nb;

	country_t** liste; 

} country_list_t ;

extern country_list_t * creer_country_list() ;
extern void afficher_country_list(const country_list_t * c);
extern void detruire_country_list(country_list_t ** c);
extern float count_compromised_pcs(country_list_t * list);
extern float count_healthy_pcs(country_list_t * list);
extern float compromised_healthy_proportion(country_list_t * list);


#endif