/*******************************************************************************
* Autor: Álvaro Martínez Alfaro
* Fecha: 10/10/2022
* Programa: dado un número entero positivo, indicar todos los números perfectos
*          entre 1 y el número dado.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, j, suma = 0;

    printf("%d", INT_MAX);

    printf("Indica un numero entero positivo: ");
    scanf("%d", &num);

    printf("Los numeros perfectos entre 1 y %d son: ", num);
    for ( i = 1; i < num; i++ ) {
        for ( j = 1; j < i; j++ ) {
            if (i % j == 0) {
                suma = suma + j;
            }
        }

        if ( suma == i ) {
            printf("%d ", i);
        }
        suma = 0;
    }

    return 0;
}
