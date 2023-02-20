/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe un programa que elimine todos los espacios en blanco de
 *            una cadena, actuando sobre esa misma cadena (en caso de ser
 *            necesario, utiliza un tamano maximo de cadena).
 ******************************************************************************/
#include <stdio.h>

#define MAX_L_CAD 1000


void eliminarEspacios( char cadena[] );


int main() {
    char cadena[MAX_L_CAD];

    printf("Indica una cadena: ");
    gets(cadena);

    printf("\nCadena con espacios: '%s'.\n", cadena);
    eliminarEspacios(cadena);
    printf("Cadena sin espacios: '%s'.\n", cadena);

    return 0;
}


void eliminarEspacios( char cadena[] ) {
    int i = 0, j;

    while ( cadena[i] != '\0' ) {
        if ( cadena[i] == ' ' ) {
            j = i;
            while ( cadena[j+1] != '\0' ) {
                cadena[j] = cadena[j+1];
                j++;
            }
            cadena[j] = '\0';
        }
        i++;
    }
}
