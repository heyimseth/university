/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 05/11/2022
 * Programa: calcular x^n para x real y n entero.
 ******************************************************************************/
#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
    float x, res = 1;
    int n, i;

    printf("Indica un numero real: ");
    scanf("%f", &x);
    printf("Indica un numero entero: ");
    scanf("%d", &n);

    if ( log2(FLT_MAX) <= n ) {
        printf("[ERROR] Numero entero demasiado grande.\n\n");
        return 1;
    }

    for ( i = 1; i <= abs(n); i++ ) {
        res = res * x;
    }

    if ( n < 0 ) {
        res = 1 / res;
    }

    printf("El resultado de R^n es %.8G\n\n", res);

    return 0;
}
