/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: define una funcion que obtenga la suma de dos vectores y la
 *            devuelva en otro vector.
 ******************************************************************************/
#include <stdio.h>

#define MAX_V_LONG 50


int leerVector( int v[] );
void sumaVectores( int v1[], int l1, int v2[], int l2, int v3[], int mayor );


int main() {
    int v1[MAX_V_LONG], v2[MAX_V_LONG], v3[MAX_V_LONG*2], v_long1, v_long2, may;

    v_long1 = leerVector(v1);
    v_long2 = leerVector(v2);

    if ( v_long1 > v_long2 ) may = v_long1;
    else may = v_long2;

    sumaVectores(v1, v_long1, v2, v_long2, v3, may);

    printf("El vector suma es: ");
    for ( int i = 0; i < may; i++ ) printf("%d ", v3[i]);

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

void sumaVectores( int v1[], int l1, int v2[], int l2, int v3[], int mayor ) {
    for ( int i = 0; i < mayor; i++ ) {
        if ( i < l1 && i < l2 ) v3[i] = v1[i] + v2[i];
        else if ( i < l1 ) v3[i] = v1[i];
        else v3[i] = v2[i];
    }
}
