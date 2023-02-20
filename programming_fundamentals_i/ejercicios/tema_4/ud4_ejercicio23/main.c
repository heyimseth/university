/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/10/2022
 * Programa: dada una secuencia de números (finalizada en 0), muestra el
 *           resultado de las sumas:
 *              -S = a1 + a2 + a3 + ... + an
 *              -St = a1 + (a1+a2) + (a1+a2+a3) + ... + (a1+a2+...+an)
 ******************************************************************************/
#include <stdio.h>

int main() {
    int num = 1, s = 0, st = 0;

    printf("A partir de una secuencia de numeros, calcular las sumas\n");
    printf("\tS = a1 + a2 + ... + an\n"
           "\tSt = a1 + (a1+a2) + (a1+a2+a3) + ... (a1+a2+a3+...+an)\n");

    while ( num != 0 ) {
        printf("Indica un numero (o 0 para acabar): ");
        scanf("%d", &num);

        s = s + num;
        st = st + s;
    }
    st = st - s;

    printf("S = %d\nSt = %d\n", s, st);

    return 0;
}
