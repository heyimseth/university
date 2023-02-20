/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define MAX_TEMP 50
#define MAX_CAP 100

typedef enum { accion, comedia, drama, terror, romantico } TIPO_TEMATICA;

typedef struct {
    char nombre[25];
    TIPO_TEMATICA tematica;
    int puntuacion, temporadas, capitulos;
    bool vistos[MAX_TEMP][MAX_CAP];
} TIPO_SERIE;

typedef TIPO_SERIE TIPO_USUARIOS[250];

int main() {
    TIPO_USUARIOS usuarios;

    printf("Hello, World!\n");
    return 0;
}
