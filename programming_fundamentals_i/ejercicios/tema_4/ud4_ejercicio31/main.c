/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 08/11/2022
 * Programa: dada una secuencia de caracteres terminada en $, calcular el número
 *           de veces que aparece la palabra la en la misma.
 ******************************************************************************/
#include <stdio.h>

int main() {
    char c;
    int count = 0;

    printf("Indica una frase acabada en $: ");

    do {
        c = getchar();

        while ( c == 'l' ) {
            c = getchar();
            if ( c == 'a' ) {
                count++;
            }
        }
    } while ( c != '$' );

    printf("Se han encontrado %d veces 'la'.\n", count);
    return 0;
}
