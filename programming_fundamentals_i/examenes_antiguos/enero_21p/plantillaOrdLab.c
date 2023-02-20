/*************************************************************
 *   FUNDAMENTOS DE PROGRAMACIÓN I   GRUPO *Pon aquí tu grupo*
 *   CONVOCATORIA ORDINARIA
 *   CONTROL DE LABORATORIO  19-01-2021
 *
 *   AUTOR:     *Pon aqui tu nombre*
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Capacidad máxima de juegos que pueden haber en la consola
#define CAPACIDAD 512

// TipoTiempo es un tipo de dato que representa una cantidad de tiempo en la forma horas, minutos, segundos
typedef struct
{
    int horas;
    int minutos;
    int segundos;
}TipoTiempo;

// TipoJuego es un tipo de dato que representa la información almacenada acerca de cada juego por el control parental
typedef struct
{
    int gameID;                     // Identificador del juego (coincide con su posición en la lista de juegos). Usar solo para búsquedas.
    char nombre[20];                // Nombre del juego
    TipoTiempo tiempoDeJuegoActual; // Tiempo de juego actual
    TipoTiempo tiempoDeJuegoMaximo; // Tiempo de juego máximo permitido
}TipoJuego;

// TipoLista es el tipo de dato que representa la lista de juegos jugados en la consola.
//  La capacidad máxima es CAPACIDAD
typedef TipoJuego TipoLista[CAPACIDAD];

// Esta variable es un array que representa la lista de juegos jugados en la consola
//  Está inicializada con tres juegos.
TipoLista listaJuegos = {{0,"God of War",{10,15,6},{150,0,0}},
                         {1,"Fortnite",{140,59,25},{142,0,0}},
                         {2,"Minecraft",{10,1,0},{150,0,0}}};

// Indica el número de juegos jugados en la consola (inicializado a 3 -los de arriba-)
int numeroJuegos = 3;

// Prototipos de funciones
void imprimeDatosDeUnJuego(TipoJuego game);
TipoJuego incluirJuegoNuevo();
void sumarTiempo(int gameID, int minutos);
bool sePuedeJugar(char nombre[]);
TipoJuego obtenerJuegoMasJugado();
int obtenerNuevoGameID();

// Función main
int main()
{
    // Menú para el usuario
    int opc,i,gameID,min;
    TipoTiempo tiempo;
    TipoJuego juego;
    char nombre[20];
    do {
    printf("  -------------------------------------\n");
    printf(" -------- PS5 Control Parental --------- \n");
    printf("  -------------------------------------\n");
    printf(" 1. Listar juegos instalados.\n");
    printf(" 2. Insertar juego nuevo.\n");
    printf(" 3. Incrementar tiempo de juego.\n");
    printf(" 4. Comprobar si hay tiempo disponible para jugar a un juego.\n");
    printf(" 5. Obtener el juego jugado por mas tiempo.\n");
    printf(" 6. Cerrar el programa.\n");
    printf(" ------------------------------------------------\n");
    printf(" Elige una opcion: ");
    scanf("%d",&opc);
    printf("\n");

    switch (opc)  {
        case 1:
            for (i=0;i<numeroJuegos;i++)
                imprimeDatosDeUnJuego(listaJuegos[i]);
            printf("\n");
            break;
        case 2:
            if (numeroJuegos<CAPACIDAD)
            {
                listaJuegos[numeroJuegos]=incluirJuegoNuevo(numeroJuegos);
                numeroJuegos++;
            }
            break;
        case 3:
            for (i=0;i<numeroJuegos;i++)
                imprimeDatosDeUnJuego(listaJuegos[i]);
            do
            {
                printf("Introduce el ID del juego: ");
                scanf("%d",&gameID);
            }while((gameID<0) && (gameID>=numeroJuegos));
            do
            {
                printf("Introduce la cantidad de minutos a sumar: ");
                scanf("%d",&min);
            }while(min<0);
            sumarTiempo(gameID,min);
            printf("\n");
            break;
        case 4:
            for (i=0;i<numeroJuegos;i++)
                imprimeDatosDeUnJuego(listaJuegos[i]);
            printf("Introduce el NOMBRE del juego: ");
            getchar();
            gets(nombre);
            if(sePuedeJugar(nombre))
                printf(" -El juego \'%s\' todavia se puede jugar.\n", nombre);
            else
                printf(" -El juego \'%s\' ha sobrepasado el tiempo de juego maximo.\n",nombre);
            printf("\n");
            break;
        case 5:
            juego=obtenerJuegoMasJugado();
            printf("El juego mas jugado es: \'%s\'.\n", juego.nombre);
            printf(" -Ha sido jugado %d horas, %d minutos, %d segundos.\n",juego.tiempoDeJuegoActual.horas,juego.tiempoDeJuegoActual.minutos,juego.tiempoDeJuegoActual.segundos);
            printf("\n");
            break;
        case 6:
            printf("¡Hasta pronto!\n");
            break;
    }
 }while (opc!=6);
    return 0;
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: imprimeDatosDeUnJuego
// Descripción: Imprime por pantalla los datos almacenados de un juego
// Parámetros: TipoJuego game -> juego que contiene los datos a imprimir
// Return: Nada
//////////////////////////////////////////////////////////////////
void imprimeDatosDeUnJuego(TipoJuego game)
{
    // Escribe aquí la fu ncionalidad pedida por el apartado '1' del examen
    ///...
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: incluirJuegoNuevo
// Descripción: Pide al usuario los datos de un juego nuevo.
//               Como se trata de un juego nuevo, el tiempo de juego
//               actual debe inicializarse a 0. El tiempo de juego
//               máximo permitido habrá que pedírselo al usuario.
// Parámetros: int gameID -> identificador que tendrá el nuevo juego
// Return: Una estructura de tipo TipoJuego con los campos rellenados.
//////////////////////////////////////////////////////////////////
TipoJuego incluirJuegoNuevo(int gameID)
{
    // Escribe aquí la fu ncionalidad pedida por el apartado '2' del examen
    ///...
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: sumarTiempo
// Descripción: Añade una cantidad de minutos (pasada como parámetro)
//               a un juego identificado por su gameID (pasado como parámetro).
//               Se debe mantener la variable tiempoDeJuegoActual con valores
//               que sean válidos
// Parámetros: int gameID  -> identificador que tendrá el nuevo juego
//             int minutos -> cantidad de miniutos a sumar al tiempo de juego actual
// Return: Nada
//////////////////////////////////////////////////////////////////
void sumarTiempo(int gameID, int minutos)
{
    // Escribe aquí la fu ncionalidad pedida por el apartado '3' del examen
    ///...
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: sePuedeJugar
// Descripción: Compara el tiempo de juego actual con el tiempo de juego máximo permitido
//               para ver si es posible jugar. El juego está identificado por su gameID.
//               Es recomendable usar la función auxiliar convertirTiempoASegundos
// Parámetros: int gameID  -> identificador que tendrá el nuevo juego
// Return: bool -> verdadero si se puede y falso si no
//////////////////////////////////////////////////////////////////
bool sePuedeJugar(char nombre[])
{
    // Escribe aquí la fu ncionalidad pedida por el apartado '4' del examen
    ///...
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: obtenerJuegoMasJugado
// Descripción: Compara todos los juegos para ver cuál es al que se ha jugado más.
//               Es recomendable usar la función auxiliar convertirTiempoASegundos
// Parámetros: Ninguno
// Return: Una estructura de tipo TipoJuego con los datos del juego más jugado
//////////////////////////////////////////////////////////////////
TipoJuego obtenerJuegoMasJugado()
{
    // Escribe aquí la fu ncionalidad pedida por el apartado '5' del examen
    ///...
}

//////////////////////////////////////////////////////////////////
//Nombre de la función: convertirTiempoASegundos
// Descripción: Convierte una estructura TipoTiempo que contiene una cantidad de tiempo
//               expresada en horas, minutos y segundos a únicamente segundos. Útil para
//               comparar dos estructuras TipoTiempo distintas.
// Parámetros: TipoTiempo t -> estructura que contiene una cantidad de tiempo expresada en
//                              horas, minitos y segundos
// Return: Cantidad de segundos representados por la estructura t
//////////////////////////////////////////////////////////////////
int convertirTiempoASegundos(TipoTiempo t)
{
    return t.horas*3600 + t.minutos*60 + t.segundos;
}
