#include <stdio.h>
#define PRECIO_COLA 0.17
#define PRECIO_NARANJA 0.20
#define PRECIO_LIMON 0.19

/* Una compañía de refrescos comercializa tres productos: de cola,
 * de naranja y de limón. Se desea realizar un programa que calcule
 * las ventas realizadas de cada producto. Para ello, se leerá la
 * cantidad vendida (máximo 5000000) y el precio en euros de cada
 * producto y se mostrará un informe de ventas como el que sigue:
 *
 * Producto     Ventas      Precio      Total
 * ------------------------------------------------------------------------
 *  Cola        1000000     0.17        170000.00
 *  Naranja     350000      0.20        70000.00
 *  Limon       530000      0.19        100700.00
 *                                TOTAL 340700.00
*/

int main() {
    int ventas_cola, ventas_naranja, ventas_limon;
    double total_cola, total_naranja, total_limon, total;

    /* Lectura de la cantidad de ventas por producto y verificacion de que no
     * exceden el limite de 5.000.000 */
    printf("Indica las ventas de refrescos de cola (max. 5000000): ");
    scanf("%d", &ventas_cola);
    if (ventas_cola > 5000000) {
        ventas_cola = 5000000;
    }
    printf("Indica las ventas de refrescos de naranja (max. 5000000): ");
    scanf("%d", &ventas_naranja);
    if (ventas_naranja > 5000000) {
        ventas_naranja = 5000000;
    }
    printf("Indica las ventas de refrescos de limon (max. 5000000): ");
    scanf("%d", &ventas_limon);
    if (ventas_cola > 5000000) {
        ventas_cola = 5000000;
    }

    /* Calculo del dinero total obtenido por cada producto */
    total_cola = ventas_cola * PRECIO_COLA;
    total_naranja = ventas_naranja * PRECIO_NARANJA;
    total_limon = ventas_limon * PRECIO_LIMON;
    total = total_cola + total_naranja + total_limon;

    /* Mostrar por pantalla el informe de ventas */
    printf("\n\nProducto\tVentas\tPrecio\tTotal\n");
    printf("-------------------------------------------------\n");
    printf("Cola\t\t%d\t%.2f\t%.2f\n", ventas_cola, PRECIO_COLA,
           total_cola);
    printf("Naranja\t\t%d\t%.2f\t%.2f\n", ventas_naranja, PRECIO_NARANJA,
           total_naranja);
    printf("Limon\t\t%d\t%.2f\t%.2f\n", ventas_limon, PRECIO_LIMON,
           total_limon);
    printf("\t\t\tTOTAL\t%.2f\n\n", total);

    return 0;
}
