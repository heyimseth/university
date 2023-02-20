/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 24/10/2022
 * Programa: dado un número, comprobar si es capicúa
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
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

bool esCapicua(int num) {
    int n_dig = 0, i, num_inv = 0, pot10;

    calcularDigitos(num, &n_dig);
    pot10 = pow(10, n_dig-1);

    for ( i = 1; i <= n_dig; i++ ) {
        num_inv = num_inv + (obtenerPosicion(num, i) * pot10);
        pot10 = pot10 / 10;
    }

    if ( num_inv == num ) {
        return true;
    }
    return false;
}

int main() {
    int num;

    printf("Indica un numero: ");
    scanf("%d", &num);

    if ( esCapicua(num) ) {
        printf("\n\nEl numero %d es capicua.\n", num);
    } else {
        printf("\n\nEl numero %d no es capicua.\n", num);
    }

    return 0;
}
