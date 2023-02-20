/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 17/11/2022
 * Programa: dada una cadena, devolver esa misma cadena eliminando caracteres
 *           en blanco.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR_MAX_LONG 51
#define ABC_LONG 57

// Elimina los espacios encontrados en la cadena indicada
void modificarCadena( char cadena[], int abc[] );

int main() {
    char cadena[STR_MAX_LONG];
    int abecedario[ABC_LONG], i;

    for ( i = 0; i < ABC_LONG; i++ ) {
        abecedario[i] = 0;
    }

    printf("Indica una cadena: ");
    gets(cadena);
    printf("Cadena antes de eliminado: ");
    puts(cadena);
    modificarCadena(cadena, abecedario);
    printf("\nCadena despues de eliminado: ");
    puts(cadena);

    for ( i = 0; i < ABC_LONG; i++ ) {
        if ( abecedario[i] != 0 ) {
            printf("Letra: %c - %d\n", i+65, abecedario[i]);
        }
    }

    return 0;
}

void modificarCadena( char cadena[], int abc[] ) {
    int i = 0, j;
    int longi = strlen(cadena);
    char letra;

    while ( cadena[i] != '\0' ) {
        if ( cadena[i] == ' ' ) {
            for ( j = i; j < longi; j++ ) {
                cadena[j] = cadena[j+1];
            }
            longi--;
        }
        if ( cadena[i] != ' ' ) {
            letra = cadena[i];
            abc[letra-65] = abc[letra-65] + 1;
        }
        i++;
    }
}
