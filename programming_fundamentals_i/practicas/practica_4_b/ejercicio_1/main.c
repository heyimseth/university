/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 20/10/2022
 * Programa: calcular el seno de x, donde x se encuentra en el intervalo [0,3]
 *           y el número de términos n en el intervalo [1, 20].
 *              -Utilizar la función Math.sin(x)
 *              -Utilizar la serie:
 *        sen x = x - (x^3)/3! + (x^5)/5! - (x^7)/7! + ... + (x^2n+1)/(2n+1)!
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

double calcularFact(int num) {
    double fact = 1;
    int i;

    for ( i = num; i > 1; i-- ) {
        fact = fact * i;
    }
    return fact;
}

float calcularSeno(float x, int n) {
    float seno = x;
    int i;
    int par = 1;
    int den = 3;

    for ( i = 3; i <= 2*n+1; i++ ) {
        if ( par % 2 == 0 ) {
            seno = seno + ((pow(x,den) / calcularFact(den)));
        } else {
            seno = seno - ((pow(x,den) / calcularFact(den)));
        }
        den = den+2;
        par++;
    }

    return seno;
}

int main() {
    float x;
    int n;

    printf("\nCalcular el seno de x.\n\n");

    do {
        printf("Indica el valor de x (en el intervalo [0,3]): ");
        scanf("%f", &x);
    } while ( x < 0 || x > 3 );

    do {
        printf("Indica el valor de n: ");
        scanf("%d", &n);
    } while ( n < 0 || n > 20 );
    // Seno usando la función Math.sin()
    printf("Seno usando Math.sin() = %f\n", sin(x));
    // Seno usando la función calcularSeno()
    printf("Seno usando calcularSeno() = %f", calcularSeno(x, n));

    return 0;
}
