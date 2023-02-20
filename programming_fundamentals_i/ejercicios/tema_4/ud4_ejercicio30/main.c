/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 03/10/2022
 * Programa: leer caracteres por teclado hasta que se introduzca un punto, e
 *           imprimir el número de veces que se ha introducido una vocal.
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int num_a = 0, num_e = 0, num_i = 0, num_o = 0, num_u = 0;

    printf("Indica una frase finalizada en punto (.): ");
    c = getchar();

    while ( c != '.' ) {
        switch (toupper(c)) {
            case 'A':
                num_a++;
                break;
            case 'E':
                num_e++;
                break;
            case 'I':
                num_i++;
                break;
            case 'O':
                num_o++;
                break;
            case 'U':
                num_u++;
                break;
        }

        c = getchar();
    }

    printf("\n\nSe han introducido %d 'a', %d 'e', %d 'i', %d 'o' y "
           "%d 'u'.", num_a, num_e, num_i, num_o, num_u);
    return 0;
}
