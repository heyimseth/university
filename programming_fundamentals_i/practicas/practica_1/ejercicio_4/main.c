#include <stdio.h>
/* Programa que lee un caracter en minusculas y
 * lo escribe en mayusculas */

int main() {
    int minuscula, mayuscula;

    printf("Indica un caracter en minusculas:\t");
    minuscula = getchar();

    /* Transformacion a mayusculas, restando 32 caracteres, para obtener
     * su codigo correspondiente en ASCII */
    mayuscula = minuscula - 32;

    printf("Mayusculas: %c", mayuscula);

    return 0;
}
