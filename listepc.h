#include "objet.h"

typedef struct liste_s{
    int nb;
    objet_t ** liste;
}liste_t;

extern int liste_existe(liste_t *const liste);
//static err_t liste_destroy(liste_t ** liste);
extern liste_t * liste_creer(const int nb);