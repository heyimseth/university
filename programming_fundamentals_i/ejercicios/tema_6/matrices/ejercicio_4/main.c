/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: crea una funcion que dada una matriz de nxm devuelva un vector de
 *            tamano n donde esten los valores minimos de cada una de las filas.
 ******************************************************************************/
#include <stdio.h>

#define N 4
#define M 3


void leerMatriz( int m[N][M] );
void minimosFilas( int m[N][M], int v[N] );


int main() {
    int matriz[N][M], minimos[N];

    leerMatriz(matriz);
    minimosFilas(matriz, minimos);

    for ( int i = 0; i < N; i++ )
        printf("Min. Fila %d: %d\n", i, minimos[i]);

    return 0;
}


void leerMatriz( int m[N][M] ) {
    for ( int i = 0; i < N; i++ ) {
        printf("Datos de la fila %d.\n", i+1);
        for ( int j = 0; j < M; j++ ) {
            printf("\tIndica columna %d: ", j+1);
            scanf("%d", &m[i][j]);
        }
        printf("\n");
    }
}

void minimosFilas( int m[N][M], int v[N] ) {
    for ( int i = 0; i < N; i++ ) {
        v[i] = m[i][0];
        for ( int j = 1; j < M; j++ ) {
            if ( m[i][j] < v[i] ) {
                v[i] = m[i][j];
            }
        }
    }
}
