/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 30/09/2022
 * Programa: leer una cantidad de segundos y convertirlos a días, horas, minutos
 *           y segundos.
 ******************************************************************************/
 #include <stdio.h>

int main() {
    int cantidad, dias, horas, minutos, segundos;

    printf("Convertir una cantidad de segundos a dias, horas, minutos"
           " y segundos.\n\n");

    // Solicitar cantidad de segundos al usuario
    printf("Indica una cantidad de segundos: ");
    scanf("%d", &cantidad);

    // Calcular tiempo en días, horas, minutos y segundos
    minutos = cantidad / 60;
    segundos = cantidad % 60;

    horas = minutos / 60;
    minutos = minutos % 60;

    dias = horas / 24;
    horas = horas % 24;

    // Mostrar resultado por pantalla
    printf("%d segundos son: %d dias, %d horas, %d minutos, %d segundos.",
           cantidad, dias, horas, minutos, segundos);

    return 0;
}
