/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 03/11/2022
 * Programa: dado un número en formato fracción continua, calcular el real
 *           equivalente.
 ******************************************************************************/
#include <stdio.h>

int fraccionMixta( int *num, int den );
float fraccionContinua( int num, int den );

int main() {
    int num, den;
    int n;

    printf("Calcular el valor de una fraccion continua.\n");
    printf("Debes indicar un numero real en formato fraccionario.\n");

    do {
        printf("Indica el valor del numerador (entero positivo): ");
        scanf("%d", &num);
        printf("Indica el valor del denominador (entero positivo): ");
        scanf("%d", &den);
    } while( num <= 0 || den <= 0 );
    return 0;
}

/* Devuelve la fracción mixta equivalente a una fracción dada.
 * La parte entera se devuelve en parte_entera y el numerador lo modifica
 * mediante el puntero */
int fraccionMixta( int *num, int den ) {
    int parte_entera = *num / den;
    *num = *num % den;

    return parte_entera;
}

float fraccionContinua( int num, int den ) {
    float resultado = 0;
    int parte_entera = 0;

    while ( num != 1 ) {
        parte_entera = fraccionMixta( &num, den );
        resultado =
    }

    return resultado;
}
