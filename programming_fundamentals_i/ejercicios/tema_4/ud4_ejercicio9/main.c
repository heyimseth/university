/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 03/10/2022
 * Programa: mostrar por pantalla todos los números pares comprendidos entre
 *           1 y 50.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num = 1;

    printf("Numeros pares comprendidos entre 1 y 50:\n\n");

    while ( num <= 50 ) {
        if ( num % 2 == 0 ) {
            printf("%d ", num);
        }
        num++;
    }

    return 0;
}
