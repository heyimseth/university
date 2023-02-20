/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: basandonos en el programa anterior, haz un programa que lea dos
 *            matrices de enteros, las sume, y muestre el resultado. El tamano
 *            maximo de cada matriz ha de ser 20.
 ******************************************************************************/
#include <stdio.h>

#define N 20
#define M 20


void leerMatriz( int matriz[N][M], int f, int c );
void mostrarMatriz( int matriz[N][M], int f, int c );
void sumarMatrices( int m1[N][M], int m2[N][M], int s[N][M], int f, int c );


int main() {
    int filas, cols;
    printf("Indica tamano matriz (nxm) menor que 20 (o mayor para 4x5): ");
    scanf("%dx%d", &filas, &cols);

    if ( filas*cols > 20 ) filas = 4, cols = 5;

    int matriz1[filas][cols], matriz2[filas][cols], suma[filas][cols];
    leerMatriz(matriz1, filas, cols);
    leerMatriz(matriz2, filas, cols);

    sumarMatrices(matriz1, matriz2, suma, filas, cols);
    mostrarMatriz(suma, filas, cols);

    return 0;
}


void leerMatriz( int matriz[N][M], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        printf("Datos de la fila %i.\n", i+1);
        for (int j = 0; j < c; j++) {
            printf("Columna %d: ", j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz( int matriz[N][M], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumarMatrices( int m1[N][M], int m2[N][M], int s[N][M], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            s[i][j] = m1[i][j] + m2[i][j];
        }
    }
}
