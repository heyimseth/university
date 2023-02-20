/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: implementa una funcion que lea una cadena de caracteres y un
 *            caracter, y devuelva la primera posicion en que aparece este en la
 *            cadena, o -1 si no aparece. Implementar un programa que use esta
 *            funcion.
 ******************************************************************************/
#include <stdio.h>

#define MAX_L_CAD 1000


int buscarCaracter( char t[], char c );


int main() {
    char texto[MAX_L_CAD], caracter;
    int posicion;

    printf("Indica un texto o cadena: ");
    gets(texto);
    printf("Indica un caracter a buscar: ");
    scanf("%c", &caracter);

    posicion = buscarCaracter( texto, caracter );
    if ( posicion != -1 ) {
        printf("La primera posicion en la que se ha encontrado '%c' ha"
               " sido en %d.\n", caracter, posicion);
    } else {
        printf("No se ha encontrado '%c' en '%s'.\n", caracter, texto);
    }

    return 0;
}


int buscarCaracter( char t[], char c ) {
    int i = 0, pos = -1;

    while ( t[i] != '\0' && pos == -1 ) {
        if ( t[i] == c ) {
            pos = i;
        }
        i++;
    }

    return pos;
}
