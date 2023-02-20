/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 25/10/2022
 * Programa: calcular la serie de Fibonacci en el término n.
 ******************************************************************************/
#include <stdio.h>

int fibo( int n ) {
    if ( n == 0 || n == 1 ) {
        return 1;
    }
    return fibo( n-1 ) + fibo( n-2 );
}

int main() {
    int n;

    printf("Indica el termino n para calcular la serie de Fibonacci: ");
    scanf("%d", &n);

    printf("\n\n%d", fibo(n));


    return 0;
}
