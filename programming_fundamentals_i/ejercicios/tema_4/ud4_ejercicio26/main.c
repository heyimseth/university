/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/10/2022
 * Programa: comprobar si un número dado es automórfico.
 ******************************************************************************/
#include <stdio.h>
#include <limits.h>

int main() {
    int ini, pot_10 = 1, i;
    unsigned long long int cuad, fin, rest = 0;

    printf("%llu\n\n", ULLONG_MAX);

    printf("Indica numero inicial: ");
    scanf("%d", &ini);
    printf("Indica numero final: ");
    scanf("%lld", &fin);

    for ( i = ini; i <= fin; i++ ) {
        cuad = i*i;
        while ( cuad != 0 && i != rest ) {
            rest = rest + (( cuad % 10 ) * pot_10);
            cuad = cuad / 10;
            pot_10 = pot_10 * 10;
        }

        if ( i == rest ) {
            printf("El numero %d es automorfico.\n", i);
        }
        rest = 0;
        pot_10 = 1;
    }

    return 0;
}
