/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 23/09/2022
 * Programa: programa que calcula y almacena en variables la suma, resta,
 *           multiplicacion, division y resto de dos numeros leidos por
 *           teclado.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num1, num2, suma, resta, producto, division, resto;

    printf("\n\nCalcular la suma, resta, multiplicacion, division y resto "
           "de los dos numeros indicados.\n\n");

    /* Lectura de datos */
    printf("Indica el primer numero: ");
    scanf("%d", &num1);
    printf("Indica el segundo numero: ");
    scanf("%d", &num2);

    /* Calculo y almacenamiento en variables */
    suma = num1 + num2;
    resta = num1 - num2;
    producto = num1 * num2;
    division = num1 / num2;
    resto = num1 % num2;

    /* Mostrar resultados por pantalla */
    printf("\n\n%d + %d = %d\n", num1, num2, suma);
    printf("%d - %d = %d\n", num1, num2, resta);
    printf("%d * %d = %d\n", num1, num2, producto);
    printf("%d / %d = %d\n", num1, num2, division);
    printf("Resto division: %d\n\n", resto);

    return 0;
}
