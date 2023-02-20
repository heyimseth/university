/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: dada una matriz de nxn, construye un programa que realice sobre
 *            ella las rotaciones indicadas a continuacion:
 *
 *            a11 a12 a13 a14               a11 a12 a13 a14
 *            a21 a22 a23 a24      -->      a24 a21 a22 a23
 *            a31 a32 a33 a34               a33 a34 a31 a32
 *            a41 a42 a43 a44               a42 a43 a44 a41
 ******************************************************************************/
#include <stdio.h>

#define N 4


void leerMatriz( int matriz[N][N] );
void mostrarMatriz( int matriz[N][N] );
void rotacion( int matriz[N][N] );


int main() {
    int matriz[N][N];

    leerMatriz(matriz);
    printf("\nMatriz introducida:\n");
    mostrarMatriz(matriz);
    rotacion(matriz);
    printf("\nRotacion realizada:\n");
    mostrarMatriz(matriz);

    printf("Hello, World!\n");
    return 0;
}


void leerMatriz( int matriz[N][N] ) {
    for ( int i = 0; i < N; i++ ) {
        printf("Datos de la fila %d.\n", i+1);
        for ( int j = 0; j < N; j++ ) {
            printf("\tColumna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz( int matriz[N][N] ) {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void rotacion( int matriz[N][N] ) {
    int copia[N], j, k;

    for ( int i = 1; i < N; i++ ) {
        for ( j = 0; j < N; j++ ) {
            copia[j] = matriz[i][j];
        }

        k = i;
        j = 0;
        do {
            if ( k == 4 ) {
                k = 0;
            }
            matriz[i][k] = copia[j];
            k++, j++;
        } while ( k != i );
    }
}
