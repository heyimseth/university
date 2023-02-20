/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/10/2022
 * Programa: calcular los cuatro primeros números deficientes mayores que un
 *           número dado.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num, i, count = 0, num_aux, suma_num_aux;

    printf("Indica un numero entero para calcular los primeros cuatro "
           "primeros numeros deficientes mayores que el: ");
    scanf("%d", &num);
    printf("Los cuatros primeros numeros mayores que %d son: ", num);
    num_aux = num;

    do {
        num_aux++;
        suma_num_aux = 0;
        // Calcular la suma de los divisores de num_aux
        for ( i = 1; i < num_aux; i++ ) {
            if ( num_aux % i == 0 ) {
                suma_num_aux = suma_num_aux + i;
            }
        }

        /* Cuando num_aux sea mayor que la suma de sus divisores (es deficiente)
         * mostrarlo por pantalla */
        if ( num_aux > suma_num_aux ) {
            printf("%d ", num_aux);
            count++;
        }
    } while ( count < 4 );

    return 0;
}
