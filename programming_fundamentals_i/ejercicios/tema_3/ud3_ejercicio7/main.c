/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 26/09/2022
 * Programa: leer un periodo de tiempo en formato hh:mm:ss y expresarlo en
 *           segundos.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int horas, minutos, segundos, total_segundos;

    printf("Convertir un periodo de tiempo a segundos.\n\n");

    // Solicitar periodo de tiempo al usuario
    printf("Indica un periodo de tiempo en formato (hh:mm:ss): ");
    scanf("%d:%d:%d", &horas, &minutos, &segundos);

    // Calcular tiempo en segundos y mostrar cantidad por pantalla
    total_segundos = segundos + (horas * 3600) + (minutos * 60);
    printf("\n\n%d:%d:%d es equivalente a %d segundos.\n", horas, minutos,
           segundos, total_segundos);

    return 0;
}
