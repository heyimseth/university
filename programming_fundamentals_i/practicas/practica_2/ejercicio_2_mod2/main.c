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

int main() {
    int opcion = 0;
    char salir;

    do {
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
        printf("\t3. Introducir jugadores\n");
        printf("\t4. Salir\n\n");
        printf("\tElige opcion (1, 2, 3 o 4): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n\tIniciando nueva partida...");
                break;
            case 2:
                printf("\n\tMostrando estadisticas de las jugadas");
                break;
            case 3:
                printf("\n\tIntroducir jugadores");
                break;
            case 4:
                do {
                    fflush(stdin);
                    printf("Seguro que quieres salir? (S/N)");
                    scanf("%c", &salir);
                } while ( salir != 'S' && salir != 'N' );
                break;
            default:
                printf("\nERROR - Opcion no valida.");
        }
        printf("\n\n\n\n");

    } while ( salir != 'S' );

    printf("Saliendo...\n");

    return 0;
}
