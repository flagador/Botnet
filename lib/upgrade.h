/**
 * @file upgrade.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure upgrade_t et prototypes fonctions externes
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _UPGRADE_H_
#define _UPGRADE_H_

/**
 * @struct upgrade_t
 *  @brief Structure contenant un nom, prix, taux de recherche et de propagation
 * 
 */
typedef struct
{
	char *name;

	float price;
	float research_rate;
	float spreading_rate;
} upgrade_t ;

extern upgrade_t *upgrade_create(char name[], float price, float spr_rate, float rsch_rate);

extern void upgrade_edit(upgrade_t * u, char name[], float price, float spr_rate, float rsch_rate);
extern void upgrade_edit_name(upgrade_t * u, char * name);

extern void upgrade_display(upgrade_t *upgrade);
extern void upgrade_edit_price(upgrade_t * upgrade, float price);

extern void upgrade_destroy(upgrade_t ** upgrade);

#endif
