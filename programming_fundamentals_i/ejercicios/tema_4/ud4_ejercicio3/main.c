/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 26/09/2022
 * Programa: dado el salario de una persona, se calcula su nuevo salario en
 *           función de los siguientes incrementos:
 *                  salario actual          incremento
 *                     0 a 9000                15%
 *                   9001 a 15000              10%
 *                  15000 a 20000               5%
 *                   más de 20000             1.5%
 ******************************************************************************/
 #include <stdio.h>

int main() {
    float salario_actual;

    printf("Calculadora de incremento de salario.\n\n");

    // Solicitar salario al usuario
    printf("Indica el salario actual del trabajador: ");
    scanf("%f", &salario_actual);

    // Calcular nuevo salario
    if ( salario_actual <= 9000 ) {
        printf("\n\nEl nuevo salario es de %.2f euros.\n",
               salario_actual * 1.15);
    } else if ( salario_actual <= 15000 ) {
        printf("\n\nEl nuevo salario es de %.2f euros.\n",
               salario_actual * 1.1);
    } else if ( salario_actual <= 20000 ) {
        printf("\n\nEl nuevo salario es de %.2f euros.\n",
               salario_actual * 1.05);
    } else {
        printf("\n\nEl nuevo salario es de %.2f euros.\n",
               salario_actual * 1.015);
    }

    return 0;
}
