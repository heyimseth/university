/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa: funcion que reciba una matriz bidimensional NxM de enteros, un
 *           vector de M enteros y una posicion, y devuelve la matriz en la que
 *           se ha insertado una fila completa, en una posicion determinada.
 *
 *           Funcion que desplaza las filas de una matriz hacia abajo una
 *           posicion desde una fila dada. La ultima fila de la matriz se pierde
 ******************************************************************************/
#include <stdio.h>
#define N 4
#define M 7

void insertar( int matriz[N][M], int vector[M], int fila );
void desplazar( int matriz[N][M], int fila );

int main() {
    int matriz[N][M], vector[M], posicion;

    printf("Indica los valores de la matriz.");
    for (int i = 0; i < N; i++ ) {
        fflush(stdin);
        printf("\nFila %d.\n", i);
        for ( int j = 0; j < M; j++ ) {
            printf("Columna %d: ", j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Indica los valores para la fila a insertar:\n");
    for ( int i = 0; i < M; i++ ) {
        printf("Valor %d: ", i);
        scanf("%d", &vector[i]);
    }

    printf("Indica la posicion en la que insertar la fila: ");
    scanf("%d", &posicion);

    insertar( matriz, vector, posicion );

    for ( int i = 0; i < N; i++ ) {
        for (int j = 0; j < M; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void insertar( int matriz[N][M], int vector[M], int fila ) {
    desplazar( matriz, fila );

    for ( int i = 0; i < M; i++ ) matriz[fila][i] = vector[i];
}

void desplazar( int matriz[N][M], int fila ) {
    for ( int i = N-1; i > fila; i-- )
        for ( int j = 0; j < M; j++ ) matriz[i][j] = matriz[i-1][j];
}
