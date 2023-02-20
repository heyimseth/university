/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#define N 10
#define M 6

int Codifica( char m[N][M], char mens[] );

int main() {
    char matriz[N][M] = {
            {'E','J','E','M','P','L'},
            {'O',' ','Q','U','E',' '},
            {'I','L','U','S','T','R'},
            {'A',' ','E','L',' ','M'},
            {'E','T','O','D','O',' '},
            {'D','E',' ','C','I','F'},
            {'R','A','D','O',' ','P'},
            {'O','R',' ','T','R','A'},
            {'N','S','P','O','S','I'},
            {'C','I','O','N','&','&'}
    }, mens[N*M];
    int tam;

    tam = Codifica(matriz,mens);
    printf("Mensaje codificado: ");
    puts(mens);

    return 0;
}

int Codifica( char m[N][M], char mens[] ) {
    int i_mens = 0;

    for ( int c = 0; c < M; c++ ) {
        for ( int f = 0; f < N; f++ ) {
            mens[i_mens] = m[f][c];
            i_mens++;
        }
    }
    mens[i_mens] = '\0';

    return i_mens;
}
