/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: dada una matriz de enteros de dimension NxM, disena un algoritmo
 *            que indique la posicion de todos aquellos elementos que sean a su
 *            vez maximos de su fila y minimos de su columna.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define N 4
#define M 5


void leerMatriz( int matriz[N][M] );
void mostrarMatriz( int matriz[N][M] );
int maxFilaMinColumna( int matriz[N][M], int posiciones[N] );


int main() {
    int matriz[N][M], posiciones[N], q;

    leerMatriz( matriz );
    printf("\nMatriz introducida:\n");
    mostrarMatriz( matriz );
    q = maxFilaMinColumna( matriz, posiciones );

    if ( q != 0 ) {
        printf("\nLos elementos en las siguientes posiciones son maximos"
               " de su fila y minimos de su columna:\n");
        for ( int i = 0; i < N; i++ ) {
            if ( posiciones[i] != -1 ) {
                printf("\tFila %d, columna %d\n", i, posiciones[i]);
            }
        }
    } else {
        printf("\nNo se han encontrado elementos que sean maximos de su "
               "fila y minimos de su columna.\n");
    }

    return 0;
}


void leerMatriz( int matriz[N][M] ) {
    for ( int i = 0; i < N; i++ ) {
        printf("Datos de la fila %d.\n", i+1);
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

int maxFila( int fila[M], int *pos ) {
    int max = fila[0];
    *pos = 0;

    for ( int i = 1; i < M; i++ ) {
        if ( fila[i] > max ) {
            max = fila[i];
            *pos = i;
        }
    }

    return max;
}

int minColumna( int matriz[N][M], int col, int *pos ) {
    int menor = matriz[0][col];
    *pos = 0;

    for ( int i = 0; i < N; i++ ) {
        if ( matriz[i][col] < menor ) {
                menor = matriz[i][col];
                *pos = i;
        }
    }

    return menor;
}

int maxFilaMinColumna( int matriz[N][M], int posiciones[N] ) {
    int q = 0, j = 0, max, min, f, c;

    for ( int i = 0; i < N; i++ ) {
        posiciones[i] = -1;
        while ( j < M && posiciones[i] == -1 ) {
            max = maxFila( matriz[i], &c );
            min = minColumna( matriz, c, &f );

            if ( max == min && c == j && f == i ) {
                posiciones[i] = j;
                q++;
            }
            j++;
        }
        j = 0, f = -1, c = -1;
    }

    return q;
}
