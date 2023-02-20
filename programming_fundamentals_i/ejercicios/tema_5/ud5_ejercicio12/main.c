/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 24/10/2022
 * Programa: dado un número entero positivo, invertirlo. (365 = 563)
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

void calcularDigitos(int n, int *dig) {
    do {
        n = n/10;
        *dig = *dig + 1;
    } while (n >= 1);
}

int obtenerPosicion(int num, int pos) {
    int i;

    if (num < 0) {
        num = -num;
    }
    for ( i = 1; i < pos; i++ ) {
        num = num / 10;
    }
    return num % 10;
}

int invertir(int num) {
    int n_dig = 0, i, num_inv = 0, pot10;

    calcularDigitos(num, &n_dig);
    pot10 = pow(10, n_dig-1);

    for ( i = 1; i <= n_dig; i++ ) {
        num_inv = num_inv + (obtenerPosicion(num, i) * pot10);
        pot10 = pot10 / 10;
    }

    return num_inv;
}

int main() {
    int num;

    do {
        printf("Indica un numero entero positivo: ");
        scanf("%d", &num);
    } while ( num < 0 );

    printf("El numero %d invertido es %d.\n\n", num, invertir(num));

    return 0;
}