/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa: funcion que reciba como argumento una frase (cadena de caracteres)
 *           y devuelva un valor entero que sea la longitud de la palabra mas
 *           larga de la frase, sabiendo que el espacio (' ') es el unico
 *           caracter separador de palabras.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#define F_MAX_LONG 50

int palabraMasLarga( char frase[] );

int main() {
    int longitud = 0;
    printf("Indica longitud de frase (por defecto %d): ", F_MAX_LONG);
    scanf("%d", &longitud);
    if ( longitud == 0 ) longitud = F_MAX_LONG;

    char frase[longitud];

    printf("Indica una frase: ");
    fflush(stdin);
    gets(frase);

    printf("La palabra mas larga de la frase tiene %d caracteres.\n",
           palabraMasLarga(frase));

    return 0;
}

int palabraMasLarga( char frase[] ) {
    int l_mayor = 0, l_actual = 0, i = 0;

    while ( frase[i] != '\0' ) {
        if ( frase[i] != ' ' && frase[i+1] != '\0' ) l_actual++;
        else {
            if ( frase[i+1] == '\0' ) l_actual++;
            if ( l_actual > l_mayor ) l_mayor = l_actual;
            l_actual = 0;
        }

        i++;
    }

    return l_mayor;
}
