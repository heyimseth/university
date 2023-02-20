/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciados:
 *      13. Crea un tipo de datos que permita almacenar la informacion relativa
 *          a un evento, y al que se denominara EVENTO. Dicho evento podra ser
 *          un ingreso o un alta; se producira en una fecha y horas determinadas
 *          y afectara a un paciente, que tendra un DNI y un nombre. Para el
 *          tipo de evento utilizaremos una enumeracion; para la fecha y horas,
 *          los tipos de estructuras que se han definido anteriormente; para el
 *          DNI un entero; y para el nombre una cadena de caracteres.
 *      14. Implementar una funcion que imprima un objeto del tipo EVENTO.
 *      15. Implementar una funcion que lea los datos de un evento.
 *      16. Crear un array de tamano 500 para almacenar todos los eventos que se
 *          producen en un dia y definir una variable donde se registre el
 *          numero de eventos almacenados. Definir ambas variables como globales
 *      17. Crear una funcion que tome como parametro la posicion del vector
 *          creado en el ejercicio 16, lea (utilizando la funcion definida en el
 *          ejercicio 15) la informacion de un evento, y la almacene en la
 *          posicion del vector correspondiente. Implementar una funcion similar
 *          para imprimir un evento (utilizando la funcion existente).
 *      18. Implementar una funcion que anada un evento en el array, utilizando
 *          la funcion definida en el ejercicio 17 y la variable global donde
 *          se registra el numero de eventos almacenados.
 *      19. Implementar una funcion que determine si un paciente ha sido
 *          ingresado en un dia determinado. Para ello, se utilizara su DNI.
 *          Ha de recibir un entero como parametro (el DNI) y utilizar el array
 *          y el numero de pacientes. Debe devolver el indice donde esta el
 *          paciente, o -1 si no lo esta.
 ******************************************************************************/
#include <stdio.h>

typedef enum { ingreso, alta } TIPO_EVENTO;

typedef struct {
    int d, m, a;
} FECHA;

typedef struct {
    int h, m;
} HORA;

typedef struct {
    int DNI;
    char nombre[50];
} PACIENTE;

typedef struct {
    TIPO_EVENTO tipo;
    PACIENTE paciente;
    FECHA fecha;
    HORA hora;
} EVENTO;


void mostrarFecha( FECHA f );
void mostrarEvento( EVENTO e );
void crearEvento();
int buscarPaciente( int dni );

const char MESES[12][10] = {"enero","febrero","marzo","abril",
                            "mayo","junio","julio","agosto",
                            "septiembre","octubre","noviembre",
                            "diciembre"};

int numero_eventos = 0;
EVENTO eventos[500];


int main() {
    int pos_paciente;

    crearEvento();
    pos_paciente = buscarPaciente(49310980);
    if ( pos_paciente != -1 ) {
        printf("El paciente ha sido ingresado.\n");
    } else {
        printf("No hay registros de ingreso del paciente.\n");
    }

    return 0;
}


void mostrarFechaNumerica( FECHA f ) {
    printf("%02d/%02d/%4d\n", f.d, f.m, f.a);
}

void mostrarFecha( FECHA f ) {
    printf("%02d de %s de %04d.\n", f.d, MESES[f.m-1], f.a);
}

void mostrarHora( HORA h ) {
    printf("%02d:%02d.\n", h.h, h.m);
}

FECHA leerFecha() {
    FECHA f;

    printf("Indica una fecha (DD/MM/AAAA): ");
    scanf("%2d/%2d/%4d", &f.d, &f.m, &f.a);

    return f;
}

HORA leerHora() {
    HORA h;

    printf("Indica una hora (HH:MM): ");
    scanf("%2d:%2d", &h.h, &h.m);

    return h;
}

PACIENTE leerDatosPaciente() {
    PACIENTE p;

    printf("Indica DNI: ");
    scanf("%8d", &p.DNI);
    printf("Indica nombre completo: ");
    fflush(stdin);
    gets(p.nombre);

    return p;
}

TIPO_EVENTO leerTipoEvento() {
    TIPO_EVENTO t;

    printf("Indica tipo de evento (0: ingreso, 1: alta): ");
    scanf("%d", &t);

    return t;
}

EVENTO leerDatosEvento() {
    EVENTO e;

    e.tipo = leerTipoEvento();
    e.paciente = leerDatosPaciente();
    e.fecha = leerFecha();
    e.hora = leerHora();

    return e;
}

void mostrarEvento( EVENTO e ) {
    if ( e.tipo == 0 ) {
        printf("INGRESO\n");
    } else {
        printf("ALTA\n");
    }
    printf("Paciente:\n");
    printf("\tDNI: %08d\n", e.paciente.DNI);
    printf("\tNombre: %s.\n", e.paciente.nombre);
    printf("\tFecha: ");
    mostrarFecha(e.fecha);
    printf("\tHora: ");
    mostrarHora(e.hora);
}

void crearEvento() {
    eventos[numero_eventos] = leerDatosEvento();
    numero_eventos++;
}

int buscarPaciente( int dni ) {
    int pos = -1, i = 0;

    while ( i < numero_eventos && pos == -1 ) {
        if ( dni == eventos[i].paciente.DNI && eventos[i].tipo == ingreso ) {
            pos = i;
        }
        i++;
    }

    return pos;
}
