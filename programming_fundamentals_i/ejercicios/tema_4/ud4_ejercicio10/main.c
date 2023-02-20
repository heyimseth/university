/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 03/10/2022
 * Programa: calcular la división entera de dos números indicados por teclado.
 *           Solo se puede utilizar la resta.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num1, num2;
    int resultado = 0;
    printf("Indica dos numeros enteros separados por espacio ( ): ");
    scanf("%d %d", &num1, &num2);

    while ( num1 >= num2 ) {
        num1 = num1 - num2;
        resultado++;
    }

    printf("\n\nEl resultado es: %d", resultado);

    return 0;
}
