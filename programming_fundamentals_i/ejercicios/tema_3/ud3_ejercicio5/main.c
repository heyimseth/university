/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 23/09/2022
 * Programa: convertir una medida dada en pies a sus equivalente en
 *                  A) yardas
 *                  B) pulgadas
 *                  C) centimetros
 *                  D) metros
 *           teniendo en cuenta que
 *                  -12 pulgadas = 1 pie
 *                  -1 yarda = 3 pies
 *                  -1 pulgada = 2,54 cm
 *                  -1 m = 100 cm
 *           Leer el numero en pies e imprimir las conversiones
 ******************************************************************************/
#include <stdio.h>

int main() {
    float pies, pulgadas, yardas, centimetros, metros;

    printf("\n\nConversion de pies a yardas, pulgadas, centimetros y "
           "metros.\n\n");

    // Obtener la medida en pies
    printf("Indica una medida en pies: ");
    scanf("%f", &pies);

    // Conversion de pies a yardas
    yardas = pies / 3;

    // Conversion de pies a pulgadas
    pulgadas = pies * 12;

    // Conversion de pulgadas a centimetros
    centimetros = pulgadas * 2.54;

    // Conversion de centimetros a metros
    metros = centimetros / 100;

    // Mostrar conversiones por pantalla
    printf("%.2f pies es equivalente a:\n", pies);
    printf("\t%.2f yardas\n", yardas);
    printf("\t%.2f pulgadas\n", pulgadas);
    printf("\t%.2f centimetros\n", centimetros);
    printf("\t%.2f metros\n", metros);

    return 0;
}
