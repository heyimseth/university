/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 29/09/2022
 * Programa: mostrar el tipo de fruta en función del carácter introducido:
 *                  -N/n: Naranja Cítrico
 *                  -C/c: Cítrico
 *                  -M/m: Manzana No es cítrico
 *                  -Otro: No se sabe qué es
 ******************************************************************************/
#include <stdio.h>

void main() {
    char caracter;
    scanf("%c", &caracter);

    switch(caracter) {
        case 'N':
        case 'n':
            printf("Naranja \n");
        case 'C':
        case 'c':
            printf("Citrico \n");
            break;
        case 'M':
        case 'm':
            printf("Manzana \n");
            printf("No es un citrico \n");
            break;
        default:
            printf("No se sabe que es");
    }
}
