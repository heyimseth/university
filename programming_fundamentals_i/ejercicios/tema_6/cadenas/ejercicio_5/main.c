/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que elimine de una cadena los n caracteres
 *            que aparezcan a partir de la posicion p.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_CAD 150


void eliminarCaracteres( char cadena[], int p, int q );


int main() {
    char cadena[MAX_CAD];
    int cant, pos;

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD);
    gets(cadena);
    printf("Indica posicion en la que empezar a eliminar caracteres: ");
    scanf("%d", &pos);
    printf("Indica cantidad de caracteres a eliminar: ");
    scanf("%d", &cant);

    printf("\n\nCadena introducida: '%s'.\n", cadena);
    eliminarCaracteres(cadena, pos, cant);
    printf("Cadena modificada: '%s'.\n", cadena);

    return 0;
}


void eliminarCaracteres( char cadena[], int p, int q ) {
    int lng = strlen(cadena);

    for ( int i = p+1; i <= p+q; i++ ) {
        cadena[i] = cadena[i+q];
    }

    for ( int i = p+q+1; i < lng-q; i++ ) {
        cadena[i] = cadena[i+q];
    }

    cadena[lng-q] = '\0';
}
