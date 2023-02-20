/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 04/10/2022
 * Programa: calcular la media de un conjunto de números en coma flotante.
 *           Se leerán números hasta que se introduzca un 0.
 ******************************************************************************/
#include <stdio.h>

int main() {
    float numero, suma = 0;
    int n = 0;

    printf("Calcular la media de los numeros decimales introducidos. "
           "Deben ser menores o iguales que 100.\n");
    do {
        printf("Por favor, introduce un numero (o 0 para parar): ");
        scanf("%f", &numero);
        if ( numero != 0 && numero <= 100 ) {
            n++;
            suma = suma + numero;
        }
    } while ( numero != 0 );

    if ( n > 0 ) {
        printf("\nLa media de los numeros introducidos es: %f", suma / n);
    } else {
        printf("\nDebes introducir algun numero...");
    }

    return 0;
}
