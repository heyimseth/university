/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 23/09/2022
 * Programa: programa que dada una cantidad de dinero expresada en centimos, la
 *           exprese en billetes y monedas actuales de España.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int cantidad, resto;


    printf("\n\nExpresar una cantidad de centimos en billetes y "
           "monedas.\n\n");

    // Leer la cantidad de centimos a convertir
    printf("Indica una cantidad de centimos: ");
    scanf("%d", &cantidad);

    // Conversion y expresion de la cantidad en billetes
    printf("\n\nBillete\t\tCantidad\n");
    printf("------------------------\n");

    // Calculo para billetes de 500 Eur
    printf("500 Eur\t\t%d\n", cantidad / 50000);
    resto = cantidad % 50000;

    // Calculo para billetes de 200 Eur
    printf("200 Eur\t\t%d\n", resto / 20000);
    resto = resto % 20000;

    // Calculo para billetes de 100 Eur
    printf("100 Eur\t\t%d\n", resto / 10000);
    resto = resto % 10000;

    // Calculo para billetes de 50 Eur
    printf("50 Eur\t\t%d\n", resto / 5000);
    resto = resto % 5000;

    // Calculo para billetes de 20 Eur
    printf("20 Eur\t\t%d\n", resto / 2000);
    resto = resto % 2000;

    // Calculo para billetes de 10 Eur
    printf("10 Eur\t\t%d\n", resto / 1000);
    resto = resto % 1000;

    // Calculo para billetes de 5 Eur
    printf("5 Eur\t\t%d\n", resto / 500);
    resto = resto % 500;


    // Conversion y expresion de la cantidad restante en monedas
    printf("\n\nMonedas\t\tCantidad\n");
    printf("------------------------\n");

    // Calculo para monedas de 2 Eur
    printf("2 Eur\t\t%d\n", resto / 200);
    resto = resto % 200;

    // Calculo para monedas de 1 Eur
    printf("1 Eur\t\t%d\n", resto / 100);
    resto = resto % 100;

    // Calculo para monedas de 50 Cents
    printf("50 Cts\t\t%d\n", resto / 50);
    resto = resto % 50;

    // Calculo para monedas de 20 Cents
    printf("20 Cts\t\t%d\n", resto / 20);
    resto = resto % 20;

    // Calculo para monedas de 10 Cents
    printf("10 Cts\t\t%d\n", resto / 10);
    resto = resto % 10;

    // Calculo para monedas de 5 Cents
    printf("5 Cts\t\t%d\n", resto / 5);
    resto = resto % 5;

    // Calculo para monedas de 2 Cents
    printf("2 Cts\t\t%d\n", resto / 2);
    resto = resto % 2;

    // Calculo para monedas de 1 Cents
    printf("1 Cts\t\t%d\n", resto / 1);

    return 0;
}
