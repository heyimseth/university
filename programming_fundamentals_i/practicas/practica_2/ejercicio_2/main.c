/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 29/09/2022
 * Programa: mostrar el menú de un juego. En el que el usuario puede escoger
 *           entre iniciar una nueva partida, mostrar las estadísticas de las
 *           jugadas o introducir jugadores. Las opciones se seleccionarán
 *           con los números 1 a 3. El programa mostrará por pantalla la opción
 *           elegida. Si se selecciona una opción diferente a 1 a 3, mostrará
 *           un mensaje indicando que la opción no es válida y terminará.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;

    printf("\\\\\t\t  Space Invaders       \t\t//\n\n");
    printf("    ##          ##              ##          ##\n"
           "      ##      ##                  ##      ##\n"
           "    ##############              ##############\n"
           "  ####  ######  ####          ####  ######  ####\n"
           "######################      ######################\n"
           "##  ##############  ##      ##  ##############  ##\n"
           "##  ##          ##  ##      ##  ##          ##  ##\n"
           "      ####  ####                  ####  ####\n\n\n");
    printf("\t1. Iniciar una nueva partida\n");
    printf("\t2. Mostrar las estadisticas de las jugadas\n");
    printf("\t3. Introducir jugadores\n\n");
    printf("\tElige opcion (1, 2 o 3): ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\n\tIniciando nueva partida...\n\n");
            break;
        case 2:
            printf("\n\tMostrando estadisticas de las jugadas\n\n");
            break;
        case 3:
            printf("\n\tIntroducir jugadores\n\n");
            break;
        default:
            printf("\nERROR - Opcion no valida.\n\n");
            exit(1);
    }

    return 0;
}
