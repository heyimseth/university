/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#define N 7

int Cuantas_Veces_D( char m[N][N] );
int Cuantas_Veces_palabra( char m[N][N] );

int main() {
    char matriz[N][N] = {   // matriz de ejemplo modificada
            {'S','-','S','-','-','S','-'},
            {'-','O','O','O','O','-','O'},
            {'S','O','L','L','L','-','-'},
            {'S','O','L','O','S','-','-'},
            {'-','O','L','S','S','L','O'},
            {'L','S','O','L','O','O','L'},
            {'L','S','S','O','L','O','L'}
    };

    printf("Numero de veces SOL en diagonal principal: %d\n",
           Cuantas_Veces_D(matriz));
    printf("Numero de veces SOLO en horizontal: %d",
           Cuantas_Veces_palabra(matriz));

    return 0;
}

int Cuantas_Veces_D( char m[N][N] ) {
    int total = 0, dig = 0;

    for ( int i = 0; i < N; i++ ) {
        if ( (m[i][i] == 'O' && dig == 1) || (m[i][i] == 'L' && dig == 2) )
            dig++;
        else dig = 1;

        if ( dig == 3 ) {
            dig = 0;
            total++;
        }
    }

    return total;
}

int Cuantas_Veces_palabra( char m[N][N] ) {
    int total = 0, dig = 0;

    for ( int i = 0; i < N; i++ ) {
        for ( int j = 1; j < N; j++ ) {
            if ( (m[i][j] == 'O' && ((dig == 1 && m[i][j-1] == 'S') ||
                (dig == 3 && m[i][j-1] == 'L'))) || ( m[i][j] == 'L' && dig == 2 ) ) {
                dig++;
            } else {
                dig = 1;
            }

            if ( dig == 4 ) {
                total++;
            }
        }
    }

    return total;
}
