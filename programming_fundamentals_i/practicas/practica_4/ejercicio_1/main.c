/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 22/10/2022
 * Programa:
 ******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* definición de funciones del programa */
int dificultad();
void actualizar( int *partidas_ganadas, int *partidas_perdidas,
                 int *total_partidas, int ganador );
void estad( int partidas_ganadas, int partidas_perdidas, int total_partidas,
            char jugador );
void reset( int *partidas_ganadas, int *partidas_perdidas,
            int *total_partidas, char *jugador );
char leeInicial();
int jugar( int nivel, int monedas );
int jugar0( int monedas );
int jugar1( int monedas );


int main() {
    int opcion = 0, nivel_dificultad, min_monedas, monedas, ganador,
        partidas_ganadas = 0, partidas_perdidas = 0, total_partidas = 0;
    char jugador = 'X';
    bool salir = false;

    /* menú principal */
    do {
        printf("\\\\\t\t  Last Coin of Death      \t\t//\n\n");
        printf("\t1. Iniciar una nueva partida\n");
        printf("\t2. Mostrar estadisticas de las jugadas\n");
        printf("\t3. Introducir jugador\n");
        printf("\t4. Resetear juego\n");
        printf("\t5. Salir\n\n");
        printf("\tElige opcion (1, 2, 3, 4 o 5): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                /* solicitar dificultad, calcular número de monedas e iniciar
                 * una nueva partida */
                if ( jugador == 'X' ) {
                    printf("Debes indicar un jugador.\n");
                    jugador = leeInicial();
                }
                do {
                    printf(">> ");
                    nivel_dificultad = dificultad();
                    if ( nivel_dificultad != 1 && nivel_dificultad != 2
                            && nivel_dificultad != 3 ) {
                        printf("\nERROR - Indica un nivel correcto "
                               "(1, 2 o 3).\n");
                    }
                } while ( nivel_dificultad <= 0 || nivel_dificultad >= 4 );
                min_monedas = 10 * ((nivel_dificultad * 10) / 6);

                if ( nivel_dificultad == 1 || nivel_dificultad == 2 ) {
                    do {
                        printf("\n\nIndica cantidad de monedas (minimo "
                               "%d): ", min_monedas);
                        scanf("%d", &monedas);
                    } while ( monedas < min_monedas );
                }

                ganador = jugar(nivel_dificultad, monedas);
                if ( ganador == 2 ) {
                    printf("\nHas ganado.");
                    printf("\nEres toda una maquina.");
                } else {
                    printf("\nHas perdido.");
                    printf("\nNadie puede contra una maquina.");
                }
                actualizar(&partidas_ganadas,
                           &partidas_perdidas,
                           &total_partidas, ganador);
                break;
            case 2:
                if ( jugador == 'X' ) {
                    printf("Debes indicar un jugador.\n");
                    jugador = leeInicial();
                }
                estad(partidas_ganadas, partidas_perdidas, total_partidas,
                      jugador);
                break;
            case 3:
                if ( jugador == 'X' ) {
                    jugador = leeInicial();
                } else {
                    printf("Ya hay un jugador introducido.\n");
                    printf("Resetea estadisticas para introducir un "
                           "nuevo jugador.\n");
                }
                break;
            case 4:
                printf("Reseteando estadisticas.\n");
                reset(&partidas_ganadas,
                      &partidas_perdidas,
                      &total_partidas, &jugador);
                break;
            case 5:
                salir = true;
                break;
            default:
                printf("\nERROR - Opcion no valida.\nPulsa Intro para"
                       " continuar.");
                getch();
        }
        printf("\n\n\n\n");

    } while ( !salir );

    printf("Saliendo...\n");
    return 0;
}


