/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: crea una funcion que obtenga la suma de los elementos de las
 *            diagonales de una matriz.
 ******************************************************************************/
#include <stdio.h>

#define N 4
#define M 5


void leerMatriz( int matriz[N][M] );
void mostrarMatriz( int matriz[N][M] );
int sumaDiagonales( int matriz[N][M] );


int main() {
    int matriz[N][M];

    leerMatriz( matriz );
    printf("\nMatriz introducida:\n");
    mostrarMatriz( matriz );
    printf("\nSuma de los elementos de sus diagonales: %d.\n",
           sumaDiagonales(matriz));

    return 0;
}


void leerMatriz( int matriz[N][M] ) {
    for ( int i = 0; i < N; i++ ) {
        printf("Datos sobre la fila %d.\n", i+1);
        for ( int j = 0; j < M; j++ ) {
            printf("\tColumna %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
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

int sumaDiagonales( int matriz[N][M] ) {
    int suma = 0;

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( i == j ) {
                suma += ( matriz[i][j] + matriz[i][M-j-1]);
            }
        }
    }

    return suma;
}
