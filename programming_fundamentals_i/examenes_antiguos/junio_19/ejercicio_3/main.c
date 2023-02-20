/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa: clasificador de naranjas segun su tamano. El programa lee por
 *           teclado diametros y mostrara por pantalla la categoria:
 *                  ·84-110     -       Extra
 *                  ·64-84      -       Estandar
 *                  ·53-64      -       Media
 *                  ·<53        -       Diminuta
 *           Se leeran diametros hasta introducir -100. Al finalizar, se debe
 *           mostrar el numero de naranjas clasificadas en cada categoria.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int total_clasificadas[4] = {0,0,0,0};
    float diametro = 0;

    while ( diametro != -100 ) {
        printf("Indica un diametro: ");
        scanf("%f", &diametro);

        if ( diametro != -100 ) {
            if ( diametro > 84 && diametro <= 110 ) {
                printf("\nExtra\n");
                total_clasificadas[0]++;
            } else if ( diametro > 64 && diametro <= 84 ) {
                printf("\nEstandar\n");
                total_clasificadas[1]++;
            } else if ( diametro > 53 && diametro <= 64 ) {
                printf("\nMedia\n");
                total_clasificadas[2]++;
            } else if ( diametro <= 53 ) {
                printf("\nDiminuta\n");
                total_clasificadas[3]++;
            }
        }
    }

    printf("Se han clasificado\n\t-Extra: %d\n\t-Estandar: %d\n\t"
           "-Media: %d\n\t-Diminuta: %d\n\n", total_clasificadas[0],
           total_clasificadas[1], total_clasificadas[2], total_clasificadas[3]);

    return 0;
}