int dificultad() {
    int nivel = 0;

    printf("\n\n\nSeleccionar dificultad (1, 2 o 3): \n");
    printf("\tNivel 1 -> Minimo 10 monedas.\n");
    printf("\tNivel 2 -> Minimo 30 monedas.\n");
    printf("\tNivel 3 -> 21 monedas.\n");

    do {
        printf(">> ");
        scanf("%d", &nivel);
        if ( nivel != 1 && nivel != 2 && nivel != 3 ) {
            printf("\nERROR - Indica un nivel correcto (1, 2 o 3).\n");
        }
    } while ( nivel <= 0 || nivel >= 4 );

    return nivel;
}


int jugar( int nivel, int monedas ) {
    int ganador;

    if ( nivel == 1 ) {
        ganador = jugar0( monedas );
    } else if ( nivel == 2 ) {
        ganador = jugar1( monedas );
    } else {
        ganador = jugar1( 21 );
    }

    return ganador;
}

int jugar0( int m ){
    int  p, c;
    srand((unsigned)time( NULL));

    while(1)
    {
        do{
            printf("Coge 1, 2, 3 o 4 monedas\n>> ");
            scanf("%d", &p);
        }while (p < 1 || p > 4);

        m = m - p;
        printf("Quedan %d monedas\n", m);
        if ( m == 1 ) {
            return 2;
        }
        if (m-1 <= 4) {
            c = m-1;
        } else {
            c = ((int)rand() % 4)+1;
        }
        printf("El ordenador coge %d monedas \n", c);

        m = m - c;
        printf("Quedan %d monedas\n", m);
        if ( m == 1 ) {
            return 1;
        }
    }
}

int jugar1(int m){
    int  p, c;

    while(1) {
        do {
            printf("Coge 1, 2, 3 o 4 monedas\n>> ");
            scanf("%d", &p);
        } while ( p < 1 || p > 4 );

        m = m-p;
        printf("Quedan %d monedas\n", m);

        if ( m == 1 ) {
            return 2;
        }

        int quedan = m-21;
        if ( quedan >= 1 && quedan <= 4 ) {
            c = quedan;
        } else if ( quedan <= 0 ) {
            c = 5-p;
        } else {
            c = 1;
        }

        printf("El ordenador coge %d monedas\n", c);
        m = m-c;

        if ( m <= 0 ){
            return 2;
        } else if ( m == 1 ) {
            return 1;
        }

        printf("Quedan %d monedas\n", m);
    }
}

void actualizar( int *partidas_ganadas, int *partidas_perdidas,
                 int *total_partidas, int ganador ) {
    *total_partidas = *total_partidas + 1;
    if (ganador != 2) {
        *partidas_perdidas = *partidas_perdidas + 1;
        return;
    }
    *partidas_ganadas = *partidas_ganadas + 1;
}

void estad( int partidas_ganadas, int partidas_perdidas, int total_partidas,
            char jugador ) {
    printf("\nEstadisticas de %c", jugador);
    printf("\n-----------------------------------------------------");
    printf("\nGanadas\t\tPerdidas\tTotal");
    printf("\n%d\t\t%d\t\t%d", partidas_ganadas, partidas_perdidas,
           total_partidas);
    printf("\n-----------------------------------------------------");
    printf("\n\nEstadisticas de la maquina");
    printf("\n-----------------------------------------------------");
    printf("\nGanadas\t\tPerdidas\tTotal");
    printf("\n%d\t\t%d\t\t%d", partidas_perdidas, partidas_ganadas,
           total_partidas);
    printf("\n-----------------------------------------------------");
    printf("\nPulsa Intro para continuar.");
    fflush(stdin);
    getch();
}

void reset( int *partidas_ganadas, int *partidas_perdidas,
            int *total_partidas, char *jugador ) {
    *jugador = 'X';
    *total_partidas = 0;
    *partidas_ganadas = 0;
    *partidas_perdidas = 0;
}

char leeInicial() {
    char inicial;

    fflush(stdin);
    printf("Indica una inicial: ");
    scanf("%c", &inicial);

    return toupper(inicial);
}
