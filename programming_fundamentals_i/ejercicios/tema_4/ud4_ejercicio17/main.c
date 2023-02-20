/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 11/10/2022
 * Programa: dado un valor x y una precisión n, calcular el valor e^x con esa
 *           precisión.
 *                  e^x = 1 + (x / 1!) + (x^2 / 2!) + (x^3 / 3!) + ...
 ******************************************************************************/
#include <stdio.h>

int main() {
    int i, x, num, n;
    long int fact = 1;
    float e = 1.0;

    printf("Calcular e^x dados el valor de x y una precision.\n\n");
    printf("Indica el valor de x: ");
    scanf("%d", &x);
    printf("Indica la precision: ");
    scanf("%d", &n);
    num = x;

    for ( i = 1; i <= n; i++ ) {
        fact = fact * i;
        e = e + ( num / (float)fact );
        num = num * x;
    }

    printf("El resultado es: %f", e);

    return 0;
}
