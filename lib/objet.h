#include "global.h"

typedef struct objet_s objet_t;
struct objet_s{
    void (*afficher)(objet_t *const obj);
    err_t (*detruire)(objet_t ** obj);
};

