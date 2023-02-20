/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 04/10/2022
 * Programa: a partir de una cantidad de kg de ropa a lavar, se calcula de la
 *           cantidad de litros de agua que se necesitan. En función del nivel:
 *              - > 10kg: la lavadora no funcionará.
 *              - > 8kg: la lavadora gastará 30 litros.
 *              - > 7kg: la lavadora gastará 20 litros.
 *              - > 5kg: la lavadora gastará 10 litros.
 *              - <= 5kg: la lavadora gastará 7 litros.
 *           Se solicitará una cantidad repetidamente hasta que el usuario pida
 *           terminar.
 ******************************************************************************/
 #include <stdio.h>

int main() {
    float peso;

    printf("Calcular gasto de agua a partir de una cantidad de ropa.\n");
    do {
        printf("Indica una cantidad en kg (o 0 para parar): ");
        scanf("%f", &peso);

        if ( peso > 10 ) {
            printf("Demasiado peso para la lavadora.\n\n");
        } else if ( peso > 8 ) {
            printf("Se gastan 30 litros de agua.\n\n");
        } else if ( peso > 7 ) {
            printf("Se gastan 20 litros de agua.\n\n");
        } else if ( peso > 5 ) {
            printf("Se gastan 10 litros de agua.\n\n");
        } else if ( peso > 0 ) {
            printf("Se gastan 7 litros de agua.\n\n");
        }

    } while ( peso != 0 );

    printf("Cerrando...");
    return 0;
}
