/**
 * @file computer_list.h
 * @author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
 * @brief Définition structure computer_list_t et prototypes fonctions externes
 * @version 0.1
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _UPGRADE_LIST_H
#define _UPGRADE_LIST_H

#include "upgrade.h"
/**
 * @struct upgrade_list.h
 * @brief Structure comprenant un nombre d'upgrade et une liste de upgrade_s
 */
typedef struct upgrade_list_s{
    int nb;
    upgrade_t ** liste;
}upgrade_list_t;

extern int upgrade_liste_existe(upgrade_list_t *const liste);
extern int upgrade_liste_destroy(upgrade_list_t ** liste);

extern upgrade_list_t * upgrade_liste_charger(char * nom_file);
extern int upgrade_liste_sauv(upgrade_list_t *liste, char * path);


extern void afficher_upgrade_list(const upgrade_list_t * l);

extern upgrade_list_t * upgrade_liste_creer(const int nb);

#endif