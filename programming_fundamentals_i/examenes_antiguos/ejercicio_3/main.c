/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa:
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define MAX_TEMP 50
#define MAX_EPI 150

enum tematica {accion=0, comedia, drama, terror, romantico};

struct info_serie {
    char nombre[25];
    enum tematica tipo;
    int puntuacion;
    int temporadas;
    int cap_temporada;
    bool vistos[MAX_TEMP][MAX_EPI];
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
