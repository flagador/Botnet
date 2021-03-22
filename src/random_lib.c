#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../lib/random_lib.h"

extern void init_rand(){
    srand(time(0));
}

//Loi normale selon la boite de muller https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform
extern double loi_normale_CR(){ 
    double u1 = (double)rand() / (double)RAND_MAX ;
    double u2 = (double)rand() / (double)RAND_MAX ;
    
    return sqrt(-2*log(u1))*cos(2*M_PI*u2);

}

extern double loi_normale(double delta, double sigma){
    return loi_normale_CR() * sigma + delta;
}

extern int loi_normale_int(double delta, double sigma){
    return (int) (loi_normale_CR() * sigma + delta);
}

extern int test_bernoulli(double p)
{
    double r = (double)rand() / (double)RAND_MAX;
    return(r<p); 
}

extern int random_in(int a)
{
    return rand() % a; 
}