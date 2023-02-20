/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe una funcion que dados dos vectores A y B de enteros, de
 *            longitud N, devuelva como salida el producto de las componentes
 *            de B para las que las correspondientes de A sean negativas.
 ******************************************************************************/
#include <stdio.h>

#define MAX_V_LONG 50


void leerVector( int v[], int l );
// void mostrarVector( int v[], int l );
int productoV1V2Negativas( int v1[], int v2[], int l );


int main() {
    int v1[MAX_V_LONG], v2[MAX_V_LONG],  v_long = 0, prod;

    printf("Indica longitud del vector (o 0 para %d): ", MAX_V_LONG);
    scanf("%d", &v_long);
    if ( v_long == 0 ) v_long = MAX_V_LONG;

    printf("Indica datos del vector 1.\n");
    leerVector(v1, v_long);

    printf("Indica datos del vector 2.\n");
    leerVector(v2, v_long);

    prod = productoV1V2Negativas(v1, v2, v_long);
    printf("El producto de las componentes del vector 2 cuyas correspon"
           "dientes del vector 1 son negativas es: %d", prod);

    return 0;
}


void leerVector( int v[], int l ) {
    for ( int i = 0; i < l; i++ ) {
        printf("Indica el numero %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

//void mostrarVector( int v[], int l ) {
//    for ( int i = 0; i < l; i++ ) printf("%d ", v[i]);
//}

int productoV1V2Negativas( int v1[], int v2[], int l ) {
    int pos = 0, prod = 1;

    for ( int i = 0; i < l; i++ ) {
        if ( v1[i] < 0 ) prod *= v2[i];
    }

    return prod;
}
