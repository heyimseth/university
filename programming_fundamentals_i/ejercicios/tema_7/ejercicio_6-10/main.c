/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciados:
 *      6. Crea un tipo de datos (struct) para almacenar fechas, y denominalo
 *         FECHA, y otro para almacenar horas, y denominalo HORA. Crea dos
 *         variables para almacenar el dia y hora en el que se produjeron dos
 *         eventos, como por ejemplo, el ingreso y el alta de un paciente en un
 *         hospital.
 *      7. Crear una funcion que imprimar el valor de una variable del tipo
 *         FECHA descrito anteriormente en formato DD/MM/AAAA.
 *      8. Crear una funcion que imprima el valor de una variable del tipo FECHA
 *         descrito anteriormente en formato "Dia de Mes de Ano". Para ello,
 *         definir un vector de cadenas de caracteres que, en cada posicion,
 *         almacene el nombre del mes. Dicho vector ha de estar declarado como
 *         variable global constante, y será accedido desde la funcion para
 *         imprimir directamente con el numero de mes (sin utilizar un switch).
 *      9. Crear una funcion que lea una FECHA. Dicha funcion no debe recibir
 *         ningun parametro de entrada, pero devuelve la fecha nueva.
 *     10. Implementar una funcion que lea una fecha pero pasandole un puntero a
 *         la variable fecha que debe leer, es decir, utilizando paso por
 *         referencia. La funcion no debe devolver nada.
 ******************************************************************************/
#include <stdio.h>

typedef struct {
    int d, m, a;
} FECHA;

typedef struct {
    int h, m;
} HORA;

void mostrarFechaNumerica( FECHA f );
void mostrarFecha( FECHA f );
// FECHA leerFecha();
void leerFecha( FECHA *f );

const char MESES[12][10] = {"enero","febrero","marzo","abril",
                            "mayo","junio","julio","agosto",
                            "septiembre","octubre","noviembre",
                            "diciembre"};


int main() {
    FECHA fecha_ingreso, fecha_alta;
    HORA hora_ingreso, hora_alta;

//    fecha_ingreso = leerFecha();
    leerFecha(&fecha_ingreso);
    mostrarFechaNumerica(fecha_ingreso);
    mostrarFecha(fecha_ingreso);

    return 0;
}


void mostrarFechaNumerica( FECHA f ) {
    printf("%02d/%02d/%4d\n", f.d, f.m, f.a);
}

void mostrarFecha( FECHA f ) {
    printf("%02d de %s de %04d.\n", f.d, MESES[f.m-1], f.a);
}

//FECHA leerFecha() {
//    FECHA f;
//
//    printf("Indica una fecha (DD/MM/AAAA): ");
//    scanf("%2d/%2d/%4d", &f.d, &f.m, &f.a);
//
//    return f;
//}

void leerFecha( FECHA *f ) {
    printf("Indica una fecha (DD/MM/AAAA): ");
    scanf("%2d/%2d/%4d", &f->d, &f->m, &f->a);
}
