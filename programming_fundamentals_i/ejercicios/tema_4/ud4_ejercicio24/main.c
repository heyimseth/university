/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/11/2022
 * Programa: dada una secuencia de caracteres acabada en #, obtenga todos los
 *           números que en ella aparecen y calcule su suma.
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    float num = 0, suma = 0;
    int q = 10;

    printf("Indica una secuencia de caracteres acabada en #: ");

    do {
        c = getchar();
        while ( isdigit(c) ) {
            num = num + ( (c-48) / (float)q );
            c = getchar();
            if ( c == '.' ) {
                float dec = 0;
                int dec_pot = 10;
                c = getchar();

                while ( isdigit(c) ) {
                    dec = dec + (c-48)/(float)dec_pot;
                    dec_pot = dec_pot*10;
                    c = getchar();
                }

                suma = suma + dec;
            }
            q = q * 10;
        }
        suma = suma + (num * ((float)q/10));
        num = 0;
        q = 10;
    } while ( c != '#' );

    printf("\n\nSuma = %.2f", suma);

    return 0;
}
