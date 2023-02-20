#include <stdio.h>

int main() {
    int num1, num2;
    int sum, res, prod, rest;
    float div_e, div_real, avrg;

    printf("Bienvenido/a a \"Calculadora v1.0\".\n");
    printf("\n");
    printf("Introduce Primer operando:\t");
    scanf("%d", &num1);
    printf("Introduce Segundo operando:\t");
    scanf("%d", &num2);

    printf("\n...calculando resultados...\n");

    sum = num1 + num2;
    res = num1 - num2;
    prod = num1 * num2;
    div_e = num1 / num2;
    div_real = (float)num1 / num2;
    rest = num1 % num2;
    avrg = (float)(num1 + num2) / 2;

    printf("Suma:\t\t%d\n", sum);
    printf("Resta:\t\t%d\n", res);
    printf("Producto:\t\t%d\n", prod);
    printf("Division:\t\t%.2f\n", div_e);
    printf("Division real:\t\t%f\n", div_real);
    printf("Resto de la division:\t\t%d\n", rest);
    printf("Media de los numeros:\t\t%f\n", avrg);
    printf("Truncado de la media:\t\t%d\n", (int)avrg);
    printf("(%d + (2 x %d)) / 2:\t\t%f\n", num1, num2, (float)(num1+(2*num2))/2);
    printf("Porcentaje de %d: %.2f%%", num1, (float)num1 / 100);
    printf("\nBye\n");

    return 0;
}
