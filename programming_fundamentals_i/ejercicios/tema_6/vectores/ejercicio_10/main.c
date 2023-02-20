/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: haz un programa que, utilizando las funciones anteriores, lea un
 *            vector, lo imprima, lo invierta, e imprima el resultado.
 ******************************************************************************/
#include <stdio.h>

#define MAX_V_LONG 50


int leerVector( int v[] );
void mostrarVector( int v[], int l );
void invertirVector( int v[], int l );


int main() {
    int vector[MAX_V_LONG], v_long;

    v_long = leerVector(vector);
    printf("\nVector: ");
    mostrarVector(vector, v_long);
    invertirVector(vector, v_long);
    printf("\nVector invertido: ");
    mostrarVector(vector, v_long);

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

void mostrarVector( int v[], int l ) {
    for ( int i = 0; i < l; i++ ) printf("%d ", v[i]);
}

void invertirVector( int v[], int l ) {
    int aux;

    for ( int i = 0; i <= l/2-1; i++ ) {
        aux = v[i];
        v[i] = v[l-i-1];
        v[l-i-1] = aux;
    }
}
