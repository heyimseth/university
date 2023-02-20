/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>

typedef struct {
    char titulo[26], director[30], genero[16], idioma[11];
    int duracion;
    float puntuaciones[7];
} PELICULA;

int main() {
    PELICULA peliculas[15][6];

    printf("Hello, World!\n");
    return 0;
}
