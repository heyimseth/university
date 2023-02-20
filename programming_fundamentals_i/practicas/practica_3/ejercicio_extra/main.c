/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 06/10/2022
 * Programa: simulación del comportamiento de un canguro ante la comida.
 *              -El canguro está en un recinto circular de radio R metros. X
 *              -Su posición inicial es aleatoria (x,y). X
 *              -Desea llegar al plato de comida, cuya posición variará entre
 *               ejecuciones, y deberá indicarlo el científico. X
 *
 *           Se debe tener en cuenta que:
 *              -El recinto es cerrado, por tanto el canguro no puede escapar.
 *              -Los saltos del canguro son de 1 m de longitud.
 *              -El canguro se moverá en función de las siguientes teclas:
 *                  ·'N' se dirige al frente.
 *                  ·'S' se dirige hacia atrás.
 *                  ·'E' se dirige hacia la derecha.
 *                  ·'O' se dirige hacia la izquierda.
 *              -Cuando el canguro se tope con la valla, emitirá un gruñido
 *               y volverá a la posición de la que partía.
 *              -Para comprobar que el canguro está dentro del recinto se
 *               utilizará el teorema de Pitágoras --> R^2 = x^2 + y^2
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int radio = 15;
    int cang_x, cang_y;
    int plato_x, plato_y;
    bool plato_pos = false, comiendo = false, comando_valido;
    char comando;

    // Iniciar proceso de generación aleatoria de números
    srand((unsigned)time(NULL));
    // Generar aleatoriamente la posición del canguro
    cang_x = sqrt(rand() % radio);
    cang_y = sqrt(rand() % radio);


    printf("Simulacion del comportamiento de un canguro ante comida.\n");
    printf("Los comandos de movimiento del canguro son:\n");
    printf("\t-'N' para moverse hacia arriba.\n");
    printf("\t-'S' para moverse hacia abajo.\n");
    printf("\t-'E' para moverse hacia la derecha.\n");
    printf("\t-'O' para moverse hacia la izquierda.\n\n");


    // Solicitar posición de la comida, x e y deben ser menores que el radio
    do {
        printf("\nIndica la posicion del plato\n\tValor de 'x': ");
        scanf("%d", &plato_x);
        printf("\n\tValor de 'y':");
        scanf("%d", &plato_y);

        /* Verificar que x e y es un punto real del recinto. Si no lo son,
         * volver a solicitarlo. Si lo es, cambiar el valor de plato_pos a true
         * para continuar */
        if ( radio <= sqrt((plato_x*plato_x + plato_y*plato_y)) ) {
            printf("La posicion indicada esta fuera del recinto...\n");
        } else {
            plato_pos = true;
        }
    } while ( !plato_pos );


    /* Bucle de movimiento del canguro hasta llegar a la comida. El objetivo es
     * que, mediante comandos de movimientos introducidos por el usuario, el
     * canguro llegue hasta el plato de comida. Una vez lo consiga, salir del
     * bucle y finalizar el programa. */
    do {
        // Indicamos la posición actual del canguro y del plato de comida.
        printf("El canguro se encuentra en (%d,%d).\nEl plato se "
               "encuentra en (%d,%d).\n", cang_x, cang_y, plato_x, plato_y);

        /* Si la posición del canguro es la misma que la del plato, comenzará
         * a comer. Cambiamos el valor de 'comiendo' a 'true', finalizando así
         * el bucle y el programa */
        if ( cang_x == plato_x && cang_y == plato_y ) {
            comiendo = true;
        } else {
            // Solicitar un comando de movimiento válido
            do {
                fflush(stdin);
                comando_valido = false;
                printf(" >> ");
                comando = getchar();

                if ( comando != 'N' && comando != 'S' && comando != 'E' &&
                        comando != 'O' ) {
                    printf("No se reconoce el comando indicado...\n\n");
                } else {
                    comando_valido = true;
                }
            } while ( !comando_valido );

            /* En este punto ya tenemos un comando de movimiento válido, por
             * tanto, ejecutamos el movimiento */
            switch ( comando ) {
                case 'N':
                    cang_y++;
                    break;
                case 'S':
                    cang_y--;
                    break;
                case 'E':
                    cang_x++;
                    break;
                case 'O':
                    cang_x--;
                    break;
            }

            // Comprobamos si el canguro está intentando escapar del recinto
            if ( radio <= sqrt((cang_x*cang_x + cang_y*cang_y)) ) {
                printf("\n\nEL CANGURO INTENTA ESCAPAR Y HA CHOCADO "
                       "CONTRA LA VALLA!\a\n");
                printf("Volviendo al punto anterior...\n\n");
                switch ( comando ) {
                    case 'N':
                        cang_y--;
                        break;
                    case 'S':
                        cang_y++;
                        break;
                    case 'E':
                        cang_x--;
                        break;
                    case 'O':
                        cang_x++;
                        break;
                }
            }
        }
    } while ( !comiendo );

    printf("El canguro ha llegado hasta la comida!\n\n");

    return 0;
}
