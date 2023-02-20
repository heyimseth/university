/******************************************************************************+
 * Autor: Alvaro Martinez Alfaro
 * Programa:
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define V_MAX_LEN 35

bool sumaElementos( int vector[], int len, int *pos );

int main() {
    int len, pos = -1;

    printf("Indica cantidad de numeros (o 0 para %d): ", V_MAX_LEN);
    scanf("%d", &len);
    if ( len == 0 ) {
        len = V_MAX_LEN;
    }

    int vector[len];
    for ( int i = 0; i < len; i++ ) {
        printf("Indica numero %d", i+1);
        scanf("%d", &vector[i]);
    }

    if ( sumaElementos(vector, len, &pos) ) {
        printf("La suma de los elementos a la izquierda de %d y los de la"
               " derecha son iguales.\n", pos);
    } else {
        printf("No se ha encontrado una posicion coincidente.");
    }

    return 0;
}

bool sumaElementos( int vector[], int len, int *pos ) {
    int suma_izq = 0, suma_der = 0, i = 0, j = len-1;

    while ( i < len ) {
        suma_izq += vector[i];
        while ( j > i ) {
            suma_der += vector[j];
            j--;
        }
        if ( suma_der == suma_izq ) {
            *pos = i;
        }
        j = len-1;
        suma_der = 0;
        i++;
    }

    if ( *pos >= 0 ) {
        return true;
    } else {
        return false;
    }
}
