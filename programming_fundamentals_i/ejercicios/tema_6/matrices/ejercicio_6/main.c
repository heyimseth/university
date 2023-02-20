/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe un programa que lea una matriz e imprima su traspuesta.
 *            Usar tambien un tamano maximo de 20 filas y columnas.
 ******************************************************************************/
#include <stdio.h>

#define MAX_LONG 20


void leerMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c );
void mostrarMatriz( int matriz[MAX_LONG][MAX_LONG], int f, int c );
void mostrarTraspuesta( int matriz[MAX_LONG][MAX_LONG], int f, int c );


int main() {
    int fil = 0, col = 0, matriz[MAX_LONG][MAX_LONG];

    while ( (fil <= 0 || col <= 0) || (fil > MAX_LONG || col > MAX_LONG) ) {
        printf("Indica cantidad de filas (max. %d): ", MAX_LONG);
        scanf("%d", &fil);
        printf("Indica cantidad de columnas (max. %d): ", MAX_LONG);
        scanf("%d", &col);

        if ( fil <= 0 || col <= 0 || fil > MAX_LONG || col > MAX_LONG ) {
            printf("[ERROR] Se debe indicar un numero de filas y columnas"
                   " comprendido entre 1 y %d.\n", MAX_LONG);
        }
    }

    leerMatriz(matriz, fil, col);
    printf("\n\nMatriz introducida:\n");
    mostrarMatriz(matriz, fil, col);
    printf("\nTraspuesta:\n");
    mostrarTraspuesta(matriz, fil, col);

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

void mostrarTraspuesta( int matriz[MAX_LONG][MAX_LONG], int f, int c ) {
    for ( int i = 0; i < c; i++ ) {
        for ( int j = 0; j < f; j++ ) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}
