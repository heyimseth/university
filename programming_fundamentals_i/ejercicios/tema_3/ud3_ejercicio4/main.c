/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 26/09/2022
 * Programa: a partir de un total de kilómetros recorridos, el precio de la
 *           gasolina (por litro), el importe de gasolina gastada en un viaje,
 *           y el tiempo tardado (horas y minutos), todo ello introducido por
 *           teclado, se calcula:
 *                  -consumo de gasolina (litros y euros) por cada 100 km
 *                  -velocidad media (km/h)
 ******************************************************************************/
#include <stdio.h>

int main() {
    float km, precio_gasolina, importe_gasolina,
            litros_gasolina, euros_gasolina, velocidad_media;
    int horas, minutos;

    printf("\nCalculadora de consumo de gasolina\n\n");

    // Solicitar los datos necesarios al usuario
    printf("Introduce el total de kilometros recorridos: ");
    scanf("%f", &km);
    printf("Introduce el precio/litro de la gasolina: ");
    scanf("%f", &precio_gasolina);
    printf("Introduce el importe gastado en gasolina en el viaje: ");
    scanf("%f", &importe_gasolina);
    printf("Introduce el tiempo tardado en realizar el viaje (formato:"
           " horas minutos): ");
    scanf("%d %d", &horas, &minutos);

    // Calcular consumo de gasolina en litros y euros por cada 100 km
    litros_gasolina = (100 * (importe_gasolina / precio_gasolina)) / km;
    euros_gasolina = (100 * importe_gasolina) / km;
    printf("\n\nConsumo por cada 100 km:\n\t%.2f l\t\t%.2f euros\n",
           litros_gasolina, euros_gasolina);

    // Calcular velocidad media
    horas = horas + (minutos / 60);
    velocidad_media = (km / horas);
    printf("\n\nVelocidad media:\n\t%.2f km/h\n\n", velocidad_media);

    return 0;
}
