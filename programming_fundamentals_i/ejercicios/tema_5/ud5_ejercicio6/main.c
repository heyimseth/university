/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 18/10/2022
 * Programa: leer números por teclado hasta introducir un número primo.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// Comprueba si el número indicado como parámetro es primo o no
bool esPrimo(int num) {
    int i;

    for ( i = 2; i < num; i++ ) {
        if ( num % i == 0 ) {
            return false;
        }
    }
    return true;
}

// Lee una cantidad indefinida de números
int leerNumeros() {
    int num;

    do {
        printf("\nIndica un numero: ");
        scanf("%d", &num);
    } while (!esPrimo(num));

    return num;
}

int main() {
    printf("El numero %d es primo.\n", leerNumeros());

    return 0;
}
