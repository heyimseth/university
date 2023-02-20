/* 
 * File:   main.c
 * Author: Alvaro Martinez Alfaro
 *
 * Created on 
 */

// Incluir E/S y Librerias Standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define N_ABON 100
#define N_TRAM 3


// Zona de Declaracion de Constantes
const double TARIFA_D[] = {0.51,0.67,0.92}; // Precio por tramos
const double TARIFA_I[] = {0.61,0.70,0.99};
const int LIM_TRAMOS[] = {10,50,9999};      // límites m3 tramos


// Zona de Declaracion de Tipos
typedef struct p {
        bool creado;        // registro creado
        bool domestico;     // indica si es doméstico o industrial
        int num_abon;       // número abonado
        int l_ant, l_act;   // Lectura Anterior, Lectura Actual m3
	    char nombre[40];        // nombre
 }Tr_abon;

// tipo array con la informacion de los abonados
typedef  Tr_abon Tabonados[N_ABON];

typedef float Ttarifa[N_TRAM];


// Zona de Declaracion prototipos
void nuevoAbon(Tabonados abonados);                     // crea un nuevo abonado desde el teclado
void recibo(Tabonados abonados);                        // Muestra el recibo del abonado
void muestra(Tabonados abonados, int num);              // muestra un determinado abonado
void muestraTotal(Tabonados abonados);                  // Muestra el importe total de los recibos
int nextAbon(Tabonados abonados);                       // obtiene número del siguiente abonado
void dameTarifa(Ttarifa tarifa, bool domestico);        // devuelve la tarifa según el contrato
double calculaRecibo(Tabonados abonados, int n_abon);
char menu();
bool confirmarSalida();
void pausa();
void clrscr();


// Programa Principal
int main() {
  Tabonados abonados={
	true,true,0,0,30,"JUAN PEREZ",
	true,true,1,10,50,"ANDRES RAMOS",
	true,true,2,10,70,"CHI S.L.",
        false,false,0,0,0,"",
        false,false,0,0,0,"",
        false,false,0,0,0,""
	};  // array con los Abonados
                  
  bool salir = false;
  char op_menu;

  while (!salir) {
    clrscr();
    op_menu = menu();

    switch (op_menu) {
      case 'A':
        printf("A --> Nuevo Abonado\n");
        nuevoAbon(abonados);
        break;
      case 'B':
        printf("B--> Muestra Recibo\n");
        recibo(abonados);
        break;
       case 'C':
        printf("C--> Calcula Totales\n");
        muestraTotal(abonados);
        break;
      case 'X':
        salir = confirmarSalida();
        break;
    }
    pausa();
  }
  return 0;
}


// Zona de Implementacion de PROC/FUNC
char menu() {
  char op;
  printf("MENU\n\n");
  printf("A--> Nuevo Abonado\n");
  printf("B--> Muestra Recibo\n");
  printf("C--> Calcula Totales\n");
  printf("X--> Salir del Programa\n");

  do {
    printf("\nOpcion: ");
   // fflush(stdin); //limpia el buffer del teclado
    scanf(" %c", &op);
    op = toupper(op);// Paso op a mayusculas
  }while ( (op!='X') && ((op<'A')||(op>'D')) );
  return op;
}

bool confirmarSalida(){
  char si_no;
  fflush(stdin); //limpia el buffer del teclado
  printf("\nEsta seguro de que quiere salir (S/N)?: ");
  scanf(" %c", &si_no);
  return (toupper(si_no) == 'S');
}

// Una implementacion de pausa y clrscr llamando a funciones del S.O.

void pausa() {
  system("pause");
}

void clrscr() {
  system("cls");
}

/* Lee el número del abonado por teclado*/
int getNumAbon(){
    int n;
    do{
    printf("\n ABONADO#? : ");
    //fflush(stdin); //limpia el buffer del teclado
    scanf(" %d", &n);
  }while ( ((n<0)||(n>N_ABON)) );
  return n;
}

//devuelve array con la tarifa según el contrato
void dameTarifa(Ttarifa tarifa, bool domestico){
    for ( int i = 0; i < N_TRAM; i++ ) {
        if ( domestico ) {
            tarifa[i] = TARIFA_D[i];
        } else {
            tarifa[i] = TARIFA_I[i];
        }
    }
}


/* calcula el importe del un recibo de un abonado */
double calculaRecibo(Tabonados abonados, int n_abon){
  int consumo;
  double importe=0;
  Ttarifa tarifa;
  
  dameTarifa(tarifa,abonados[n_abon].domestico);
  consumo = abonados[n_abon].l_act-abonados[n_abon].l_ant;

  printf("%d\n", consumo);

  if ( consumo <= LIM_TRAMOS[0] ) {
      importe = consumo * tarifa[0];
  } else if ( consumo <= LIM_TRAMOS[1] ) {
      importe = consumo * tarifa[1];
  } else {
      importe = consumo * tarifa[2];
  }

  return importe;
}

/*Muestra los datos del titular de un recibo*/
void muestra(Tabonados abonados, int num){
  
  if( abonados[num].creado) {
    printf("ABONADO# : %d\n", abonados[num].num_abon);
    printf("NOMBRE : %s\n", abonados[num].nombre);
    if ( abonados[num].domestico ) printf("CONTRATO DOMESTICO\n");
    else printf("CONTRATO INDUSTRIAL\n");
    printf("L. ANT :%d - L. ACT:%d\n", abonados[num].l_ant,
           abonados[num].l_act);
  } else
    printf("\n abonado %d no existe\n", num);
}

void recibo(Tabonados abonados){
  int n_abon;
  double importe;

  n_abon = getNumAbon();
  importe =calculaRecibo(abonados,n_abon);
  muestra(abonados,n_abon);
  printf("\n IMPORTE RECIBO : %.2f \n",importe);
}

/*Muestra el total de la suma de los recibos*/
void muestraTotal(Tabonados abonados){
  double total = 0;

  for ( int i = 0; i < nextAbon(abonados); i++ ) {
      total += calculaRecibo( abonados, i );
  }

  printf("\n\nIMPORTE TOTAL RECIBOS : %.2f \n",total);
}

int nextAbon(Tabonados abonados){
    int next = -1, i = 0;

    do {
        if ( abonados[i].creado == false ) next = i;
        i++;
    } while ( i < N_ABON && next == -1 );

    return next;
}

void nuevoAbon(Tabonados abonados){
  
  int n_abon ;
   
  n_abon = nextAbon(abonados); //buscamos siguiente posición creado en el array
  
  abonados[n_abon].num_abon = n_abon;
  abonados[n_abon].creado = false;
  printf("\n NOMBRE?: ");
  fflush(stdin);
  //Lee Nombre 
  gets(abonados[n_abon].nombre);
    //Lee Lectura Anterior
  printf("\n LECTURA ANTERIOR?: ");
  scanf(" %d",&abonados[n_abon].l_ant);
   //Lee Lectura Actual
  printf("\n LECTURA ACTUAL?: ");
  scanf(" %d",&abonados[n_abon].l_act);
}