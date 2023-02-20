/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 21/10/2022
 * Programa: dado un número entero, calcular la suma de todos sus dígitos
 ******************************************************************************/
#include <stdio.h>

int sumarDigitos(int n) {
    int suma = 0;

    while ( n != 0 ) {
        suma = suma + (n % 10);
        n = n / 10;
    }

    return suma;
}

int main() {
    int num;

    printf("Indica un numero: ");
    scanf("%d", &num);

    printf("La suma de los digitos del numero %d es %d.", num,
           sumarDigitos(num));

    return 0;
}
