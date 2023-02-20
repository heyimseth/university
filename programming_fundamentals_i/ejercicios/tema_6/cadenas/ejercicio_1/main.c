/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: realiza un subprograma que extraiga los n primeros caracteres de
 *            una cadena.
 ******************************************************************************/
#include <stdio.h>

#define MAX_CAD 51


void extraerCaracteres( char cadena[MAX_CAD], char extraido[MAX_CAD], int cant );


int main() {
    char cadena[MAX_CAD], nueva[MAX_CAD];
    int q;

    printf("Indica una cadena (max. %d caracteres): ", MAX_CAD-1);
    gets(cadena);

    printf("Indica cuantos caracteres extraer de la cadena: ");
    scanf("%d", &q);

    extraerCaracteres( cadena, nueva, q );
    printf("%s", nueva);

    return 0;
}


void extraerCaracteres( char cadena[MAX_CAD], char extraido[MAX_CAD], int cant ) {
    int i = 0;

    while ( i < cant && cadena[i] != '\0' ) {
        extraido[i] = cadena[i];
        i++;
    }
    extraido[i] = '\0';
}
