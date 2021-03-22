#include <stdio.h>

#include "../lib/random_lib.h"

int main(){
    
    init_rand();

    printf("Loi normale classique :\n");
    for(int i = 0; i<10; i++){
        printf("%f\n", loi_normale_CR());
    }
    printf("Loi normale 10,5 :\n");
    for(int i = 0; i<10; i++){
        printf("%f\n", loi_normale((double) 10, (double) 5));
    }
    printf("Loi normale int 80 20:\n");
    for(int i = 0; i<10; i++){
        printf("%i\n", loi_normale_int((double) 80, (double) 20));
    }
}