/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/10/2022
 * Programa: comprobar si un número dado es automórfico.
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num, cuad, pot_10 = 1, rest = 0;

    printf("Indica un numero para saber si es automorfico: ");
    scanf("%d", &num);
    cuad = num * num;

    while ( cuad != 0 && num != rest ) {
        rest = rest + (( cuad % 10 ) * pot_10);
        cuad = cuad / 10;
        pot_10 = pot_10 * 10;
    }

    if ( num == rest ) {
        printf("El numero %d es automorfico.\n", num);
    } else {
        printf("El numero %d no es automorfico.\n", num);
    }

    return 0;
}
