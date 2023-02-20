/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

int main() {
    float x;

    do {
        printf("Indica el valor de x: ");
        scanf("%f", &x);

        if ( x != 0 ) {
            if (x < 2) {
                printf("f(x) = 2x^2 + 3x + 4\n");
                printf("f(%.3f) = %f\n\n", x, 2 * pow(x, 2) + 3 * x + 4);
            } else if (x > 2) {
                printf("f(x) = -2x^2 + 3x - 4\n");
                printf("f(%.3f) = %f\n\n", x, -2 * pow(x, 2) + 3 * x - 4);
            } else {
                printf("f(x) = 0\n");
                printf("f(%.3f) = 0\n\n", x);
            }
        }
    } while ( x != 0 );

    return 0;
}
