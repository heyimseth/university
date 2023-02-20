/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 18/10/2022
 * Programa: calcular si un número es primo o no.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int num) {
    int i;

    for ( i = 2; i < num; i++ ) {
        if ( num % i == 0 ) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    printf("Indica un numero para saber si es primo: ");
    scanf("%d", &num);

    if (esPrimo(num)) {
        printf("\nEl numero %d es primo.\n\n", num);
    } else {
        printf("\nEl numero %d no es primo.\n\n", num);
    }

    return 0;
}
