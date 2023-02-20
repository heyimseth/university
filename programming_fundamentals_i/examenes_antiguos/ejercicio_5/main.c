/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa: dada una matriz de NxM, devolver un vector de N elementos, donde
 *           cada elemento es la suma de los k elementos que contiene cada fila
 ******************************************************************************/
#include <stdio.h>
#define N 50
#define M 50

void suma(int matriz[N][M], int vector[N], int f, int c);

int main() {
    int f = 0, c = 0;
    do {
        printf("Indica numero de filas: ");
        scanf("%d", &f);
    } while ( f <= 0  || f > 50 );

    do {
        printf("Indica numero de columnas: ");
        scanf("%d", &c);
    } while ( c <= 0 || c > 50 );
    int matriz[f][c], vector[f];

    for ( int i = 0; i < f; i++ ) {
        printf("Indica valores para la fila %d:\n", i+1);
        for ( int j = 0; j < c; j++ ) {
            printf("Columna %d", j+1);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    suma(matriz, vector, f, c);

    return 0;
}

void suma( int matriz[N][M], int vector[N], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j <= f; j++ ) {
            if ( j < c ) {
                vector[i] += matriz[i][j];
            }
        }
    }
}
