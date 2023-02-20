#include<stdio.h>
#include<stdlib.h>
#define NPLANT 6   //  Numero de plantas que tiene el hotel
#define NHAB 23    //   Numero de habitaciones por planta
#define LIBRE (-1)  //    Constante para marcar las habitaciones libres

typedef struct fecha {
    int d;
    int m;
    int y;
};

/////////////////////////////////////////////////////
//   Tipo de datos utilizado para almacenar los datos
//   del cliente que hace una reserva
//
/////////////////////////////////////////////////////
typedef struct {
    int DNI;
    char nombre[30];
    char apellido[50];
    int telefono;
    unsigned long long int tarjeta;
    struct fecha entrada;
    struct fecha salida;
} Reserva;

///////////////////////////////////////////////////////////////////////////
//
//  Tipo de datos que representa el hotel.
// Es una matriz donde cada fila representa una planta y
// cada columna una habitaci�n.
// Los elementos de la matriz son los datos de la reserva si existe.
// Si la habitaci�n est� libre en el campo DNI se pone el valor LIBRE
//
////////////////////////////////////////////////////////////////////////////
typedef Reserva Hotel[NPLANT][NHAB];



///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  VaciaHotel
//  Parametros:  Matriz que representa el hotel
//  Retorno: --
//  Tarea realizada: Asigna al campo DNI de todas las habitaciones
//                   el valor LIBRE para indicar que todo el hotel esta vacio
//
////////////////////////////////////////////////////////////////////////////
void VaciaHotel( Hotel hab ) {
    int p,h;

    for (p = 0; p < NPLANT; p++ ) {
        for (h = 0; h < NHAB; h++ ) {
            hab[p][h].DNI = LIBRE;
        }
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  MuestraReservas
//  Parametros:  Matriz que representa el hotel
//  Retorno: --
//  Tarea realizada: Muestra por pantalla, en forma de matriz el esquema del hotel
//                   Muestra una L si la habitacion esta libre
//                   Muestra una O si la habitacion esta ocupada
//
////////////////////////////////////////////////////////////////////////////
void MuestraReservas( Hotel hab ) {
    printf("\n\tPlano de reservas:\n");
    for ( int i = 0; i < NPLANT; i++ ) {
        printf("Planta %d:\t", i+1);
        for ( int j = 0; j < NHAB; j++ ) {
            if ( hab[i][j].DNI == LIBRE ) {
                printf("L ");
            } else {
                printf("R ");
            }
        }
        printf("\n");
    }
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion: BuscaHabitacion
//  Parametros: Matriz que representa el hotel
//              Parametro por referencia para obtener la planta de la habitacion
//              Parametro por referencia para devolver el numero de habitacion
//  Retorno: Numero de planta y de habitacion selecionada. (Por referencia)
//  Tarea realizada: Busca una habitaci�n libre para poder ser reservada.
//                   Empieza por la ultima planta y va descendiendo
//                   Si no hay habitaciones libres devuelve en planta el valor -1
////////////////////////////////////////////////////////////////////////////
void BuscaHabitacion( Hotel hab, int *planta, int *habitacion ) {
    *planta = -1;
    *habitacion = -1;
    int i = NPLANT-1, j = 0;

    do {
        do {
            if ( hab[i][j].DNI == LIBRE ) {
                *planta = i;
                *habitacion = j;
            }
            j++;
        } while ( j < NHAB && *habitacion == -1 );
        i--;
        j = 0;
    } while ( *planta == -1 && i >= 0 );
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion: PideDatos
//  Parametros:  --
//  Retorno: Variable del tipo Reserva con los datos del cliente
//  Tarea realizada: Pide al usuario que introduzca los datos de la reserva
//
////////////////////////////////////////////////////////////////////////////
Reserva PideDatos() {
    Reserva cliente;

    printf("Indica, a continuacion, los datos del cliente.\n");
    printf("Indica DNI: ");
    scanf("%d", &cliente.DNI);
    printf("Indica nombre:");
    fflush(stdin);
    gets(cliente.nombre);
    printf("Indica apellido: ");
    fflush(stdin);
    gets(cliente.apellido);
    printf("Indica telefono: ");
    scanf("%d", &cliente.telefono);
    printf("Indica tarjeta para el pago: ");
    scanf("%llu", &cliente.tarjeta);
    printf("Indica fecha de entrada (formato DD/MM/AAAA): ");
    scanf("%d/%d/%d", &cliente.entrada.d, &cliente.entrada.m,
          &cliente.entrada.y);
    printf("Indica fecha de salida (formato DD/MM/AAAA): ");
    scanf("%d/%d/%d", &cliente.salida.d, &cliente.salida.m,
          &cliente.salida.y);

    return cliente;
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion: HacerReserva
//  Parametros: Matriz que representa el hotel
//  Retorno: 0 si esta lleno y 1 si no lo esta
//  Tarea realizada: Realiza la reserva de una habitacion.
//                   Primero busca una habitacion libre y luego pide los datos
//
////////////////////////////////////////////////////////////////////////////
int HacerReserva( Hotel hab ) {
    int planta, habitacion;
    Reserva cli;

    BuscaHabitacion( hab, &planta, &habitacion );
    if ( planta != -1 ) {
        cli = PideDatos();
        hab[planta][habitacion] = cli;
        return 1;
    } else {
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion: AnulaReserva
//  Parametros: Matriz que representa el hotel
//              Identificacion de la reserva mediante el numero de planta y de hab
//  Retorno: --
//  Tarea realizada: Marca una habitacion como libre poniendo en DNI el valor
//                   LIBRE
//
////////////////////////////////////////////////////////////////////////////
void AnulaReserva( Hotel hab, int pl, int ha ) {
    hab[pl][ha].DNI = LIBRE;
}

/*******************************************************************************
 *
 * Funcion: totalPorHabitacion
 * Parametros: Matriz del hotel
 *             Vector de NHAB posiciones para sumar las habitaciones libres
 * Retorno: Vector con la suma de habitaciones libres por numero de habitacion
 * Tarea: almacena en el vector pasado por parametro la suma de habitaciones
 *        libres en funcion del numero de habitacion
 *
 ******************************************************************************/
void totalPorHabitacion( Hotel hab, int libres[NHAB] ) {
    int h = 0, suma = 0;

    for ( int i = 0; i < NPLANT; i++ ) {
        for ( int j = 0; j < NHAB; j++ ) {

        }
    }
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  Main
//  Parametros:  --
//  Retorno: --
//  Tarea realizada: Programa principal
//
////////////////////////////////////////////////////////////////////////////
void main() {
    Hotel habitaciones;
    int opc,pl,hab;

    VaciaHotel(habitaciones);

    do {
        printf("\n1.- Hacer reserva\n");
        printf("2.- Mostrar mapa de reservas\n");
        printf("3.- Anular Reserva\n");
        printf("4.- Finalizar\n");
        printf("Introduce una opcion:  ");
        scanf("%d",&opc);

        switch (opc) {
            case 1:
                HacerReserva(habitaciones);
                break;
            case 2:
                MuestraReservas( habitaciones );
                break;
            case 3:
                printf("Indica reserva a anular\n");
                MuestraReservas(habitaciones);
                printf(" Planta :");
                scanf("%d", &pl);
                printf(" HabitaciOn :");
                scanf("%d", &hab);
                AnulaReserva(habitaciones, pl, hab);
                printf("\nReserva anulada.\n");
                MuestraReservas(habitaciones);
                break;
            case 4: printf("HASTA PRONTO\n");
                break;
        }
    } while (opc!=4);
}
