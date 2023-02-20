/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que elimine los espacios en blanco que haya
 *            al principio de una cadena.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_CAD 150


void eliminarEspaciosIniciales( char cadena[] );


int main() {
    char cadena[MAX_CAD];

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD);
    gets(cadena);

    printf("\nCadena introducida: '%s'\n", cadena);
    eliminarEspaciosIniciales(cadena);
    printf("Cadena sin espacios iniciales: '%s'\n", cadena);

    return 0;
}


void eliminarEspaciosIniciales( char cadena[] ) {
    int i = 0, lng = strlen(cadena);

    while ( cadena[i] == ' ' ) {
        i++;
    }

    for ( int j = 0; j < lng-i; j++ ) {
        cadena[j] = cadena[j+i];
    }
    cadena[lng-i] = '\0';
}
