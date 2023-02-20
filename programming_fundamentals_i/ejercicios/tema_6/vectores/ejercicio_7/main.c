/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: crea una funcion que dado un vector de numeros obtenga la suma,
 *            la media, el valor minimo y el valor maximo de los componentes
 *            del vector.
 ******************************************************************************/
#include <stdio.h>
#include <limits.h>

#define MAX_V_LONG 50


int leerVector( int v[] );
void infoVector( int v[], int l, int *sum, float *med, int *min, int *max );


int main() {
    int vector[MAX_V_LONG], v_long, suma, min, max;
    float media;

    v_long = leerVector(vector);
    infoVector(vector, v_long, &suma, &media, &min, &max);

    printf("Informacion sobre los numeros del vector:\n");
    printf("\t-Suma: %d\n", suma);
    printf("\t-Media: %.2f\n", media);
    printf("\t-Valor minimo: %d\n", min);
    printf("\t-Valor maximo: %d\n", max);

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

void infoVector( int v[], int l, int *sum, float *med, int *min, int *max ) {
    *sum = 0, *med = 0, *min = INT_MAX, *max = INT_MIN;

    for ( int i = 0; i < l; i++ ) {
        *sum += v[i];

        if ( v[i] < *min ) *min = v[i];
        if ( v[i] > *max ) *max = v[i];
    }

    *med = (float)*sum / l;
}
