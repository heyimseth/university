/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 28/10/2022
 * Programa: dado un número en base 2, calcular su equivalente en base 10.
 ******************************************************************************/
#include <stdio.h>
#include <limits.h>

int calcularDecimal(unsigned long int num_b) {
    int num_d = 0;
    int exp = 1;

    while ( num_b != 0 ) {
        num_d = num_d + (( num_b % 10 ) * exp );
        num_b = num_b / 10;
        exp = exp * 2;
    }

    return num_d;
}

int main() {
    unsigned long int num_b;

    printf("Indica un numero binario para convertirlo a decimal: ");
    scanf("%lu", &num_b);

    if ( num_b == ULONG_MAX ) {
        printf("El numero es demasiado grande, indica uno menor.\n\n");
        return 1;
    }

    printf("El equivalente decimal a %lu es %d.\n\n", num_b,
           calcularDecimal(num_b));
    return 0;
}
