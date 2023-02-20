/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 24/10/2022
 * Programa: dado un numero, devolver el dígito que ocupa la posición p (p>0)
 ******************************************************************************/
#include <stdio.h>

int obtenerPosicion(int num, int pos) {
    int i;

    if (num < 0) {
        num = -num;
    }
    for ( i = 1; i < pos; i++ ) {
        num = num / 10;
    }
    return num % 10;
}

int main() {
    int num, pos;

    printf("Indica un numero entero: ");
    scanf("%d", &num);

    do {
        printf("Indica una posicion (mayor que 0): ");
        scanf("%d", &pos);
    } while ( pos < 1 );

    printf("\nEl digito que ocupa la posicion %d en %d es %d.", pos, num,
           obtenerPosicion(num, pos));

    return 0;
}
