/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 26/09/2022
 * Programa: lee un número x e indica en qé rango se encuentra dentro del rango:
 *              -x < 0
 *              -0 <= x <= 100
 *              -100 < x <= 1000
 *              -x > 1000
 ******************************************************************************/
#include <stdio.h>

int main() {
    float num;

    printf("Indica un numero: ");
    scanf("%f", &num);

    if (num < 0) {
        printf("El numero %.2f es inferior a 0", num);
    } else if (num <= 100) {
        printf("El numero se encuentra en el rango 0 <= %.2f <= 100",
               num);
    } else if (num <= 1000) {
        printf("El numero se encuentra en el rango 100 <= %.2f <= 1000",
               num);
    } else {
        printf("El numero %.2f es superior a 1000", num);
    }

    return 0;
}
