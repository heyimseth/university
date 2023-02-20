#include <stdio.h>
#define N 5
#define M 3

void SumaFilas( int m[N][M], int s[N] );

int main() {
    int matriz[N][M] = {
            {4,3,6},
            {6,8,1},
            {2,4,5},
            {9,1,2},
            {9,2,3}
    };
    int suma[N] = {0,0,0,0,0};

    SumaFilas(matriz, suma);

    for ( int i = 0; i < N;  i++ ) printf("%d ", suma[i]);

    return 0;
}

void SumaFilas( int m[N][M], int s[N] ) {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            s[i] += m[i][j];
        }
    }
}
