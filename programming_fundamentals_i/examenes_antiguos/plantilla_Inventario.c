/**********************************************************  
 *  FUNDAMENTOS DE PROGRAMACION I  
 *  CONVOCATORIA EXTRAORDINARIA.  PARTE PRACTICA
 *  GESTIÓN DE ALMACEN Y PEDIDOS 
 *
 *   AUTOR: Indica aquí tu nombre y apellidos 
 *   GRUPO: Indica aqui el grupo de teoria al que perteneces
 * 
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////
// Definicion de constantes utilizadas en el programa
///////////////////////////////////////////////////////////////
#define NUMPROD 10  // Numero maximo de productos en catalogo del almacen
#define MAXPEDIDOS 15  //Numero maximo de pedidos en el almacen
#define MAXLIN 25   // Maximo numero de productos en cada pedido
#define TRUE 1   //Contantes booleana true
#define FALSE 0  //COntante booleana falso

/////////////////////////////////////////////////
//   Tipos definidos por el usuario
/////////////////////////////////////////////////

//Tipo struct que almacena los datos de un producto en el inventario del almacen
typedef struct 
{
 char nombrecomercial[50];
 float cantidad;
 float precio;
}PRODUCTOSTOCK;


//Tipo struct que representa una fecha 
typedef struct 
{
 int dia,mes,anio;   
}FECHA;

//Tipo struct que represetna cada una de los productos en un pedido
struct LINEAPED 
{
    int codigo;
    float cantidad;
};

// Tipo struct que agrupa todos los datos relativos a un  pedido
struct PEDIDO
{
 FECHA fechaped; 
 int nif;
 char Nombre[50];
 int nlineas;
 struct LINEAPED linea[MAXLIN];
};

//Prototipos de todas las funciones creadas en el programa
void ImprimeInventarioMin(PRODUCTOSTOCK inv[]);
void ImprimeInventario(PRODUCTOSTOCK inv[]);
void ActualizaInventario (PRODUCTOSTOCK Inv[], struct PEDIDO ped);
float BuscaPrecio (PRODUCTOSTOCK Inv[], int codigo);
void MuestraPedido (struct PEDIDO pd);
struct PEDIDO AltaPedido();
int LeeProductosPedido(struct LINEAPED lin[]);

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  Main
//  Parametros:  --
//  Retorno: --
//  Tarea realizada: Funcion principal de nuestro programa 
//
////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) 
{
  int  opc;  
  //Inicializacion de las variables para tener datos de prueba
  PRODUCTOSTOCK inventario[NUMPROD]={{"Bujia",12,23.5},{"Silencioso",3,230},{"Bombilla Xenon",432,25.5},{"Carburador",32,125},{"Retrovisor",21,65.3},{"VentiladorAC",3,154.6},{"Junta Culata",14,543},{"Liquido Refrigeración",453,21},{"Aceite",32,76.4},{"Filtro Aceite",121,86}};
  struct PEDIDO listaped[MAXPEDIDOS]={{{7,1,2017},754214,"Arregloto",2,{{0,2},{2,5}}},{{8,1,2017},65894,"AveriasAmi",3,{{3,1},{9,1},{8,1}}}};
  int npedidos=0,ped,codigo;
  do
  {
   printf("1. Alta Pedido.\n");
   printf("2. Muestra Pedido .\n");
   printf("3. Actualizar Inventario.\n");
   printf("4. Imprimir Inventario .\n");
   printf("5. Imprimir Productos Bajo Minimos .\n");
   printf("6. Consultar Precio Producto .\n");
   printf("0. Salir.\n");
   scanf("%d%*c", &opc);
   switch (opc)
   {
       case 0: break;
       case 1: AltaPedido(&listaped[npedidos]);
               npedidos++;
               break;   
       case 2: printf("Indica el pedido a mostrar ");
               scanf ("%d", &ped);
               MuestraPedido(listaped[ped]);
               break;
       case 3: printf("Indica el numero de pedido para actualizar el inventario ");
               scanf ("%d", &ped);
               ActualizaInventario (inventario, listaped[ped]);
               break;
       case 4: ImprimeInventario(inventario);
               break;
       case 5: ImprimeInventarioMin(inventario);
               break;
       case 6: printf("Indica el codigo del producto a consultar ");
               scanf ("%d", &codigo);
               printf(" El precio del producto %d es %f\n", codigo,BuscaPrecio (inventario, codigo));
               break;
     
     default: printf ("Opcion Incorrecta\n");
   }
  }while(opc!=0);
  printf("Bye, Bye. Hasta la proxima\n");
  return (EXIT_SUCCESS);
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  ActualizaInventario 
//  Parametros: Inv. Vector que representa el inventario de todos los productos
//                   del almacen
//              ped.  Pedido que se va a servir y con el que hay que actualizar 
//                    el inventario
//  Retorno: --
//  Tarea realizada: Actualiza la cantidad existente en el inventario de cada 
//                   uno de los productos que tiene el pedido, restando la cantidad
//                   del pedido a la cantidad existente en el inventario
//
////////////////////////////////////////////////////////////////////////////
void ActualizaInventario (PRODUCTOSTOCK Inv[], struct PEDIDO ped)  
{
//Completar esta funcion como respuesta a la pregunta A
}
///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  ImprimeInventarioMin
//  Parametros:  inv. Vector que contiene todo el inventario del almacen 
//  Retorno: --
//  Tarea realizada: Muestra por pantalla los productos cuya cantidad es menor 
//                  de 4  
//
////////////////////////////////////////////////////////////////////////////
void ImprimeInventarioMin(PRODUCTOSTOCK inv[])  
{
 int i;
 for (i=0;i<NUMPROD;i++)
  if (inv[i].cantidad<4) printf("%s\n", inv[i].nombrecomercial);
 
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  ImprimeInventario
//  Parametros:  inv. Vector que contiene todo el inventario del almacen 
//  Retorno: --
//  Tarea realizada: Muestra por pantalla todos los productos del inventario 
//
////////////////////////////////////////////////////////////////////////////
void ImprimeInventario(PRODUCTOSTOCK inv[])
{
 int i;
 printf("Producto , \t Cantidad ,\t  Precio \n");
 for (i=0;i<NUMPROD;i++)
  printf("%s , \t %f ,\t %f \n", inv[i].nombrecomercial,inv[i].cantidad,inv[i].precio);
 
}

///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  BuscaPrecio
//  Parametros: Inv. Vector que representa el inventario de todos los productos
//                   del almacen
//             codigo.  Codigo del producto del que se quiere conocer el precio
//  Retorno: Precio del producto indicado por el codigo.
//  Tarea realizada: Devuelve el precio del producto cuyo codigo se ha
//                   pasado como parametro 
//
////////////////////////////////////////////////////////////////////////////

// REalizar esta funcion como respuesta al apartado B


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  LeeProductosPedido
//  Parametros: lin[]. Vector en el que se almacenan cada uno de los productos
//                     que se tienen en el pedido 
//  Retorno: Numero de productos introducidos.
//  Tarea realizada: Pide por teclado un conjunto de productos y la cantidad 
//                   correspondiente para insertarlo en un pedido. 
//                   Ademas devuelve el numero de productos introducidos  
//
////////////////////////////////////////////////////////////////////////////
int LeeProductosPedido(struct LINEAPED lin[])  
{
//Completar esta funcion como respuesta a la pregunta D
}
///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  AltaPedido
//  Parametros: --
//  Retorno: Datos de un nuevo pedido
//  Tarea realizada: Pide los datos de un nuevo medido y devuelve un struct PEDIDO
//                   con los mismos 
//
////////////////////////////////////////////////////////////////////////////
struct PEDIDO AltaPedido()  
{
//Completar esta funcion como respuesta a la pregunta E
}


///////////////////////////////////////////////////////////////////////////
//
//  Funcion:  MuestraPedido
//  Parametros:  pd. Pedido cuyos datos se quieren mostrar 
//  Retorno: --
//  Tarea realizada: Muestra por pantalla los datos del pedido 
//
////////////////////////////////////////////////////////////////////////////

//define esta funcion como respuesta a la pregunta C


