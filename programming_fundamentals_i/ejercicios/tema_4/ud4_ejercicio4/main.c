#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float p, area;

    printf("Indica la longitud de los lados de un triangulo (separados"
           "por espacios): ");
    scanf("%d %d %d", &a, &b, &c);

    // Comprobar si están ordenados ascendentemente
    if ( a <= b && b <= c ) {
        printf("\nLos numeros han sido introducidos en orden numerico "
               "ascendente.\n\n");
    } else {
        printf("\nLos numeros no han sido introducidos en orden numerico "
               "ascendente.\n\n");
    }

    // Clasificar el triángulo que forman según su tipo
    if ( a == b && b == c ) {
        printf("El triangulo es equilatero.\n\n");
    } else if ( a == b && ( b > c || b < c ) ) {
        printf("El triangulo es isosceles.\n\n");
    } else {
        printf("El triangulo es escaleno.\n\n");
    }

    // Calcular el area del triangulo
    p = (a + b + c) / 2.0;
    if ( p < 0 ) {
        printf("No es posible calcular el area del triangulo.");
    } else {
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("El area del triangulo es: %.40f.\n", area);
    }

    return 0;
}
