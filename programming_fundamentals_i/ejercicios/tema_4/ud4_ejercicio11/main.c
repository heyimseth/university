/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 05/11/2022
 * Programa: dado un número entero, calcular la potencia 2^numero.
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int exp = 1, res = 1, i;
    printf("Indica un numero entero: ");
    scanf("%d", &exp);

    if ( log2(INT_MAX) <= exp ) {
        printf("[ERROR] El numero es demasiado grande.\n\n");
        return 1;
    }

    for ( i = 1; i <= exp; i++ ) {
        res = res * 2;
    }

    printf("2^%d = %d\n", exp, res);

    return 0;
}
