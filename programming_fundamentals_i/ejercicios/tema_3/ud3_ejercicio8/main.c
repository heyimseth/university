/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 22/09/2022
 * Programa: resolver un sistema de ecuaciones del tipo:
 *              ax + by = c
 *              dx + ey = f
 *           utilizando las fórmulas:
 *              x = (ce - bf) / (bd - ae)
 *              y = (dc - af) / (bd - ae)
 ******************************************************************************/
 #include <stdio.h>

int main() {
    float a, b, c, d, e, f, x, y;
    printf("\n\nResolver sistemas de ecuaciones lineales del tipo:\n");
    printf("\t\tax + by = c\n\t\tdx + ey = f\n\n");

    printf("Indica los valores de a, b y c (separados por un espacio): ");
    scanf("%f %f %f", &a, &b, &c),

    printf("Indica los valores de d, e y f (separados por un espacio): ");
    scanf("%f %f %f", &d, &e, &f);

    if ( (b*d-a*e) != 0 ) {
        x = (c * e - b * f) / (b * d - a * e);
        y = (d * c - a * f) / (b * d - a * e);
        printf("\n\nx = %.2f\n", x);
        printf("y = %.2f\n", y);
    } else {
        printf("\nNo se puede dividir por 0.");
    }

    return 0;
}