/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 25/10/2022
 * Programa: calcular el MCD de dos números enteros utilizando el algoritmo de
 *           Euclides.
 ******************************************************************************/
#include <stdio.h>

int calcularMCD(int a, int b);

int main() {
    int num_a, num_b;

    printf("Indica un numero: ");
    scanf("%d", &num_a);
    printf("Indica otro numero: ");
    scanf("%d", &num_b);

    printf("El MCD entre %d y %d es %d.", num_a, num_b,
           calcularMCD(num_a, num_b));

    return 0;
}

int calcularMCD( int a, int b ) {
    int resto;

    resto = a % b;

    while ( resto != 0 ) {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}
