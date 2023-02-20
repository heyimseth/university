/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: definir una estructura que permita representar numeros complejos,
 *            y realizar un programa que lea por telcado dos numeros complejos
 *            y calcule su suma y su resta.
 ******************************************************************************/
#include <stdio.h>

typedef struct {
    float real;
    float imaginaria;
} COMPLEJO;
typedef COMPLEJO t_complejo;


int main() {
    t_complejo num1, num2, suma, resta;

    printf("Numero complejo 1.\n");
    printf("\tIndica parte real: ");
    scanf("%f", &num1.real);
    printf("\tIndica parte imaginaria: ");
    scanf("%f", &num1.imaginaria);

    printf("Numero complejo 2.\n");
    printf("\tIndica parte real: ");
    scanf("%f", &num2.real);
    printf("\tIndica parte imaginaria: ");
    scanf("%f", &num2.imaginaria);

    suma.real = num1.real + num2.real;
    suma.imaginaria = num1.imaginaria + num2.imaginaria;

    resta.real = num1.real - num2.real;
    resta.imaginaria = num1.imaginaria - num2.imaginaria;

    printf("(%.2f+%.2fi) + (%.2f+%.2fi) = %.2f+%.2fi\n", num1.real,
           num1.imaginaria, num2.real, num2.imaginaria, suma.real,
           suma.imaginaria);
    printf("(%.2f+%.2fi) - (%.2f+%.2fi) = %.2f+%.2fi\n", num1.real,
           num1.imaginaria, num2.real, num2.imaginaria, resta.real,
           resta.imaginaria);

    return 0;
}
