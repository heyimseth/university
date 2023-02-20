/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 28/10/2022
 * Programa: calcular la expresión
 *              x + (n)/(x + (n-1)/(x + (n-2)/.../(x + 3/(x + 2/x))))
 *           de forma recursiva y no recursiva.
 ******************************************************************************/
#include <stdio.h>

float noRecursiva( int x, int n );
float recursiva( int x, int n );

int main() {
    int x, n;
    printf("Indica el valor de x: ");
    scanf("%d", &x);
    printf("Indica el valor de n: ");
    scanf("%d", &n);

    printf("No recursiva: %f.\n", noRecursiva(x, n));
    printf("Recursiva: %f.\n", recursiva(x, n));

    return 0;
}

float noRecursiva( int x, int n ) {
    float total = x + (2.0/x);
    int i;

    for ( i = 3; i <= n; i++ ) {
        total = x + ( i / total );
    }

    return total;
}

float recursiva( int x, int n ) {
    if ( n == 2 ) {
        return x + ((float)n / x);
    }
    return x + ( n / recursiva( x, n-1 ));
}
