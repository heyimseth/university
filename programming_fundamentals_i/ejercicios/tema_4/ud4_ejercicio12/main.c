/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/10/2022
 * Programa: procesar una secuencia de números calculando y visualizando
 *           el mayor, el menor y la media aritmética de N números enteros.
 *           Además, se calcula y visualiza la cantidad de números.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int num;
    int num_cantidad = 0, mayor = INT_MIN, menor = INT_MAX, suma = 0;
    bool salir = false;

    printf("Calcular el mayor, el menor, y la media aritmetica de los"
           " numeros introducidos por teclado, ademas de la cantidad.\n\n");

    do {
        printf("Indica un numero entero entre (o 0 para terminar): ");
        scanf("%d", &num);

        if ( num == 0 ) {
            salir = true;
        }
        else {
            num_cantidad++;
            suma = suma + num;
            if ( num > mayor ) {
                mayor = num;
            }
            if ( num < menor ) {
                menor = num;
            }
        }
    } while ( !salir );

    if ( num_cantidad > 0 ) {
        printf("\n\nSe han introducido %d numeros.\n", num_cantidad);
        printf("El mayor de ellos ha sido %d.\n", mayor);
        printf("El menor de ellos ha sido %d.\n", menor);
        printf("La media de todos ellos ha sido %f.\n\n",
               suma / (float)num_cantidad);
    }
    else {
        printf("No se han introducido numeros...\n\n");
    }
    return 0;
}
