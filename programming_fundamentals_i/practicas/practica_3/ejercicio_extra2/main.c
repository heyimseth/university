/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 13/10/2022
 * Programa: simular una carrera entre una liebre y una tortuga. Ambos comienzan
 *           en la posición 1 y deberán llegar a la 15. La ruta discurre en una
 *           ladera escurridiza, por lo que a veces pueden escurrirse. El
 *           porcentaje de realización de los movimientos es:
 *                  -Tortuga:
 *                      · Paso rápido - 50% - 3 posiciones adelante.
 *                      · Paso lento - 30% - 1 posición adelante.
 *                      · Se escurre - 20% - 2 posiciones atrás.
 *                  -Liebre:
 *                      · Descansa - 20% - Sin movimiento.
 *                      · Salto pequeño - 30% - 1 posición adelante.
 *                      · Salto grande - 20% - 6 posiciones adelante.
 *                      · Se escurre un poco - 20% - 2 posiciones atrás.
 *                      · Se escurre mucho - 10% - 4 posiciones atrás.
 *           Se utilizarán variables para el seguimiento de posiciones. Si un
 *           animal posicionado en 1 se intenta mover atrás, volverá a 1. Se
 *           irán realizando movimientos hasta que uno llegue a la meta. Al
 *           inicio de cada ciclo se generará aleatoriamente el movimiento que
 *           realiza cada uno. Los porcentajes se generarán mediante un número
 *           aleatorio en el rango 1 <= i <= 10.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pos_tort = 1, pos_lieb = 1;
    int mov_tort, mov_lieb;

    srand((unsigned)time(NULL));

    printf("COMIENZA LA CARRERA\n\n");
    printf("Tortuga: %d - Liebre: %d", pos_tort, pos_lieb);

    while ( pos_lieb < 15 && pos_tort < 15 ) {
        // Cálculo del porcentaje de movimiento
        mov_tort = rand()%10;
        mov_lieb = rand()%10;

        /***********************************************************************
         *                    MOVIMIENTO DE LOS ANIMALES                       *
         **********************************************************************/
        // Movimiento de la tortuga
        if ( mov_tort <= 5 ) {
            pos_tort = pos_tort + 3;
        } else if ( mov_tort <= 8 ) {
            pos_tort++;
        } else {
            pos_tort = pos_tort - 2;
            if ( pos_tort < 1 ) { // Comprobar que no retrocede a menos de 1
                pos_tort = 1;
            }
        }

        // Movimiento de la liebre
        if ( mov_lieb <= 3 ) {
            pos_lieb++;
        } else if ( mov_lieb <= 5 ) {
            pos_lieb = pos_lieb + 6;
        } else if ( mov_lieb <= 7 ) {
            pos_lieb = pos_lieb - 2;
        } else if ( mov_lieb <= 8 ) {
            pos_lieb = pos_lieb - 4;
        }
        if ( pos_lieb < 1 ) { // Comprobar que no retrocede a menos de 1
            pos_lieb = 1;
        }

        printf("\nTortuga: %d - Liebre: %d", pos_tort, pos_lieb);

        // Si están en la misma posición, la tortuga muerde a la liebre
        if ( pos_lieb == pos_tort ) {
            printf("\t\tAUUUHG!!");
        }
    }

    if ( pos_lieb >= 15 ) {
        printf("\n\nGana la liebre.");
    } else {
        printf("\n\nGana la tortuga.");
    }

    return 0;
}
