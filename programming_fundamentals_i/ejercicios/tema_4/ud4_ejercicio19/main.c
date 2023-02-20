/*******************************************************************************
* Autor: Álvaro Martínez Alfaro
        * Fecha: 10/10/2022
* Programa: dado un número entero positivo, indicar si es perfecto o no.
******************************************************************************/
#include <stdio.h>

int main() {
    int num, i, suma = 0;

    printf("Indica un numero entero positivo: ");
    scanf("%d", &num);

    for ( i = 1; i < num; i++ ) {
        if ( num % i == 0 ) {
            suma = suma + i;
        }
    }

    if ( suma == num ) {
        printf("El numero %d es perfecto.", num);
    }
    else {
        printf("El numero %d no es perfecto.", num);
    }
    return 0;
}
