/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#define SURTIDORES 10
#define CARBURANTES 6

typedef enum {
    SP95, SP98, DIESEL, DIESELPLUS, ELECTRICIDAD, GAS
} TIPOS_CARBURANTES;

typedef struct {
    float precio;
    int capacidad_deposito;
    int cantidad_vendida;
} INFO_CARBURANTES;

typedef struct {
    int surtidor;
    char matricula[8];
    TIPOS_CARBURANTES carburante;
    int repostado;
} V_PENDIENTES;

void repostado( V_PENDIENTES s[SURTIDORES], INFO_CARBURANTES c[CARBURANTES],
                int surtidor, int *cantidad, float *precio );

int main() {
    V_PENDIENTES surtidores[SURTIDORES];
    INFO_CARBURANTES info[CARBURANTES];

    printf("Hello, World!\n");
    return 0;
}

void repostado( V_PENDIENTES s[SURTIDORES], INFO_CARBURANTES c[CARBURANTES],
                int surtidor, int *cantidad, float *precio ) {
    *cantidad = s[surtidor].repostado;
    *precio = *cantidad * c[s[surtidor].carburante].precio;
    c[s[surtidor].carburante].cantidad_vendida += *cantidad;
}
