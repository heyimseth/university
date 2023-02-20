/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que obtenga una cadena cad2, de otra cad1,
 *            formada por los n caracteres de cad1, a partir de la posicion
 *            p de cad1.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_CAD 150


void extraerSubcadena( char cadena[], char subcadena[], int p, int n );


int main() {
    char cadena[MAX_CAD], subcadena[MAX_CAD];
    int pos, cant;

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD);
    gets(cadena);
    printf("Indica posicion en la que comenzar la subcadena: ");
    scanf("%d", &pos);
    printf("Indica cantidad de caracteres de la subcadena: ");
    scanf("%d", &cant);

    printf("\n\nCadena introducida: '%s'.\n", cadena);
    extraerSubcadena(cadena, subcadena, pos, cant);
    printf("Subcadena: '%s'.\n", subcadena);

    return 0;
}


void extraerSubcadena( char cadena[], char subcadena[], int p, int n ) {
    int q = 0;

    if ( p >= strlen(cadena) ) {
        return;
    }
    if ( p+n >= strlen(cadena) ) {
        n = strlen(cadena)-p-1;
        printf("%d", n);
    }


    for ( int i = p+1; i <= p+n; i++ ) {
        subcadena[q] = cadena[i];
        q++;
    }

    subcadena[q] = '\0';
}
