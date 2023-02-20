/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 08/11/2022
 * Programa: calcular la factorización de un número.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

void factores( int num );
bool esPrimo( int num );

int main() {
    int num;

    printf("Indica un numero entero: ");
    scanf("%d", &num);

    factores(num);

    return 0;
}

void factores( int num ) {
    int i;

    if ( esPrimo(num) ) {
        printf("1 * %d", num);
    } else {
        printf("1");
        for ( i = 2; i <= num/2; i++ ) {
            if ( num % i == 0 ) {
                printf(" * %d", i);
            }
        }
        printf(" * %d", num);
    }
}

bool esPrimo( int num ) {
    int i;

    for ( i = 2; i < num; i++ ) {
        if ( num % i == 0 ) {
            return false;
        }
    }
    return true;
}
