/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 20/10/2022
 * Programa: mostrar todos los números felices de dos cifras.
 *              203 es feliz porque 2^2+0^2+3^2=13; 1^2+3^2=10; 1^2+0^2=1;
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* Devuelve verdadero si el número indicado por parámetro es feliz, o falso en
 * caso contrario. Para ello, calcula la suma de sus dígitos al cuadrado. */
bool calcularFelicidad( int num ) {
    bool feliz = false;
    int suma = 0;

    do {
        suma = suma + pow(num%10, 2);
        num = num / 10;
    } while ( num >= 1 );

    if ( suma >= 10 ) {
        /* la función se llama a sí misma para comprobar si el resultado suma es
         * feliz, en el momento en que detecte un valor inferior a 10 y distinto
         * de 1, esta parte del código no se ejecutará, y el valor devuelto
         * "hacia arriba" por las distintas llamadas recursivas será falso */
        feliz = calcularFelicidad(suma);
    } else if ( suma == 1 ) {
        feliz = true;
    }

    return feliz;
}

int main() {
    int i;

    printf("Los numeros felices de dos cifras son:\n");

    // Los numeros van a ir del 1 al 99, pues se calculan los de dos cifras
    for ( i = 10; i <= 99; i++ ) {
        if ( calcularFelicidad(i) ) {
            printf("%d ", i);
        }
    }

    return 0;
}
