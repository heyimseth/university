/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que elimine los espacios en blanco que haya
 *            al final de una cadena.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_CAD 150


void eliminarEspaciosFinales( char cadena[] );


int main() {
    char cadena[MAX_CAD];

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD);
    gets(cadena);

    printf("Cadena introducida: %s.\n\n", cadena);
    eliminarEspaciosFinales(cadena);

    printf("Cadena sin espacios finales: %s.\n\n", cadena);

    return 0;
}


void eliminarEspaciosFinales( char cadena[] ) {
    int lng = strlen(cadena) - 1;

    while ( cadena[lng] == ' ' ) {
        lng--;
    }

    cadena[lng+1] = '\0';
}
