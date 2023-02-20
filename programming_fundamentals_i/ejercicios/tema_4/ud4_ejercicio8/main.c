/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 04/10/2022
 * Programa: mostrar por pantalla las tablas de multiplicar usuales.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num1, num2;
    for (num1 = 0; num1 <= 10; num1++) {
        printf("\n\nTabla de multiplicar del %d\n", num1);
        printf("---------------------------\n");
        for (num2 = 0; num2 <= 10; num2++) {
            printf("%d x %d = %d\n", num1, num2, num1*num2);
        }
    }
    return 0;
}
