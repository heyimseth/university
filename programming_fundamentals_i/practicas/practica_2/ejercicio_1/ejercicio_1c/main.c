/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 29/09/2022
 * Programa: calcular la potencia 2^n, donde n es el número indicado como
 *           entrada.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int exp, n;
    unsigned long p = 1;
    scanf("%d", &n);

    for ( exp = 1; exp <= n; exp++ ) {
        p = p * 2;
    }
    printf("%d ", p);

    return 0;
}
