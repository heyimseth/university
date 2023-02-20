/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/10/2022
 * Programa: indicar si un número introducido por teclado es deficiente o no.
 *           Un número deficiente es aquel que es mayor que la suma de sus
 *           divisores propios.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num, i, suma = 0;

    printf("Indica un numero entero para saber si es deficiente: ");
    scanf("%d", &num);

    // Comprobar cada numero hasta n-1 y si es un divisor de n, sumarlo a suma
    for ( i = 1; i < num; i++ ) {
        if ( num % i == 0 ) {
            suma = suma + i;
        }
    }

    if ( num > suma ) {
        printf("\n\nEl numero %d es deficiente.\n\n", num);
    } else {
        printf("\n\nEl numero %d no es deficiente.\n\n", num);
    }

    return 0;
}
