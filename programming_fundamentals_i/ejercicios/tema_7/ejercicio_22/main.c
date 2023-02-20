/*******************************************************************************
 *Autor: Alvaro Martinez Alfaro
 * Enunciado: el comercio LO.VE.TO es una pequena tienda dedicada a vender todo
 *            lo que se pone en su camino y ha decidido crear un programa que le
 *            permita informatizar, por ahora, el proceso de venta de sus
 *            productos de modo que le salgan las cuentas y tenga controlado
 *            como se van reduciendo las existencias de cada producto que tiene
 *            en el almacen. Para el control de los procutos del almacen, ha
 *            decidido que la informacion que quiere almacenar de cada uno de
 *            los productos seran un codigo de barras del producto (real o
 *            creado por la propia empresa) que estara compuesto por 15 digitos,
 *            nombre del producto, tipo de producto (perecedero, ferreteria,
 *            ropa, otros), cantidad en el almacen y precio unitario del mismo.
 *            Estos productos los tiene colocados en una fila de E estanterias,
 *            cada una de las cuales posee 5 estantes, de modo que puede tener
 *            varios estantes de varias estanterias con un mismo producto,
 *            pero en cada estante solamente tendra un producto. Ademas, quiere
 *            que el programa que controle el proceso de venta, funcione de la
 *            siguiente forma: cuando un cliente realice una compra, el
 *            encargado introducira en el sitema el codigo del producto y la
 *            cantidad que el cliente desea. Con estos datos el programa
 *            procedera en primer lugar a comprobar si posee suficientes
 *            unidades del producto para atender la peticion. Si existen,
 *            actualizara la cantidad que tiene en el almacen, calculara el
 *            importe total de la compra y lo mostrara por pantalla. En el caso
 *            en el que la cantidad en almacen sea menor que la solicitada por
 *            el cliente, el programa indicara por pantalla esta situacion y la
 *            cantidad maxima (la que tiene en el almacen) que le sera vendida.
 *            Al igual que en la situacion anterior, actualizara la cantidad de
 *            producto en almacen y calculara el precio total de la venta, que
 *            mostrara por pantalla.
 *            Debe tenerse en cuenta que puede ocurrir que alguno de los
 *            estantes en los que hay existencias del producto, puede quedarse
 *            sin ninguna unidad y que el precio del mismo producto puede variar
 *            de un estante a otro.
 *            Se pide:
 *                  -definir los tipos de datos necesarios.
 *                  -crear un programa que realice el proceso de venta de un
 *                   unico producto. debera solicitar al usuario el codigo de
 *                   barras del producto a vender y la cantidad que se va a
 *                   vender, y mostrara por pantalla el importe total de la
 *                   venta.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define ESTANTERIAS 7
#define ESTANTES 5

typedef enum {perecedero, ferreteria, ropa, otros} TIPO_PRODUCTO;

typedef struct {
    int codigo;
    char nombre[35];
    TIPO_PRODUCTO tipo;
    int cantidad;
    float precio;
} INFO_PRODUCTO;

int estantes_ocupados = 7;
INFO_PRODUCTO almacen[ESTANTERIAS][ESTANTES] = {
        {
                {21823,"martillo",ferreteria,7,6.5},
                {384721,"camiseta",ropa,5,19.99},
                {382341,"pantalon",ropa,2,24.99},
                {384721,"camiseta",ropa,6,23.99},
                {71263,"auriculares",otros,2,79.99}
        },
        {
                {21823,"martillo",ferreteria,2,7.5},
                {231,"leche",perecedero,3,0.99},
        }
};

void venderProducto();


int main() {
    int opcion = 0;

    while ( opcion != 2 ) {
        printf("\n\nGestion de ventas de LO.VE.TO.\n\n");
        printf("Menu:\n");
        printf("\t1. Vender producto.\n");
        printf("\t2. Salir.\n");
        printf("Indica opcion: ");
        scanf("%d", &opcion);

        switch( opcion ) {
            case 1:
                venderProducto();
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("[ERROR] Opcion incorrecta.\n");
        }
    }

    return 0;
}


void venderProducto() {
    int cod, q_sol, i = 0, j, q_vend = 0;
    float total = 0;
    bool vendido = false;

    printf("\nVenta de producto.\n");
    printf("\tCodigo de barras: ");
    scanf("%d", &cod);
    printf("\tCantidad solicitada: ");
    scanf("%d", &q_sol);

    while ( !vendido && i < (estantes_ocupados%ESTANTES) ) {
        j = 0;

        while ( !vendido && j < abs(ESTANTES-(estantes_ocupados*i)) ) {
            if ( almacen[i][j].codigo == cod ) {
                if ( almacen[i][j].cantidad > 0 && almacen[i][j].cantidad >= q_sol ) {
                    total += (q_sol*almacen[i][j].precio);
                    almacen[i][j].cantidad -= q_sol;
                    vendido = true;
                } else {
                    total += (almacen[i][j].cantidad * almacen[i][j].precio);
                    q_vend += almacen[i][j].cantidad;
                    q_sol -= almacen[i][j].cantidad;
                    almacen[i][j].cantidad = 0;
                }
            }
            j++;
        }
        i++;
    }

    if ( vendido ) {
        printf("Precio total: %.2f.\n", total);
    } else {
        printf("No se ha podido satisfacer la demanda. Se venden en su "
               "lugar %d unidades por un total de %.2f.\n", q_vend, total);
    }
}
