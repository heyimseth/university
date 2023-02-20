/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro, ...
 * Grupo: 1B
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX_F_ALB 5 // cantidad maxima de albaranes
#define MAX_P_ALM 15 //cantidad maxima de productos distintos en almacen
#define MAX_D_PRO 75 // cantidad maxima de caracteres en la descripcion

// solicita los datos para un nuevo albaran al usuario
// albaranes: matriz donde se van a almacenar los albaranes
// q_alb: cantidad de albaranes que se encuentran actualmente en albaranes
// cantidad_productos: vector de cantidad disponible en almacen de cada producto
// q_alm: cantidad total de productos en almacen
void introducirAlbaran( int albaranes[MAX_F_ALB][MAX_P_ALM], int *q_alb,
                        int cantidad_productos[MAX_P_ALM], int q_alm );

// confecciona y muestra por pantalla la factura de los albaranes
// productos: matriz con las descripciones de los productos
// albaran: matriz de albaranes
// precios: vector con los precios de productos
// q_alb: cantidad de albaranes pendientes de procesar en albaranes
void factura( char productos[MAX_P_ALM][MAX_D_PRO], float precios[MAX_P_ALM],
              int albaranes[MAX_F_ALB][MAX_P_ALM], int *q_alb,
              int descuentos[MAX_P_ALM]);

// introducir articulos disponibles en almacen
// productos: matriz con las descripciones de los productos
// precios: vector de precios de productos
// cantidad_productos: vector con las cantidades disponibles de cada producto
// q_alm: cantidad de productos en el almacen
void addArt(char productos[MAX_P_ALM][MAX_D_PRO], float precios[MAX_P_ALM],
            int cantidad_productos[MAX_P_ALM], int *q_alm,
            int descuentos[MAX_P_ALM] );


int main() {
    int albaranes[MAX_F_ALB][MAX_P_ALM], cantidad_productos[MAX_P_ALM],
    descuentos[MAX_P_ALM];
    float precios[MAX_P_ALM];
    int q_alb=0, q_alm=0, opcion;
    char productos[MAX_P_ALM][MAX_D_PRO];

    // inicializacion de albaranes a 0
    for (int i = 0; i < MAX_F_ALB; i++)
        for ( int j = 0; j < MAX_P_ALM; j++ )
            albaranes[i][j] = 0;

    do {
        printf("\n1. Introducir albaranes.\n");
        printf("2. Confeccion de factura.\n");
        printf("3. Introduccion de nuevo articulo.\n");
        printf("4. Salir del programa.\n>> ");
        scanf("%d", &opcion);

        switch ( opcion ) {
            case 1:
                introducirAlbaran( albaranes, &q_alb, cantidad_productos,
                                   q_alm );
                break;
            case 2:
                factura( productos, precios, albaranes, &q_alb, descuentos);
                break;
            case 3:
                addArt ( productos, precios, cantidad_productos, &q_alm, descuentos );
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("[ERROR] Opcion no disponible.");
        }
    } while ( opcion != 4 );
    return 0;
}

