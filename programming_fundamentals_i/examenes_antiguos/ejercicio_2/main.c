/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa:
 ******************************************************************************/
#include <stdio.h>
#define MENS_MAX_LEN 250

void rellena( char mens[], int F, int C, char mat[F][C]);

int main() {
    int F = 0, C = 0;

    do {
        printf("Indica numero de filas: ");
        scanf("%d", &F);
    } while ( F <= 0 );

    do {
        printf("Indica numero de columnas: ");
        scanf("%d", &C);
    } while ( C <= 0 );

    char mens[F*C];
    char mat[F][C];
    printf("Indica el mensaje: ");
    fflush(stdin);
    gets(mens);
    rellena(mens, F, C, mat);

    for ( int i = 0; i < F; i++ ) {
        for (int j = 0; j < C; j++) {
            fflush(stdin);
            printf("%c ", mat[j][i]);
        }
    }
    return 0;
}

void rellena( char mens[], int F, int C, char mat[F][C]) {
    int i_fila, i_col = 0;

    for ( int i = 0; i < F*C; i++ ) {
        mat[i_fila][i_col] = mens[i];
        i_col++;
        if ( i_col == C ) {
            i_col = 0;
            i_fila++;
        }
    }
    if ( i_fila < F ) {
        for ( int i = i_fila; i < F; i++ ) {
            if ( i_col < C ) {
                for ( int j = i_col; j < C; j++ ) {
                    mat[i][j] = '.';
                }
            }
            i_fila++;
        }
    }
}
