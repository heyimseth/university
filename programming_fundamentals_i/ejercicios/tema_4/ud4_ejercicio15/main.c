/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 11/10/2022
 * Programa: dados dos números n y m, comprueba si uno es inverso del otro.
 *              n = 135, m = 531
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

int main() {
    int n, nc, n_rev = 0, m, mc, n_num_dig = 0, m_num_dig = 0, pot_10, i;

    printf("Comprobar si un numero es inverso de otro.\n\n");
    printf("Indica un numero: ");
    scanf("%d", &n);
    printf("Indica otro numero: ");
    scanf("%d", &m);
    nc = n;
    mc = m;

    /* Contar el número de dígitos de los números, ambos deben tener la misma
     * cantidad de dígitos para que la operación de inverso tenga sentido. */
    do {
        if ( nc >= 1 ) {
            nc = nc / 10;
            n_num_dig++;
        }
        if ( mc >= 1 ) {
            mc = mc / 10;
            m_num_dig++;
        }
    } while ( nc != 0 || mc != 0 );

    if ( n_num_dig == m_num_dig ) {
        pot_10 = pow(10, n_num_dig-1);
        for ( i = 1; i <= n_num_dig; i++ ) {
            n_rev = n_rev + ((n % 10) * pot_10);
            pot_10 = pot_10 / 10;
            n = n / 10;
        }

        if ( n_rev == m ) {
            printf("Son inversos.\n");
        } else {
            printf("No son inversos.\n");
        }
    } else {
        printf("Los numeros deben tener la misma cantidad de digitos.\n");
    }

    return 0;
}
