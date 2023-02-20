/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 29/09/2022
 * Programa: calcular el consumo de un vehículo según su velocidad.
 *           Valores de entrada y salida:
 *              Velocidad   Consumo
 *                 80         10
 *                 100        11
 *                 120        13.2
 *                 140        16.8
 *                 150        18
 ******************************************************************************/

#include <stdio.h>

void main() {
    int velocidad;
    float consumo = 0;

    scanf("%d", &velocidad);

    if (velocidad < 100) {
        if (velocidad < 80)
            /* Convertimos velocidad a float porque si no, sería una division
             * entera*/
            consumo = (float)(velocidad / 10);
        else
            consumo = 10;
    }
    else {
        if (velocidad < 140)
            consumo = velocidad / 10 * 1.1;
        else
            consumo = velocidad / 10 * 1.2;
    }
    printf("%f", consumo);
}
