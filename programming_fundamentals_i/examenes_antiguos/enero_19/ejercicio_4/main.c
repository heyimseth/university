/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#define PUNTOS_CONTROL 4
#define LIMITE_COCHES 50

typedef struct {
    unsigned short int d, m, y; // dia mes año
} T_FECHA;

typedef struct {
    unsigned short int h, m, s, d; // horas:minutos:segundos:decimas
} T_HORA;

typedef enum {
    CORRECTO, ADMISIBLE, SANCIONABLE
} E_ESTADO;

typedef struct {
    char identificador[13];
    char matricula[8];
    T_FECHA fecha[PUNTOS_CONTROL];
    T_HORA hora[PUNTOS_CONTROL];
    E_ESTADO estado;
} T_FICHA;

void CalcularEstado(T_FICHA *coche);

int main() {
    T_FICHA radares[LIMITE_COCHES] = {
            {"RAD000000001", "7221KXT",
             {10,12,2022,10,12,2022,10,12,2022,10,12,2022},
             {12,20,22,9,12,21,23,1,12,23,8,7,12,43,12,8},
             }
    };

    CalcularEstado(&radares[0]);

    printf("%d", radares[0].estado);

    return 0;
}

void CalcularEstado(T_FICHA *coche) {
    unsigned short int min = 0, seg = 0, t_excedidos = 0, tiempo_total = 0;

    for ( int i = PUNTOS_CONTROL-1; i > 0; i-- ) {
        if ( (coche->hora[i].d - coche->hora[i-1].d) < 0 ) seg--;

        if ( (seg + coche->hora[i].s - coche->hora[i-1].s) < 0 ) min--;

        min += (coche->hora[i].m - coche->hora[i-1].m +
                (coche->hora[i].h - coche->hora[i-1].h)*60);

        tiempo_total += min;

        if ( min > 3 ) t_excedidos++;

        seg = 0;
        min = 0;
    }

    if ( t_excedidos == 0 ) {
        coche->estado = CORRECTO;
    } else if ( t_excedidos == 1 && tiempo_total < 15 ) {
        coche->estado = ADMISIBLE;
    } else {
        coche->estado = SANCIONABLE;
    }
}
