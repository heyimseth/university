/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: crea una funcion que lea un vector y que devuelva la longitud del
 *            vector.
 ******************************************************************************/
#include <stdio.h>

#define MAX_V_LONG 50


int leerVector( int v[] );


int main() {
    int vector[MAX_V_LONG], v_long;

    v_long = leerVector(vector);
    printf("Se han introducido %d numeros.\n", v_long);

    return 0;
}


int leerVector( int v[] ) {
    int v_long = 0;

    printf("Indica longitud del vector (o 0 para %d): ", MAX_V_LONG);
    scanf("%d", &v_long);
    if ( v_long == 0 ) v_long = MAX_V_LONG;

    for ( int i = 0; i < v_long; i++ ) {
        printf("Indica el numero %d: ", i+1);
        scanf("%d", &v[i]);
    }

    return v_long;
}
