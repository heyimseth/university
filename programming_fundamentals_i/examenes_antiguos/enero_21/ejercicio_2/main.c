/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int cuenta[4] = {0,0,0,0};

    printf("Indica una frase terminada en (%): ");
    c = getchar();

    do {
        switch (toupper(c)) {
            case 'X':
                cuenta[0]++;
                break;
            case 'Y':
                cuenta[1]++;
                break;
            case 'G':
                cuenta[2]++;
                break;
            case 'J':
                cuenta[3]++;
                break;
        }

        c = getchar();
    } while ( c != '%' );

    printf("Apariciones de 'x', 'y', 'g' y 'j':\n");
    printf("\t-x: %d\n\t-y: %d\n\t-g: %d\n\t-j: %d", cuenta[0],
           cuenta[1], cuenta[2], cuenta[3]);

    return 0;
}
