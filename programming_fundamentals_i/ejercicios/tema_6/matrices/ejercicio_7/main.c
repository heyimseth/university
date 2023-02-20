/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe una funcion que dada una matriz de a[n][m] devuelva la
 *            suma de todos sus elementos menos los de la diagonal principal.
 ******************************************************************************/
#include <stdio.h>
#define MAX_LONG 50


void leerMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c );
void mostrarMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c );
int sumaNoDiagonal( int matriz[MAX_LONG][MAX_LONG], int f, int c );


int main() {
    int fil, col, matriz[MAX_LONG][MAX_LONG];

    printf("Indicar tamano de matriz (nxm max. = %d).\n", MAX_LONG);
    do {
        printf("Indica numero de filas: ");
        scanf("%d", &fil);
        printf("Indica numero de columnas: ");
        scanf("%d", &col);

        if ( fil * col < 0 || fil * col > MAX_LONG ) {
            printf("[ERROR] %d*%d no debe superar %d.\n", fil, col,
                   MAX_LONG);
        }
    } while ( fil * col < 0 || fil * col > MAX_LONG);

    leerMatriz(matriz, fil, col);
    printf("\nMatriz introducida:\n");
    mostrarMatriz(matriz, fil, col);
    printf("\nSuma de todos los elementos menos los de la diagonal "
           "principal: %d.\n", sumaNoDiagonal(matriz, fil, col));

    return 0;
}


void leerMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        printf("Datos sobre la fila %d.\n", i+1);
        for ( int j = 0; j < c; j++ ) {
            printf("\tColumna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c ) {
    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaNoDiagonal( int matriz[MAX_LONG][MAX_LONG], int f, int c ) {
    int suma = 0;

    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            if ( i != j ) suma += matriz[i][j];
        }
    }

    return suma;
}
