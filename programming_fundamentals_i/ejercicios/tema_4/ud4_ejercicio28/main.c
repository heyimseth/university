/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 07/11/2022
 * Programa: escribir un programa que muestre por pantalla el menú:
 *                  1. Factorial.
 *                  2. Numero automorfico.
 *                  3. Ecuacion de segundo grado.
 *                  4. Fin.
 *                  Elige opcion:
 *           lea un valor i, muestre "se ha escgido la opción i", y vuelva a
 *           mostrar el menú. Si se introduce un 4, se mostrará el mensaje
 *           "Fin de la aplicación" y acabará el programa. Y si se introduce
 *           cualquier otro valor, mostrará el mensaje "Opción incorrecta" y
 *           volverá a aparecer el menú.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

double factorial();
bool esAutomorfico();
float ecSegundoGrado();

int main() {
    int opcion;

    do {
        printf("\n\n1. Factorial\n");
        printf("2. Numero automorfico\n");
        printf("3. Ecuacion de segundo grado\n");
        printf("4. Fin\n");
        printf("Elige opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
            case 2:
            case 3:
                printf("Has escogido la opcion %d.\n", opcion);
                break;
            case 4:
                printf("Fin de la aplicacion.\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    } while ( opcion != 4 );
    return 0;
}
