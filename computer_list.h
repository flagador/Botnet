#ifndef _COMPUTER_LIST_H_
#define _COMPUTER_LIST_H_

#include "computer.h"
typedef struct element_s element_t;
struct element_s{
    computer_t * computer;
    element_t * next;
    element_t * prev;
};

typedef struct computer_list_s computer_list_t;
struct computer_list_s{
    int (*detruire)(computer_list_t **);
    int nb;
    element_t * element;
};

extern int liste_existe(computer_list_t *const liste);
extern void liste_destroy(computer_list_t ** liste);
extern computer_list_t * liste_creer(const int nb);

#endif