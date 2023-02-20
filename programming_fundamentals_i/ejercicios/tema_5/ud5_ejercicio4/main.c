/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 08/11/2022
 * Programa: calcular el sumatorio de i, i=1, hasta n, para cualquier n>=1
 ******************************************************************************/
#include <stdio.h>

unsigned long long int sumatorio( int n ) {
    unsigned long long int suma = 0;
    int i;

    for ( i = 1; i <= n; i++ ) {
        suma += i;
    }

    return suma;
}

int main() {
    int n;

    printf("Indica el valor de n: ");
    scanf("%d", &n);

    printf("\nLa suma vale %llu.\n", sumatorio(n));
    return 0;
}
