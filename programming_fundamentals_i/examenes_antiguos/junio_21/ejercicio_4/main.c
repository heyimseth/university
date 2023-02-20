/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

void CuentaVocales( char vocales[], int tam, int cuenta[5] );

int main() {
    char vocales[50] = {'E','s','t','o',' ','e','s',
                        ' ','u','n','a',' ','p','r',
                        'u','e','b','a','\0',};
    int cuenta[5], tam = 19;

    CuentaVocales(vocales,tam,cuenta);

    for ( int i = 0; i < 5; i++ ) printf("%d ", cuenta[i]);
    return 0;
}

void CuentaVocales( char vocales[], int tam, int cuenta[5] ) {
    for ( int i = 0; i < 5; i++ ) cuenta[i] = 0;

    for ( int i = 0; i < tam; i++ ) {
        switch (toupper(vocales[i])) {
            case 'A':
                cuenta[0]++;
                break;
            case 'E':
                cuenta[1]++;
                break;
            case 'I':
                cuenta[2]++;
                break;
            case 'O':
                cuenta[3]++;
                break;
            case 'U':
                cuenta[4]++;
                break;
        }
    }
}
