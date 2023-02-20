/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 24/10/2022
 * Programa: dada una secuencia de números enteros acabada en 0, calcular la
 *           suma de aquellos que su número de cifras sea igual a la suma de las
 *           mismas.
 ******************************************************************************/
#include <stdio.h>

int contarDigitos( int num ) {
    int cuenta = 0;

    if ( num != 0 ) {
        while (num != 0) {
            num = num / 10;
            cuenta++;
        }
    } else {
        cuenta = 1;
    }
    return cuenta;
}

int sumarDigitos( int num ) {
    int suma_digitos = 0;

    while (num != 0) {
        suma_digitos = suma_digitos + (num % 10);
        num = num / 10;
    }
    return suma_digitos;
}

int calcularSuma() {
    int suma = 0;
    int num;

    do {
        printf("Indica un numero entero: ");
        scanf("%d", &num);

        if ( sumarDigitos(num) == contarDigitos(num) ) {
            suma = suma + num;
        }
    } while ( num != 0 );
    return suma;
}

int main() {
    printf("\n\nLa suma es: %d", calcularSuma());

    return 0;
}
