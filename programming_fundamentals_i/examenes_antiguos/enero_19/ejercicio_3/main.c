/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

int fact( int num );

int main() {
    double m, mr_pow = 1;
    int r, r_fact;

    printf("Indica el valor de m: ");
    scanf("%lf", &m);
    printf("Indica el valor de r: ");
    scanf("%d", &r);

    for ( int i = 0; i < r; i++ ) {
        mr_pow *= m;
    }

    r_fact = fact(r);

    printf("La probabilidad de que ocurra r veces es %f",
           (mr_pow/r_fact) * 1/exp(m));

    return 0;
}

int fact( int num ) {
    if ( num == 1 ) {
        return num;
    }
    return num * fact(num-1);
}
