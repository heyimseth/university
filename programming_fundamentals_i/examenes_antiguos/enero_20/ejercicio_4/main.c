/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num, mul2 = 0, mul5 = 0, mul = 0, no_mul = 0;

    do {
        printf("Indica un numero: ");
        scanf("%d", &num);

        if ( num != -1 ) {
            if (num % 2 != 0 && num % 5 != 0) {
                no_mul++;
            } else if (num % 2 == 0 && num % 5 == 0) {
                mul2++;
                mul5++;
                mul++;
            } else if (num % 5 == 0) {
                mul5++;
            } else if (num % 2 == 0) {
                mul2++;
            }
        }
    } while ( num != -1 );

    printf("Se han indicado:\n");
    printf("\t%d multiplos de 2.\n", mul2);
    printf("\t%d multiplos de 5.\n", mul5);
    printf("\t%d multiplos de ambos.\n", mul);
    printf("\t%d que no eran multiplos de ninguno.\n", no_mul);

    return 0;
}
