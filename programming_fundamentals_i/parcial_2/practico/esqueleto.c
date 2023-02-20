#include<stdio.h>
#include<stdlib.h>



#define FILAS 5   // Número de filas de la matriz
#define COLUMNAS 10   // Número columnas de lamatriz
#define LIBRE -1  // Constante para marcar las casillas libres de la matriz.


typedef struct
{
    int IDContenedor; // número único para cada contenedor.
    char contenido[20]; // nombre descriptivo del contenido.
    int peso;// peso del contenedor
    char nombreOrigen[20]; // nombre de la empresa que envía el contenedor
    char nombreDestino[20]; // nombre de la empresa que recibe el contenedor.


}Contenedor;



typedef Contenedor Almacen[FILAS][COLUMNAS];



void muestraAlmacen (Almacen AL)
{
    for(int p=0;p<FILAS;p++)
    {
        for (int h=0;h<COLUMNAS;h++)
            if (AL[p][h].IDContenedor==LIBRE) printf ("L  ");
            else printf ("O  ");
        printf("\n");
    }
}


Contenedor pideDatos()
{
    Contenedor C;
    printf("Indica identificador del contenedor: ");
    scanf("%d",&C.IDContenedor);
    fflush(stdin);
    printf("\nIndica contenido del contenedor: ");
    gets(C.contenido);
    printf("\nIndica el nombre de la empresa que envía el contenedor: ");
    gets(C.nombreOrigen);
    printf("\nIndica el nombre de la empresa que recibe el contenedor");
    gets(C.nombreDestino);
    printf("\nIndica el peso del contenedor: ");
    scanf("%d",&C.peso);
    

}


void vaciaAlmacen(Almacen AL)
{
    int p,h;
    for(p=0;p<FILAS;p++)
        for (h=0;h<COLUMNAS;h++)
            AL[p][h].IDContenedor=LIBRE;
}



void main()
{
   //Define las variables necesarias

   // Vacía el almacen
    do
    {
        printf("\n\n1.-Apilar contenedor\n");
        printf("2. Desapilar contenedor\n");
        printf("3.- Mostrar Almacén\n");
        printf("4.- Finalizar\n");
        printf("Introduce una opcion:  ");
        scanf("%d",&opc);

        switch (opc)
        {
            case 1: //Completar
                    //Si el almacén está lleno, habrá que indicarlo 
					//mediante un mensaje en la consola.

            case 2: //Completar
					//Si en la columna indicada no hay contenedores, 
					//habrá que indicarlo mediante un mensaje en la consola.
               
            case 3: //Completar
                
            case 4: printf("HASTA PRONTO\n");
                break;

        }
    }while (opc!=4);
}

