#ifndef _COMPUTER_LIST_H_
#define _COMPUTER_LIST_H_

#include "computer.h"

typedef struct computer_list_s{
    int nb;
    computer_t ** liste;
}computer_list_t;

extern int liste_existe(computer_list_t *const liste);
extern void liste_destroy(computer_list_t ** liste);
extern computer_list_t * liste_creer(const int nb);

#endif