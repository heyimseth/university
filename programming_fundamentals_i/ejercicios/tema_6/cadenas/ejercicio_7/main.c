/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que inserte una cadena dentro de otra a
 *            partir de la posicion p.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_L_CAD 150


// Inserta cad2 en cad1 a partir de la posicion p.
void insertarCadena( char cad1[MAX_L_CAD], char cad2[MAX_L_CAD], int p );


int main() {
    char cadena1[MAX_L_CAD], cadena2[MAX_L_CAD];
    int pos;

    printf("Indica una cadena (max. caracteres %d): ", MAX_L_CAD);
    gets(cadena1);
    printf("Indica otra cadena a insertar en la anterior: ");
    gets(cadena2);
    printf("Indica a partir de que posicion insertarla: ");
    scanf("%d", &pos);

    printf("\n\nCadena introducida: '%s'.\n", cadena1);
    printf("Cadena a introducir: '%s'.\n", cadena2);
    printf("Posicion en la que comenzar: %d.\n", pos);
    insertarCadena(cadena1, cadena2, pos);
    printf("Resultado: '%s'.\n", cadena1);

    return 0;
}


void insertarCadena( char cad1[MAX_L_CAD], char cad2[MAX_L_CAD], int p ) {
    int i = 0, lng = strlen(cad1);

    while ( p < lng && cad2[i] != '\0' ) {
        if ( p >= 0 ) {
            cad1[p] = cad2[i];
        }
        i++;
        p++;
    }

    if ( p == lng ) {
        cad1[p] = '\0';
    }
}
