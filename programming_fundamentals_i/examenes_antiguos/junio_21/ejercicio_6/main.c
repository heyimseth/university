/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 ******************************************************************************/
#include <stdio.h>
#define Q_CAT 250

typedef struct {
    unsigned short int d, m, y;
} FECHA;

typedef struct {
    char codigo[11], nombre[26];
    int q_stock;
    float precio;
} PRODUCTO;

typedef struct {
    int num;
    FECHA fecha;
    char nif[10], taller[21];
    int productos[20][2];
} PEDIDO;


void pedido( PRODUCTO i[Q_CAT] );
void mostrarProducto( PRODUCTO p );


int main() {
    PRODUCTO catalogo[Q_CAT];
    PEDIDO pedidos[1500];

    pedido(catalogo);

    return 0;
}

void pedido( PRODUCTO i[Q_CAT] ) {
    for ( int p = 0; p < Q_CAT; p++ ) {
        if ( i[p].q_stock < 4 ) mostrarProducto(i[p]);
    }
}

void mostrarProducto( PRODUCTO p ) {
    printf("\nCod: %s\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Cantidad: %d\n", p.q_stock);
    printf("Precio (sin I.V.A.): %.2f\n", p.precio);
}
