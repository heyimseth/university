/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que extraiga los n ultimos caracteres de
 *            una cadena.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_CAD 150

void extraerCaracteres( char cadena[], char nueva[], int q );


int main() {
    char cadena[MAX_CAD], nueva[MAX_CAD];
    int q;

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD);
    gets(cadena);

    printf("Indica cantidad de caracteres a extraer: ");
    scanf("%d", &q);

    extraerCaracteres(cadena, nueva, q);
    printf("Los ultimos %d caracteres de '%s' son: %s.\n", q, cadena, nueva);

    return 0;
}


void extraerCaracteres( char cadena[], char nueva[], int q ) {
    int lng = strlen(cadena);

    nueva[q] = '\0';
    if ( q > lng ) q = lng;

    for ( int i = 0; i < q; i++ ) {
        nueva[q-i-1] = cadena[lng-i-1];
    }
}
