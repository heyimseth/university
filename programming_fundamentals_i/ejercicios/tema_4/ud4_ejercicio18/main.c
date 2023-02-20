/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/10/2022
 * Programa: leer una secuencia de caracteres acabados en $ e indicar el número
 *           de veces que aparece un carácter dado por el usuario.
 ******************************************************************************/
#include <stdio.h>

int main() {
    char c, c_busqueda;
    int cantidad = 0;

    printf("Indica el caracter a buscar en una secuencia: ");
    scanf("%c", &c_busqueda);
    printf("Indica la secuencia de caracteres (finalizada en $): ");
    c = getchar();

    while ( c != '$' ) {
        if ( c == c_busqueda ) {
            cantidad++;
        }
        c = getchar();
    }

    printf("Se ha introducido %c un total de %d veces.", c_busqueda,
           cantidad);

    return 0;
}
