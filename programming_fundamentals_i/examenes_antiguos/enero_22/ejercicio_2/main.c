/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>

unsigned long long int factorial( int num );

int main() {
    int n, m;

    printf("Indica el valor de n: ");
    scanf("%d", &n);
    printf("Indica el valor de m: ");
    scanf("%d", &m);

    printf("El numero combinatorio de m y n es: %.2f",
           factorial(m)/(float)(factorial(n)*(factorial(m-n))));

    return 0;
}

unsigned long long int factorial( int num ) {
    if ( num == 1 ) return num;

    return num * factorial(num-1);
}
