#include "random_lib.h"
#include <stdio.h>

int main(){
    printf("Loi normale classique :\n");
    for(int i = 0; i<10; i++){
        printf("%f\n", loi_normale_CR());
    }
    printf("Loi normale 10,5 :\n");
    for(int i = 0; i<10; i++){
        printf("%f\n", loi_normale((double) 10, (double) 5));
    }
}