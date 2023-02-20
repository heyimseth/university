/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 05/11/2022
 * Programa: calcular x^n para x real y n entero.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int cant_notas, i;
    float suma = 0, nota, media;

    printf("Cuantas notas? ");
    scanf("%d", &cant_notas);

    for ( i = 1; i <= cant_notas; i++ ) {
        fflush(stdin);
        printf("Nota %d: ", i);
        scanf("%f", &nota);

        suma += nota;
    }

    media = suma / cant_notas;
    printf("Nota media = %.2f", media);

    return 0;
}
