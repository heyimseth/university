/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/10/2022
 * Programa: calcular las soluciones de una ecuación de segundo grado con
 *           coeficientes reales, pudiendo ser 0 cualquiera de ellos, y
 *           contemplando todos los casos posibles
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, rad;

    printf("Indica los valores de a, b y c separados por espacio: ");
    scanf("%f %f %f", &a, &b, &c);
    rad = (b*b) - (4*a*c);

    if ( a == 0 ) {
        printf("No es posible dividir entre 0.\n");
    } else if ( rad < 0 ) {
        printf("La ecuacion no tiene solucion.\n");
    } else if ( rad == 0 ) {
        printf("Solucion: %f", (-b)/4*a*c );
    } else {
        printf("Soluciones: %.3f, %.3f", ((-b)+sqrt(rad))/(2*a),
               ((-b)-sqrt(rad))/(2*a));
    }

    return 0;
}
