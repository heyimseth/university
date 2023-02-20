/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/10/2022
 * Programa: calcular la serie
 *              h(n) = 1 + 1/2 + 1/3 + ... + 1/n
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", INT_MAX);
    int n_termino, i;
    float total_serie = 0;

    printf("Calcular el valor de la serie:\n\th(n) = 1 + 1/2 + 1/3 + ..."
           " + 1/n\n\n");
    printf("Indica el valor de n: ");
    scanf("%d", &n_termino);

    printf("%d", n_termino);

    for ( i = 1; i <= n_termino; i++ ) {
        total_serie = total_serie + (1.0 / i);
        if ( i >  2147483645 ) {
            printf("%d\n", i);
        }
    }

    printf("El valor de la serie es: %f", total_serie);

    return 0;
}
