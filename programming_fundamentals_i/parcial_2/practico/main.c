// Alumno: Alvaro Martinez Alfaro
// Grupo: 1B
// DNI: 

#include<stdio.h>
#include<stdlib.h>



#define FILAS 5   // Número de filas de la matriz
#define COLUMNAS 10   // Número columnas de lamatriz
#define LIBRE (-1)  // Constante para marcar las casillas libres de la matriz.


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
    printf("\n");
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
    printf("\nIndica el nombre de la empresa que envia el contenedor: ");
    gets(C.nombreOrigen);
    printf("\nIndica el nombre de la empresa que recibe el contenedor");
    gets(C.nombreDestino);
    printf("\nIndica el peso del contenedor: ");
    scanf("%d",&C.peso);

    return C;
}


void vaciaAlmacen(Almacen AL)
{
    int p,h;
    for(p=0;p<FILAS;p++)
        for (h=0;h<COLUMNAS;h++)
            AL[p][h].IDContenedor=LIBRE;
}

int apilaContenedor( Almacen AL ) {
    int apilado = 0, f = FILAS-1, c = COLUMNAS-1 ;

    while ( apilado == 0 && c >= 0 ) {
        while ( apilado == 0 && f >= 0 ) {
            if ( AL[f][c].IDContenedor == LIBRE ) {
                AL[f][c] = pideDatos();
                apilado = 1;
            }
            f--;
        }
        f = FILAS-1;
        c--;
    }

    return apilado;
}

void quitaContenedor( int c, Almacen AL, int *id ) {
    int f = 0;
    *id = LIBRE;

    while ( *id == LIBRE && f < FILAS ) {
        if ( AL[f][c].IDContenedor != LIBRE ) {
            *id = AL[f][c].IDContenedor;
            AL[f][c].IDContenedor = LIBRE;
        }
        f++;
    }
}



void main()
{
    //Define las variables necesarias
    int opc, val, col;
    Almacen alm;

    // Vacía el almacen
    vaciaAlmacen(alm);

    do
    {
        printf("\n\n1.-Apilar contenedor\n");
        printf("2. Desapilar contenedor\n");
        printf("3.- Mostrar Almacen\n");
        printf("4.- Finalizar\n");
        printf("Introduce una opcion:  ");
        scanf("%d",&opc);

        switch (opc)
        {
            case 1: //Completar
                //Si el almacén está lleno, habrá que indicarlo
                //mediante un mensaje en la consola.
                val = apilaContenedor( alm );
                if ( val == 0 ) {
                    printf("\n[ERROR] El almacen esta lleno. Se debe "
                           "retirar antes algun contenedor.\n");
                } else {
                    printf("\nContenedor apilado.\n");
                    muestraAlmacen(alm);
                }
                break;
            case 2: //Completar
                //Si en la columna indicada no hay contenedores,
                //habrá que indicarlo mediante un mensaje en la consola.
                muestraAlmacen( alm );
                printf("\nIndica columna: ");
                scanf("%d", &col);
                quitaContenedor(col, alm, &val);
                if ( val == LIBRE ) {
                    printf("\n[ERROR] No se encuentran contenedores en "
                           "la columna.\n");
                } else {
                    printf("\nSe ha eliminado el contenedor con ID %d.\n",
                           val);
                    muestraAlmacen(alm);
                }
                break;
            case 3: //Completar
                printf("\nAlmacen:\n");
                muestraAlmacen(alm);
                break;
            case 4: printf("HASTA PRONTO\n");
                break;

        }
    }while (opc!=4);
}

