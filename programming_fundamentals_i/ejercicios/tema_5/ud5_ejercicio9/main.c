/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 18/10/2022
 * Programa: calcular la cantidad de dígitos de un número dado.
 ******************************************************************************/
#include <stdio.h>

void calcularDigitos(int n, int *dig) {
    do {
        n = n/10;
        *dig = *dig + 1;
    } while (n >= 1);
}

int main() {
    int num, dig = 0;

    printf("Indica un numero: ");
    scanf("%d", &num);

    calcularDigitos(num, &dig);
    printf("El numero %d tiene %d digitos.", num, dig);

    return 0;
}
