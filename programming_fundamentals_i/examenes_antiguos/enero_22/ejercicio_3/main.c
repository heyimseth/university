/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define LIM_V 9

bool sumasIguales( const int v[], int *pos );

int main() {
    int pos, vector[LIM_V] = {1,4,5,8,4,3,1,8,3};

    if ( sumasIguales(vector,&pos) ) {
        printf("La suma a la izquierda de la posicion %d (incluido) es "
               "igual que la suma a la derecha.\n", pos);
    } else {
        printf("No se ha encontrado ninguna posicion.\n");
    }

    return 0;
}

bool sumasIguales( const int v[], int *pos ) {
    int i = 0, suma_i = 0, suma_d = 0;

    *pos = -1;
    while ( *pos == -1 && i < LIM_V ) {
        for ( int j = 0; j <= i; j++ ) {
            suma_i += v[j];
        }

        for ( int j = LIM_V-1; j > i; j-- ) {
            suma_d += v[j];
        }

        if ( suma_i == suma_d ) *pos = i;
        i++;
        suma_i = 0;
        suma_d = 0;
    }

    if ( *pos != -1 ) return true;

    return false;
}