void introducirAlbaran( int albaranes[MAX_F_ALB][MAX_P_ALM], int *q_alb,
                        int cantidad_productos[MAX_P_ALM], int q_alm ) {
    int num_articulos = 0, num_ref, i = 0, cantidad;

    // comprobamos que no se haya alcanzado al limite de albaranes pendientes
    if ( *q_alb >= MAX_F_ALB ) {
        printf("\n[ERROR] Limite de albaranes alcanzado. Acceda primero "
               "a la opcion 2 para confeccionar la factura.\n\n");
        return;
    }

    // comprobamos que haya articulos en almacen para poder vender
    if ( q_alm <= 0 ) {
        printf("\n[ERROR] No hay productos en almacen para vender. Acceda"
               " primero a la opcion 3 para incluir algunos.\n\n");
        return;
    }

    // solicitar al usuario el numero de articulos que va a introducir (como
    // minimo sera 1)
    do {
        printf("Indica el numero de articulos a introducir: ");
        scanf("%d", &num_articulos);

        if ( num_articulos < 1 || num_articulos > MAX_P_ALM ) {
            printf("\n[ERROR] La cantidad minima es 1 y la cantidad "
                   "maxima es %d.\n\n", MAX_P_ALM);
        }
    } while ( num_articulos < 1 || num_articulos > MAX_P_ALM );

    // se solicitan los articulos que forman el albaran
    do {
        printf("Indica numero de referencia (0-15): ");
        scanf("%d", &num_ref);
        printf("Indica cantidad: ");
        scanf("%d", &cantidad);


        if ( num_ref >= 0 && num_ref < q_alm ) { // existe la ref indicada
            if ( cantidad_productos[num_ref] > 0 ) { // hay uds. disponibles
                if ( cantidad < cantidad_productos[num_ref] ) { // uds. suficientes
                    albaranes[*q_alb][num_ref] = cantidad;
                    cantidad_productos[num_ref] -= cantidad;
                } else { // uds. insuficientes
                    printf("\n[AVISO] No hay unidades suficientes en "
                           "almacen, se realiza la venta de %d en su lugar.\n\n",
                           cantidad_productos[num_ref]);
                    albaranes[*q_alb][num_ref] = cantidad_productos[num_ref];
                    cantidad_productos[num_ref] = 0;
                }
                i++;
            } else { // no hay uds. disponibles
                printf("\n[ERROR] No hay unidades disponibles.\n\n");
            }
        } else {
            printf("\n[ERROR] Numero de referencia indicado no existe.\n\n");
        }
    } while ( i < num_articulos );
    (*q_alb)++;
}

void factura( char productos[MAX_P_ALM][MAX_D_PRO], float precios[MAX_P_ALM],
              int albaranes[MAX_F_ALB][MAX_P_ALM], int *q_alb,
              int descuentos[MAX_P_ALM] ) {
    int i, j, cantidad[MAX_P_ALM]={0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0};
    double total=0,suma=1, final, ahorro = 0, importe;

    if (*q_alb > 0) {
        for (i = 0; i < *q_alb; ++i) {
            for (j = 0; j < MAX_P_ALM; ++j) {
                if (albaranes[i][j] != 0) cantidad[j] = cantidad[j] + albaranes[i][j];
            }
        }
        printf("FACTURA\n");
        printf("Descripcion%-65s\tCantidad Precio\tImporte\tDESC\tFINAL\n", "");
        printf("========================================================================================================================\n");
        for (i = 0; i < MAX_P_ALM; ++i) {
            if (cantidad[i] != 0) {
                printf("%-75s", productos[i]);
                importe = (double) cantidad[i] * precios[i];
                ahorro += (importe * descuentos[i])/100;
                final = importe - (importe * descuentos[i])/100;
                total = total + importe;
                printf("\t%d\t%.2f\t%.2f\t%d%\t%.2f\n", cantidad[i], precios[i], importe, descuentos[i], final);
                suma = 1;
            }
        }
        printf("========================================================================================================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\tTotal: %.2f\n", total);
        printf("\t\t\t\t\t\t\t\t\t\t\t\tAhorro: %.2f\n", ahorro);
        printf("\t\t\t\t\t\t\t\t\t\t\t\tA pagar: %.2f\n", total-ahorro);
        *q_alb = 0;
    } else printf("\n[ERROR] No has introducido albaranes.\n\n");
}

void addArt( char productos[MAX_P_ALM][MAX_D_PRO], float precios[MAX_P_ALM],
             int cantidad_productos[MAX_P_ALM], int *q_alm,
             int descuentos[MAX_P_ALM]) {
    if (*q_alm == MAX_P_ALM) {
        printf("El almacen esta lleno, no se pueden traer productos nuevos.\n");
        return;
    }

    char desc[MAX_D_PRO];
    float pre;
    int stk;
    int descuento = -1;

    printf("Introduce descripcion (max. %d caracteres): ", MAX_D_PRO);
    fflush(stdin);
    gets (desc);

    do {
        puts ("Introduce precio: ");
        scanf ("%f", &pre);
    } while (pre <= 0);

    do {
        puts ("Introduce stock: ");
        scanf ("%d", &stk);
    } while (stk <= 0);

    do {
        printf("Indica descuento a aplicar: ");
        scanf("%d", &descuento);
    } while ( descuento < 0 );


    strcpy (productos[*q_alm], desc);
    precios[*q_alm] = pre;
    cantidad_productos[*q_alm] = stk;
    descuentos[*q_alm] = descuento;

    (*q_alm)++;
}
