/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: dada una secuencia de caracteres acabada en blanco y punto,
 *            construir un programa C que contabilice la cantidad de veces que
 *            aparece en el texto cada una de las letras, asi como el numero de
 *            caracteres de las diferentes palabras y la longitud media de
 *            palabra.
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

#define SEC_MAX_LONG 50


int main() {
    int cuentaLetras[26] = {0,0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,0,
                            0}, l_palabra = 0, total_palabras = 0, suma_letras = 0, i = 0;

    char secuencia[SEC_MAX_LONG], letra;

    printf("Indica una frase acabada en espacio y punto ( .) y maximo %d"
           " caracteres: ", SEC_MAX_LONG);
    gets(secuencia);

    while ( secuencia[i] != ' ' || secuencia[i+1] != '.' ) {
        letra = toupper(secuencia[i]);

        if ( letra >= 65 && letra <= 90 ) {
            cuentaLetras[letra-65]++;
            l_palabra++;
        }

        if ( secuencia[i+1] == ' ' ) {
            total_palabras++;
            suma_letras += l_palabra;
            l_palabra = 0;
        }

        i++;
    }

    printf("Letras y cantidad introducida:\n");
    for ( int j = 0; j < 26; j++ ) printf("%c - %d\n", j+65, cuentaLetras[j]);
    printf("Total palabras = %d\n", total_palabras);
    printf("Total letras = %d\n", suma_letras);
    printf("Media de letras por palabra = %.2f", (float)suma_letras / total_palabras);

    return 0;
}
