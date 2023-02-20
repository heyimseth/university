/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: una pequena tienda de fotografia quiere informatizar el proceso de
 *            gestion de revelado de fotografias. En este proceso, cuando un
 *            cliente llega a la tienda con sus fotos, el encargado de la tienda
 *            rellena una ficha con un numero de solicitud, el nombre y
 *            apellidos del cliente, un numero de telefono de contacto, tipo de
 *            revelado (digital o tradicional), el tipo de papel (mate, brillo,
 *            satinado) y la fecha de entrega del pedido. Posteriormente,
 *            cuando el pedido es enviado al laboratorio, se anota en la misma
 *            ficha la fecha en la que es enviado. Por ultimo, cuando el pedido
 *            vuelve del laboratorio, el encargado de la tienda anota la fecha
 *            de vuelta asi como el numero de fotos que se han obtenido. Segun
 *            estimaciones del encargado de la tienda sabemos que a lo largo de
 *            un dia en la tienda se reciben un maximo de 30 solicitudes de
 *            revelado. Definir los tipos de datos necesarios para almacenar la
 *            informacion de todas las solicitudes de revelado de un dia.
 ******************************************************************************/
#include <stdio.h>
#define MAX_SOLICITUDES 30

typedef enum {digital, tradicional} TIPO_REVELADO;
typedef enum {mate, brillo, satinado} TIPO_PAPEL;

typedef struct {
    int d, m, a;
} TIPO_FECHA;

typedef struct {
    int num;
    char nombre_completo[50];
    int telefono;
    TIPO_REVELADO revelado;
    TIPO_PAPEL papel;
    TIPO_FECHA fechas[3]; // 0: fecha pedido; 1: fecha envio lab; 2: fecha vuelta lab
    int cantidad_fotos;
} FICHA;

int cantidad_solicitudes = 0;
FICHA solicitudes_dia[MAX_SOLICITUDES];


int main() {
    printf("Hello, World!\n");
    return 0;
}
