/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: dados dos vectores de caracteres A y B de dimension N, crea un
 *            nuevo vector C con todos los elementos de A que no esten en B.
 *            Suponemos que A y B estan ordenados.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define MAX_V_LONG 50


void leerVector( int v[], int l );
void mostrarVector( int v[], int l );
void ordenarVector( int v[], int l );
int diferenciaV1V2( int v1[], int v2[], int v3[], int l );


int main() {
    int v1[MAX_V_LONG], v2[MAX_V_LONG], v3[MAX_V_LONG], v_long = 0, v3_long;

    printf("Indica longitud del vector (o 0 para %d): ", MAX_V_LONG);
    scanf("%d", &v_long);
    if ( v_long == 0 ) v_long = MAX_V_LONG;

    printf("Indica datos del vector 1.\n");
    leerVector(v1, v_long);

    printf("Indica datos del vector 2.\n");
    leerVector(v2, v_long);

    ordenarVector(v1, v_long), ordenarVector(v2, v_long);

    v3_long = diferenciaV1V2(v1, v2, v3, v_long);
    mostrarVector(v3, v3_long);

    return 0;
}


void leerVector( int v[], int l ) {
    for ( int i = 0; i < l; i++ ) {
        printf("Indica el numero %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

void ordenarVector( int v[], int l ) {
    int aux;

    for ( int i = 1; i < l; i++ ) {
        for ( int j = i; j > 0; j-- ) {
            if ( v[j] < v[j-1] ) {
                aux = v[j-1], v[j-1] = v[j], v[j] = aux;
            }
        }
    }
}

void mostrarVector( int v[], int l ) {
    for ( int i = 0; i < l; i++ ) printf("%d ", v[i]);
}

int diferenciaV1V2( int v1[], int v2[], int v3[], int l ) {
    int pos = 0, j = 0;
    bool encontrado = false;

    for ( int i = 0; i < l; i++ ) {
        while ( !encontrado && j < l ) {
            if ( v1[i] == v2[j] ) {
                encontrado = true;
            }
            j++;
        }

        if ( !encontrado ) {
            v3[pos] = v1[i];
            pos++;
        }

        encontrado = false;
        j = 0;
    }

    return pos;
}