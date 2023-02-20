#include <stdio.h>

#define N 4
#define M 3


void leerMatriz( int m[N][M] );
void sumaColumnas( int m[N][M], int v[M] );


int main() {
    int matriz[N][M], suma[M];

    leerMatriz(matriz);
    sumaColumnas(matriz, suma);

    printf("Sumas de columnas:\n");
    for ( int i = 0; i < M; i++ ) {
        printf("\t-Columna %d: %d\n", i+1, suma[i]);
    }

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

void sumaColumnas( int m[N][M], int v[M] ) {
    for ( int c = 0; c < M; c++ ) {
        v[c] = 0;
        for ( int f = 0; f < N; f++ ) {
            v[c] += m[f][c];
        }
    }
}
