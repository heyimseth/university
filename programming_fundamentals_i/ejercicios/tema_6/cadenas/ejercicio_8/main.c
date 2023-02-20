/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un programa que permita contar las veces que una
 *            determinada palabra aparece en un texto dado.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_L_CAD 2000


int contarPalabras( char texto[MAX_L_CAD], char palabra[] );


int main() {
    char text[MAX_L_CAD], palabra[MAX_L_CAD];

    printf("Indica un texto: ");
    gets(text);
    printf("Indica una palabra a buscar: ");
    gets(palabra);

    printf("La palabra '%s' se ha encontrado %d veces.\n", palabra,
           contarPalabras(text, palabra));

    return 0;
}


bool compararCadena( char palabra1[], char palabra2[] ) {
    bool coinciden = true;
    int ind = 0, lng1 = strlen(palabra1), lng2 = strlen(palabra2);

    if ( lng1 != lng2 ) {
        return false;
    }

    while ( coinciden && ind < lng1 ) {
        if ( palabra1[ind] != palabra2[ind] ) {
            coinciden = false;
        }
        ind++;
    }

    return coinciden;
}

int contarPalabras( char texto[MAX_L_CAD], char palabra[] ) {
    int ind = 0, j = 0, q = 0;
    char p_act[MAX_L_CAD];

    while ( texto[ind] != '\0' ) {
        while ( texto[ind] != ' ' ) {
            p_act[j] = texto[ind];
            ind++;
            j++;
        }
        p_act[j] = '\0';

        if (compararCadena(p_act, palabra) ) {
            q++;
        }
        j = 0;
        ind++;
    }

    return q;
}
