/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 28/10/2022
 * Programa: dado un número entero positivo, calcular su equivalente en base 2.
 ******************************************************************************/
#include <stdio.h>
#include <limits.h>
#include <math.h>

unsigned long int calcularBinario(int num) {
    unsigned long int n_binario = 0;
    int exp = 1;

    while ( num != 0 ) {
        n_binario = n_binario + ( (num % 2) * exp );
        num = num / 2;
        exp = exp*10;
    }

    return n_binario;
}

int main() {
    int num;
    double max_bits = log2(ULONG_MAX);
    printf("Indica un entero positivo para convertirlo a binario: ");
    scanf("%d", &num);

    if ( num / max_bits > max_bits ) {
        printf("El numero es demasiado grande, indica uno menor.\n\n");
        return 1;
    }

    printf("El equivalente binario a %d es %lu.\n", num,
           calcularBinario(num));
    return 0;
}
