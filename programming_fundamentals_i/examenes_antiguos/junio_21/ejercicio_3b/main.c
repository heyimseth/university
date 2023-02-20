/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#define L_MAX 100

void ContarVocales( int v[5], const char cadena[] );

int main() {
    int tam = 0;
    printf("Indica longitud maxima de cadena (%d por defecto): ", L_MAX);
    scanf("%d", &tam);

    if ( tam == 0 ) {
        tam = L_MAX;
    }

    char cadena[tam], vocales[5] = {'a','e','i','o','u'};
    int num_vocales[5] = {0,0,0,0,0}, mayor = INT_MIN;

    printf("Indica la cadena, finalizada en punto (.): ");
    fflush(stdin);
    gets(cadena);

    ContarVocales( num_vocales, cadena );

    for ( int j = 0; j < 5; j++ ) {
        if ( num_vocales[j] > mayor ) mayor = j;
    }
    printf("Vocal mas introducida: %c - %d veces ", vocales[mayor],
           num_vocales[mayor]);

    return 0;
}

void ContarVocales( int v[5], const char cadena[] ) {
    int i = 0;
    char c;

    do {
        c = cadena[i];

        if ( c != '.' ) {
            switch (toupper(c)) {
                case 'A':
                    v[0]++;
                    break;
                case 'E':
                    v[1]++;
                    break;
                case 'I':
                    v[2]++;
                    break;
                case 'O':
                    v[3]++;
                    break;
                case 'U':
                    v[4]++;
                    break;
            }
        }
        i++;
    } while ( c != '.' && c != '\0' );
}