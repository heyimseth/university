/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 29/09/2022
 * Programa: resolver sistemas de ecuaciones del tipo
 *              ax + by = c
 *              dx + ey = f
 *
 *           donde
 *              y = (af - dc) / (ae - db)
 *              x = (c - by) / a
 *
 *           Si el cociente en y el denominador es 0, el cociente no tiene
 *           solución, y por tanto el sistema tampoco. Si el cociente es 0 / 0,
 *           el sistema tiene infinitas soluciones.
 ******************************************************************************/
#include <stdio.h>

int main() {
    float x, y, a, b, c, d, e, f, y_numerador, y_denominador;

    printf("\nCalcular un sistema de ecuaciones del tipo:\n");
    printf("\t\tax + by = c\n\t\tdx + ey = f\n\n");

    // Obtener los valores de a, b, c, d, e y f
    printf("Indica los valores de a, b y c (separados por un espacio): ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Indica los valores de d, e y f (separados por un espacio): ");
    scanf("%f %f %f", &d, &e, &f);

    // Calcular numerador y denominador
    y_numerador = a*f - d*c;
    y_denominador = a*e - d*b;

    if ( y_denominador == 0 && y_numerador == 0 ) {
        printf("\n\nEl sistema tiene infinitas soluciones.\n");
    } else if ( y_denominador == 0 ) {
        printf("\n\nEl sistema no tiene solucion.\n");
    } else {
        // Calcular valores de x e y, y mostrar resultado por pantalla
        y = y_numerador / y_denominador;
        printf("y = %.2f\n", y);

        // Si a == 0 no se puede calcular el cociente entre 0
        if ( a != 0 ) {
            x = (c - b*y) / a;
            printf("x = %.2f\n", x);
        } else {
            printf("x no tiene solucion, no se puede dividir por 0.\n");
        }
    }

    return 0;
}
