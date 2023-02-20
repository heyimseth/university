/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe una funcion que lea e imprima los datos de una matriz de
 *            dos dimensiones de un tamano fijo nxm. Tanto la lectura como la
 *            escritura se deben hacer con funciones. La funcion de lectura debe
 *            ir pidiendo los datos de cada fila.
 ******************************************************************************/
#include <stdio.h>

#define N 3
#define M 4


void leerVector( int vector[] );
void mostrarMatriz( int matriz[N][M] );


int main() {
    int matriz[N][M];

    for ( int i = 0; i < N; i++ ) {
        printf("Datos de la fila %d\n", i+1);
        leerVector(matriz[i]);
    }

    mostrarMatriz(matriz);

    return 0;
}


void leerVector( int vector[] ) {
    for ( int j = 0; j < M; j++ ) {
        printf("Columna %d: ", j+1);
        scanf("%d", &vector[j]);
    }
}

void mostrarMatriz( int matriz[N][M] ) {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
