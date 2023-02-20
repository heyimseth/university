/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/11/2022
 * Programa: calcular la raíz cuadrada de un número dado siguiendo el algoritmo:
 *                  -si N es una aproximación a la raíz cuadrada
 *                   N1 = (z/N + N)/2 es una mejor aproximación.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num;
    double n=1;

    printf("Indica un numero entero positivo para calcular su raiz "
           "cuadrada: ");
    scanf("%d", &num);

    if ( num < 0 ) {
        printf("\nNo existe la raiz de un numero negativo.\n\n");
        return 1;
    }

    do {
        n = ((num / n) + n)/2;
        printf("\nAproximacion actual: %.50f", n);
    } while ( n*n > num );

    printf("\n\nLa raiz cuadrada de %d es %.5f", num, n);
    return 0;
}
