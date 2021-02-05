#include "computer.h"

typedef struct computer_list_s{
    int nb;
    computer_t ** liste;
}computer_list_t;

extern int liste_existe(computer_list_t *const liste);
//static err_t liste_destroy(liste_t ** liste);
extern computer_list_t * liste_creer(const int nb);