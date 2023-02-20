/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: implementa una funcion que reciba como parametro una cadena de
 *            caracteres, una posicion, y un numero de caracteres y devuelva una
 *            cadena de modo que empiece por esa posicion, y que tenga el numero
 *            de caracteres especificado.
 ******************************************************************************/
#include <stdio.h>

#define MAX_L_CAD 150


void extraerSubcadena( char cad[], char scad[], int p, int q );


int main() {
    char cadena[MAX_L_CAD], subcadena[MAX_L_CAD];
    int pos, cant;

    printf("Indica una cadena (max. %d caracteres): ", MAX_L_CAD);
    gets(cadena);
    printf("Indica posicion en la que comenzar: ");
    scanf("%d", &pos);
    printf("Indica cantidad de caracteres a extraer: ");
    scanf("%d", &cant);

    printf("\nCadena introducida: '%s'.\n", cadena);
    extraerSubcadena(cadena, subcadena, pos, cant);
    printf("Subcadena: '%s'.\n", subcadena);

    return 0;
}


void extraerSubcadena( char cad[], char scad[], int p, int q ) {
    int ind = 0, p_c = p;

    if ( p_c < 0 ) {
        p_c -= p_c;
    }

    while ( p_c < (p+q) && cad[p_c] != '\0' ) {
        if ( p_c >= 0 ) {
            scad[ind] = cad[p_c];
            ind++;
        }
        p_c++;
    }

    scad[ind] = '\0';
}
