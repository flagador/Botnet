#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../lib/random_lib.h"

/**
 * \file random.c
 *  \brief Génération de nombre aléatoires adaptés au jeu (loi binomiale et normale)
 *  \author {Grégoire BELLON, Klemens Galus, Julian LEBOUC}
*/


extern void init_rand(){
    srand(time(0));
}

/**
 * @brief Loi normale centrée réduite selon la boite de muller https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform
 */
extern double loi_normale_CR(){ 
    double u1 = (double)rand() / (double)RAND_MAX ;
    double u2 = (double)rand() / (double)RAND_MAX ;
    
    return sqrt(-2*log(u1))*cos(2*M_PI*u2);

}

/**
 * @brief Extension de la fonction loi_normale_CR(), permettant un delta et un sigma
 * 
 * @param delta Moyenne
 * @param sigma Ecart type
 * @return double 
 */
extern double loi_normale(double delta, double sigma){
    return loi_normale_CR() * sigma + delta;
}

/**
 * @brief Extension de la fonction loi_normale() avec conversion en entier
 * 
 * @param delta Moyenne
 * @param sigma Ecart type
 * @return int 
 */
extern int loi_normale_int(double delta, double sigma){
    return (int) (loi_normale_CR() * sigma + delta);
}

/**
 * @brief Test de bernoulli
 * 
 * @param p Probabilité de l'évènement
 * @return int Booléen (échec ou succès)
 */
extern int test_bernoulli(double p)
{
    double r = (double)rand() / (double)RAND_MAX;
    return(r<p); 
}

/**
 * @brief Entier aléatoire, compris entre 0 et l'entier entré en paramètre (exclu)
 * 
 * @param a Borne (exclu)
 * @return int 
 */
extern int random_in(int a)
{
    return rand() % a; 
}