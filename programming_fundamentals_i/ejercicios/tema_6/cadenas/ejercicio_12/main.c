/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: construye un pequeno traductor de frases al latin. La forma de
 *            hacerlo sera:
 *                  -si una palabra acaba en consonante, se le anade "us".
 *                  -si una palabra acaba en vocal, se suprime la vocal
 *                   y se anade "us".
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_L_CAD 150


void traducir( char frase[] );


int main() {
    char f_traducir[MAX_L_CAD];

    printf("Indica una frase: ");
    gets(f_traducir);
    printf("\nFrase introducida: '%s'.\n", f_traducir);
    traducir(f_traducir);
    printf("Frase traducida: '%s'.\n", f_traducir);

    return 0;
}


void traducir( char frase[] ) {
    int i = 0;

    while ( frase[i] != '\0' ) {
        if ( frase[i+1] == ' ' || frase[i+1] == '\0' ) {
            if ( !(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' ||
                    frase[i] == 'o' || frase[i] == 'u') ) {
                for ( int j = strlen(frase)+1; j > i+1; j-- ) {
                    frase[j] = frase[j-2];
                }
                frase[i+1] = 'u', frase[i+2] = 's';
                i+=2;
            } else {
                for ( int j = strlen(frase)+1; j > i; j-- ) {
                    frase[j] = frase[j-1];
                }
                frase[i] = 'u', frase[i+1] = 's';
                i+=2;
            }
        }
        i++;
    }
}
