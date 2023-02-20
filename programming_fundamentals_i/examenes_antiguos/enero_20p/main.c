/**********************************************************
 *  FUNDAMENTOS DE PROGRAMACI�N I
 *      CONVOCATORIA ORDINARIA. LABORATORIO  8/1/2020
 *
 *   AUTOR:     Alvaro Martinez Alfaro
 *   GRUPO:  1B
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //uso de srand y rand
#include <stdbool.h>
#include <string.h>

#define MAX_JUGAD 50
#define TAMEQUIPO 11
#define NUMPORTEROS 1
#define NUMDEFENSAS 4
#define NUMMEDIOS 4
#define NUMDELANTEROS 2

typedef enum { portero, defensa, medio, delantero } POSICION;
char positionName[][20] = {"portero", "defensa", "medio", "delantero"};

typedef struct
{
    int edad;
    int puntuacion;
    POSICION pos;
    char nombre[20];
    bool select;
} JUGADOR;

JUGADOR lista_seleccionados[TAMEQUIPO]; //alineacion de jugadores para el proximo partido
int num_seleccionados  = 0;            // nummero de jugadores seleccionados para el proximo partido
int total_jugadores = 0;                //total de jugadores incluidos en la alineacion

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: MuestraJugador
// Descripcion: Muestra en pantalla la informacion del jugador pasado como parametro
// Parametros:  p: jugador cuya informaci�n se quiere mostrar
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void MuestraJugador(JUGADOR p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\t", p.edad);
    printf("Puntuacion: %d\n", p.puntuacion);
    printf("Posicion: %s\n", positionName[p.pos]);
    if ( p.select ) printf("Seleccionado.\n");
    else printf("No seleccionado.\n");
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////
//Function MuestraAlineacion
// Descripcion: Muestra por pantalla la informacion de todos los judadores de lista_seleccionados (llama a MuestraJugador)
// Parametros:
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void MuestraAlineacion()
{
    int i;
    printf("Alineaci�n:\n");
    if (num_seleccionados!=TAMEQUIPO)
    {
        printf("Equipo Incompleto.\n");
        return;
    }
    for (i=0; i<TAMEQUIPO; i++)
        MuestraJugador(lista_seleccionados[i]);
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: SelectMejorJugador
// Descripcion: Devuelve el mejor jugador en la posicion dada que no ha sido seleccionado todavia y lo selecciona
// Parametros:  lista_jug: lista de todos los jugadores del equipo
//              pos: posicion en el campo para buscar el mejor jugador
// Returns: mejor jugador (no elegido todavia) in la posicion del campo dada
////////////////////////////////////////////////////////////////////////////////////////////
JUGADOR SelectMejorJugador(JUGADOR lista_jug[], POSICION pos)
{
    JUGADOR mejor = {.puntuacion = 0};

    for ( int i = 1; i < total_jugadores; i++ ) {
        if ( lista_jug[i].pos == pos && lista_jug[i].puntuacion > mejor.puntuacion &&
        !lista_jug[i].select) {
            mejor = lista_jug[i];
            lista_jug[i].select = true;
        }
    }

    return mejor;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: SelectJugadoresporPosicion
// Descripcion: Selecciona los 'njug' mejores jugadores para una determinada posicion y a�ade estos a la lista_seleccionados.
// Parametros:  list_jugad: lista de todos los jugadores del equipo
//              pos: posicion del campo para la que se van a elegir los mejores jugadores
//              njug: numero de jugadores a seleccionar para esa posicion
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void SelectJugadoresporPosicion(JUGADOR list_jugad[], POSICION pos, int njug)
{
    JUGADOR j;
    for ( int i = 0; i < njug; i++ ) {
        lista_seleccionados[num_seleccionados] = SelectMejorJugador(list_jugad, pos);
        lista_seleccionados[num_seleccionados].select=true;
        num_seleccionados++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: HacerAlineacion
// Descripcion: Completa una alineacion para el equipo. Llama a 'SelectJugadoresporPosicion' para cada posicion
// Parametros:  list_jugad: lista de todos los jugadores del equipo
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void HacerAlineacion(JUGADOR list_jugad[])
{
    //portero
    SelectJugadoresporPosicion(list_jugad,portero,NUMPORTEROS);
    //defensas
    SelectJugadoresporPosicion(list_jugad,defensa,NUMDEFENSAS);
    //medios
    SelectJugadoresporPosicion(list_jugad,medio,NUMMEDIOS);
    //delanteros
    SelectJugadoresporPosicion(list_jugad,delantero,NUMDELANTEROS);
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: PuntuacionMedia
// Descripcion: Calcula la puntuacion media de los jugadores de una posicion en el campo
// Parametros:  list_jugad: lista de todos los jugadores del equipo
//              pos: posicion para la que se va a calcular la puntuacion media
// Returns: la puntuacion media calculada
////////////////////////////////////////////////////////////////////////////////////////////
float PuntuacionMedia(JUGADOR list_jugad[], POSICION pos)
{
    int media = 0, num = 0;

    for ( int i = 0; i < total_jugadores; i++ ) {
        if ( list_jugad[i].pos == pos ) {
            media += list_jugad[i].puntuacion;
            num++;
        }
    }

    return media/(float)num;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion:  MuestraJugadorSobreMediaEnPosicion
// Descripcion: Muestra los datos de los jugadores cuya puntuacion esta sobre la media en la posicion dada
// Parametros:  list_jugad: lista de todos los jugadores del equipo
//              pos: posicion del campo de la que se muestran los jugadores
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void  MuestraJugadorSobreMediaEnPosicion(JUGADOR list_jugad[], POSICION pos)
{
    for ( int i = 0; i < total_jugadores; i++ ) {
        if ( list_jugad[i].pos == pos && list_jugad[i].puntuacion > PuntuacionMedia(list_jugad,pos) ) {
            MuestraJugador(list_jugad[i]);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: MuestraMejoresJugadores
// Descripcion: Muestra los datos de los jugadores de todas las posiciones cuya puntuacion esta sobre la media de su posicion
// Parametros:  list_jugad: lista de todos los jugadores del equipo
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void MuestraMejoresJugadores(JUGADOR list_jugad[])
{
    MuestraJugadorSobreMediaEnPosicion(list_jugad,portero);
    printf(" ------------------------------- \n");
    MuestraJugadorSobreMediaEnPosicion(list_jugad,defensa);
    printf(" ------------------------------- \n");
    MuestraJugadorSobreMediaEnPosicion(list_jugad,medio);
    printf(" ------------------------------- \n");
    MuestraJugadorSobreMediaEnPosicion(list_jugad,delantero);
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: CalculaPuntuacion
// Descripcion: Calcula de forma aletoria una puntuacion para el jugador dado
// Parametros:  p: puntero al jugador al que se le asigna la puntuacion calculada
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void CalculaPuntuacion(JUGADOR* p)
{
    srand ((unsigned)time(NULL)); //semilla aleatoriaRandom number seed
    p->puntuacion = rand()%100;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: NuevoJugador
// Descripcion: Pide al usuario los datos de un nuevo jugador y los almacena en la list_jugad pasada como parametro
// Parametros:  list_jugad: lista de todos los jugadores del equipo donde se insertara el nuevo
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
void NuevoJugador(JUGADOR list_jugad[])
{
    ///////Completa esta funcion como respuesta al apartado 'f' del examen
    // definicion de variables
    JUGADOR nuevo;
    int edad = 0;
    POSICION pos = -1;
    char nombre[20] = "";

    // introduccion de datos del nuevo jugador
    while (edad == 0) {
        printf("Indica edad: ");
        scanf("%d", &edad);

        if ( edad == 0 ) {
            printf("[ERROR] Indica una edad correcta.\n\n");
        }
    }
    while (pos < 0 || pos > 3) {
        printf("Indica posicion (0 - Portero, 1 - Defensa, 2 - Medio, 3 - Delantero): ");
        scanf("%d", &pos);

        if ( pos < 0 || pos > 3 ) {
            printf("[ERROR] Indica una posicion correcta.\n\n");
        }
    }
    while (strcmp(nombre,"") == 0) {
        printf("Indica nombre del jugador: ");
        gets(nombre);

        if (strcmp(nombre,"") == 0) {
            printf("[ERROR] Debes indicar un nombre.\n\n");
        }
    }
    nuevo.edad = edad;
    strcpy(nuevo.nombre,nombre);
    nuevo.pos = pos;
    // calculo de la puntuacion del nuevo jugador
    CalculaPuntuacion(&nuevo);
    // insercion del nuevo jugador en la lista t the new player in the list of players
    list_jugad[total_jugadores] = nuevo;
    total_jugadores++;
}

////////////////////////////////////////////////////////////////////////////////////////////
// Funcion: main
// Descripcion: Funcion principal.
// Parametros:
// Returns:
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //creacion de jugadores
    JUGADOR lista_jugadores[MAX_JUGAD] = {
            {26,87,portero,"Tomas Navidad",false}, {37,80,portero,"Pep Queen",false},
            {29,87,portero,"David Egeo",false},    {25,83,portero,"Santi Ca�as",false},
            {33,91,defensa,"Sergei Bouquet",false}, {34,85,defensa,"Franjuan",false},
            {28,95,defensa,"Vird Vann",false},      {34,82,defensa,"Philip Louise",false},
            {32,91,defensa,"Serg. Somar",false},      {26,85,defensa,"Ralph Bar",false},
            {34,87,medio,"Luck Mordred",false}, {33,89,medio,"Dave Whistle",false},
            {35,99,medio,"Ander Ista",false},   {38,85,medio,"Javi Alfonso",false},
            {27,85,medio,"H. Cisco",false},     {27,85,medio,"Cocky R.",false},
            {33,92,delantero,"Castolo",false},         {34,99,delantero,"C. Rolando",false},
            {32,87,delantero,"Suiss Luarez",false},    {32,87,delantero,"Kareen Cat",false},
            {32,99,delantero,"Leonard Liossi",false},  {18,75,delantero,"Jr. Vicious",false},
    };
    total_jugadores = 22;
    //presentacion
    char opt = 0;
    printf(" -------------------------------- \n");
    printf(" --  ASISTENTE DE ALINEACIONES -- \n");
    printf(" -------------------------------- \n\n");
    printf(" Este programa te ayudar� a elegir los mejores jugadores en cada posicion del campo.\n\n");
    //menu
    do
    {
        printf("  1. Introducir un nuevo jugador.\n");
        printf("  2. Mostrar jugadores encima de la media.\n");
        printf("  3. Hacer alineacion de mejores.\n");
        printf("  4. Salir\n\n");
        printf("Elige una opcion: ");
        opt = getchar();
        fflush(stdin);
        switch (opt)
        {
            case '1':
                NuevoJugador(lista_jugadores);
                break;
            case '2':
                MuestraMejoresJugadores(lista_jugadores);
                break;
            case '3':
                if (num_seleccionados==TAMEQUIPO)
                    printf("El equipo ya ha sido creado.\n\n");
                else
                {
                    HacerAlineacion(lista_jugadores);
                    MuestraAlineacion();
                }
                break;
            case '4':
                printf("Hasta el proximo partido\n");
                exit(0);
                break;
            default:
                printf("Opcion incorrecta. Seleccione otra opcion\n");
                break;
        }
    }
    while(opt != 4);

    return 0;
}
