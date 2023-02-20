/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 04/10/2022
 * Programa: imprimir la lista visible de caracteres ASCII junto a su código
 *           ASCII correspondiente.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int i;

    printf("Imprimir la lista de caracteres ASCII imprimibles.\n\n");
    printf("Numero\t- Caracter ASCII\n");
    for (i = 33; i <= 127; i++) {
        printf("%d\t-\t%c\n", i, i);
    }
    return 0;
}
