
#include<stdio.h>
#include<stdlib.h>


////////////////////////////////
//  DEFINICION DE CONSTANTES
////////////////////////////////

#define NPLANT 6   //  Numero de plantas que tiene el hotel
#define NHAB 23    //   Numero de habitaciones por planta
#define LIBRE -1  //    Constante para marcar las habitaciones libres

/////////////////////////////////////////////////////
//   Tipo de datos utilizado para almacenar los datos
//   del cliente que hace una reserva
//
/////////////////////////////////////////////////////
typedef struct
{
    int DNI;

 // Completar esta definición
}Reserva;

///////////////////////////////////////////////////////////////////////////
//
//  Tipo de datos que representa el hotel.
// Es una matriz donde cada fila representa una planta y
// cada columna una habitación.
// Los elementos de la matriz son los datos de la reserva si existe.
// Si la habitación está libre en el campo DNI se pone el valor LIBRE
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
void VaciaHotel (Hotel hab)
{
 int p,h;
 for(p=0;p<NPLANT;p++)
  for (h=0;h<NHAB;h++)
   hab[p][h].DNI=LIBRE;
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
??? MuestraReservas (?????)
{
 //Completar esta funcion
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  BuscaHabitación
//  Parametros:  Matriz que representa el hotel
//               Parametro por referencia para obtener la planta de la habitacion
//               Parametro por referencia para devolver el numero de habitacion
//  Retorno:  Numero de planta y de habitacion selecionada.  (Por referencia)
//  Tarea realizada: Busca una habitación libre para poder ser reservada.
//                   Empieza por la ultima planta y va descendiendo
//                   Si no hay habitaciones libres devuelve en planta el valor -1
//
////////////////////////////////////////////////////////////////////////////
??? BuscaHabitacion(???)
{
  //Completar esta funcion
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  PideDatos
//  Parametros:  --
//  Retorno: Variable del tipo Reserva con los datos del cliente
//  Tarea realizada: Pide al usuario que introduzca los datos de la reserva
//
////////////////////////////////////////////////////////////////////////////
Reserva PideDatos()
{
  //Completar esta funcion
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  HacerReserva
//  Parametros:  Matriz que representa el hotel
//  Retorno: 0 si está lleno y 1 si no lo está
//  Tarea realizada: Realiza la reserva de una habitación.
//                   Primero busca una habitación libre y luego pide los datos
//
////////////////////////////////////////////////////////////////////////////
??? HacerReserva(???)
{

}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  AnulaReserva
//  Parametros:  Matriz que representa el hotel
//               Identificacion de la reserva mediante el numero de planta y de hab
//  Retorno: --
//  Tarea realizada: Marca una habitación como libre poniendo en DNI el valor
//                   LIBRE
//
////////////////////////////////////////////////////////////////////////////
void AnulaReserva(Hotel hab,int pl, int ha)
{
  //Completar esta funcion
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  Main
//  Parametros:  --
//  Retorno: --
//  Tarea realizada: Programa principal
//
////////////////////////////////////////////////////////////////////////////
void main()
{
 Hotel habitaciones;
 int opc,pl,hab;
 VaciaHotel(habitaciones);
 do
 {
  printf("1.- Hacer reserva\n");
  printf("2.- Mostrar mapa de reservas\n");
  printf("3.- Anular Reserva\n");
  printf("4.- Finalizar\n");
  printf("Introduce una opcion:  ");
  scanf("%d",&opc);

  switch (opc)
  {
      case 1: //Completar
              break;
      case 2: // Completar
          break;
      case 3: printf("Indica reserva a anular\n");
              printf(" Planta :");
              scanf("%d", &pl);
              printf(" Habitación :");
              scanf("%d", &hab);
              // Completar
              break;
      case 4: printf("HASTA PRONTO\n");
              break;

  }
 }while (opc!=4);
}
