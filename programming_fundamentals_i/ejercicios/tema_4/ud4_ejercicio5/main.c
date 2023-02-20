/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 26/09/2022
 * Programa: leer la hora en notación de 24 horas (13:45) y convertirla a
 *           notación de 12 horas (1:45 PM)
 ******************************************************************************/
#include <stdio.h>

int main() {
    int hora, minutos;

    printf("Indica una hora en notacion de 24 horas (19:23): ");
    scanf("%d:%d", &hora, &minutos);

    if ( hora > 12 ) {
        printf("Equivalente en notacion 12 horas: %d:%d PM.\n",
               (hora % 12), minutos);
    } else {
        printf("Equivalente en notacion 12 horas: %d:%d AM.\n",
               hora, minutos);
    }

    return 0;
}
