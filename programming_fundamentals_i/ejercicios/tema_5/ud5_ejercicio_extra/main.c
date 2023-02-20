/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 31/10/2022
 * Programa: función que lea números hasta introducir un 0, y devuelva la media
 *           de los números, el número de positivos, y el número de negativos
 *           introducidos.
 */
#include <stdio.h>

void leerNumeros( float *media, int *c_positivos, int *c_negativos );

int main() {
    float media = 0;
    int c_positivos = 0, c_negativos = 0;

    leerNumeros(&media, &c_positivos, &c_negativos);
    printf("La media es: %f\n", media);
    printf("Se han introducido %d positivos.\n", c_positivos);
    printf("Se han introducido %d negativos.\n", c_negativos);

    return 0;
}

void leerNumeros( float *media, int *c_positivos, int *c_negativos ) {
    int num;
    int suma = 0;

    do {
        printf("Indica un numero: ");
        scanf("%d", &num);

        if ( num != 0 ) {
            suma = suma + num;
            if ( num > 0 ) {
                (*c_positivos)++;
            } else {
                (*c_negativos)++;
            }
        }
    } while( num != 0 );
    *media = (float)suma / ( *c_positivos + *c_negativos );
}
