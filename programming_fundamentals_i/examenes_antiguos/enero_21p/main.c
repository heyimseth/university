/*************************************************************
 *   FUNDAMENTOS DE PROGRAMACI�N I   GRUPO 1B
 *   CONVOCATORIA ORDINARIA
 *   CONTROL DE LABORATORIO  19-01-2021
 *
 *   AUTOR: Alvaro Martinez Alfaro
 *************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Capacidad m�xima de juegos que pueden haber en la consola
#define CAPACIDAD 512

// TipoTiempo es un tipo de dato que representa una cantidad de tiempo en la forma horas, minutos, segundos
typedef struct
{
    int horas;
    int minutos;
    int segundos;
} TipoTiempo;

// TipoJuego es un tipo de dato que representa la informaci�n almacenada acerca de cada juego por el control parental
typedef struct
{
    int gameID;                     // Identificador del juego (coincide con su posici�n en la lista de juegos). Usar solo para b�squedas.
    char nombre[20];                // Nombre del juego
    TipoTiempo tiempoDeJuegoActual; // Tiempo de juego actual
    TipoTiempo tiempoDeJuegoMaximo; // Tiempo de juego m�ximo permitido
} TipoJuego;

// TipoLista es el tipo de dato que representa la lista de juegos jugados en la consola.
//  La capacidad m�xima es CAPACIDAD
typedef TipoJuego TipoLista[CAPACIDAD];

// Esta variable es un array que representa la lista de juegos jugados en la consola
//  Est� inicializada con tres juegos.
TipoLista listaJuegos = {{0,"God of War",{10,15,6},{150,0,0}},
                         {1,"Fortnite",{140,59,25},{142,0,0}},
                         {2,"Minecraft",{10,1,0},{150,0,0}}};

// Indica el n�mero de juegos jugados en la consola (inicializado a 3 -los de arriba-)
int numeroJuegos = 3;

// Prototipos de funciones
void imprimeDatosDeUnJuego(TipoJuego game);
TipoJuego incluirJuegoNuevo( int gameID );
void sumarTiempo(int gameID, int minutos);
bool sePuedeJugar(char nombre[]);
TipoJuego obtenerJuegoMasJugado();
int obtenerNuevoGameID();
int convertirTiempoASegundos(TipoTiempo t);

// Funci�n main
int main()
{
    // Men� para el usuario
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
                printf("�Hasta pronto!\n");
                break;
        }
    }while (opc!=6);
    return 0;
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: imprimeDatosDeUnJuego
// Descripci�n: Imprime por pantalla los datos almacenados de un juego
// Parametros: TipoJuego game -> juego que contiene los datos a imprimir
// Return: Nada
//////////////////////////////////////////////////////////////////
void imprimeDatosDeUnJuego(TipoJuego game)
{
    printf("\nDatos de %d - %s\n", game.gameID, game.nombre);
    printf("\tTiempo de juego actual: %02d:%02d:%02d\n",
           game.tiempoDeJuegoActual.horas, game.tiempoDeJuegoActual.minutos,
           game.tiempoDeJuegoActual.segundos);
    printf("\tTiempo de juego maximo: %02d:%02d:%02d\n",
           game.tiempoDeJuegoMaximo.horas, game.tiempoDeJuegoMaximo.minutos,
           game.tiempoDeJuegoMaximo.segundos);
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: incluirJuegoNuevo
// Descripci�n: Pide al usuario los datos de un juego nuevo.
//               Como se trata de un juego nuevo, el tiempo de juego
//               actual debe inicializarse a 0. El tiempo de juego
//               m�ximo permitido habr� que ped�rselo al usuario.
// Par�metros: int gameID -> identificador que tendr� el nuevo juego
// Return: Una estructura de tipo TipoJuego con los campos rellenados.
//////////////////////////////////////////////////////////////////
TipoJuego incluirJuegoNuevo(int gameID)
{
    TipoJuego nuevo = {.gameID = gameID, .tiempoDeJuegoActual = {0,0,0}};

    printf("Indica nombre del juego: ");
    fflush(stdin);
    gets(nuevo.nombre);

    printf("Indica tiempo de juego maximo (hh:mm:ss): ");
    scanf("%d:%d:%d", &nuevo.tiempoDeJuegoMaximo.horas,
          &nuevo.tiempoDeJuegoMaximo.minutos,
          &nuevo.tiempoDeJuegoMaximo.segundos);

    return nuevo;
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: sumarTiempo
// Descripci�n: A�ade una cantidad de minutos (pasada como par�metro)
//               a un juego identificado por su gameID (pasado como par�metro).
//               Se debe mantener la variable tiempoDeJuegoActual con valores
//               que sean v�lidos
// Par�metros: int gameID  -> identificador que tendr� el nuevo juego
//             int minutos -> cantidad de miniutos a sumar al tiempo de juego actual
// Return: Nada
//////////////////////////////////////////////////////////////////
void sumarTiempo(int gameID, int minutos)
{
    listaJuegos[gameID].tiempoDeJuegoActual.minutos +=  minutos;

    while ( listaJuegos[gameID].tiempoDeJuegoActual.minutos >= 60 ) {
        listaJuegos[gameID].tiempoDeJuegoActual.minutos -= 60;
        listaJuegos[gameID].tiempoDeJuegoActual.horas++;
    }
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: sePuedeJugar
// Descripci�n: Compara el tiempo de juego actual con el tiempo de juego m�ximo permitido
//               para ver si es posible jugar. El juego est� identificado por su gameID.
//               Es recomendable usar la funci�n auxiliar convertirTiempoASegundos
// Par�metros: int gameID  -> identificador que tendr� el nuevo juego
// Return: bool -> verdadero si se puede y falso si no
//////////////////////////////////////////////////////////////////
bool sePuedeJugar(char nombre[])
{
    int id = -1, ind = 0, c = 0;
    bool coincide = true;

    do {
        while ( coincide && nombre[c] != '\0' && listaJuegos[ind].nombre[c] != '\0' ) {
            if ( nombre[c] != listaJuegos[ind].nombre[c] ) {
                coincide = false;
            }
            c++;
        }
        if ( coincide ) id = ind;
        coincide = true;
        ind++;
        c = 0;
    } while ( id == -1 && ind < numeroJuegos );

    if ( convertirTiempoASegundos(listaJuegos[id].tiempoDeJuegoActual) <
            convertirTiempoASegundos(listaJuegos[id].tiempoDeJuegoMaximo) ) {
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: obtenerJuegoMasJugado
// Descripci�n: Compara todos los juegos para ver cu�l es al que se ha jugado m�s.
//               Es recomendable usar la funci�n auxiliar convertirTiempoASegundos
// Par�metros: Ninguno
// Return: Una estructura de tipo TipoJuego con los datos del juego m�s jugado
//////////////////////////////////////////////////////////////////
TipoJuego obtenerJuegoMasJugado()
{
    TipoJuego mas_jugado = listaJuegos[0];

    for ( int i = 1; i < numeroJuegos; i++ ) {
        if (convertirTiempoASegundos(listaJuegos[i].tiempoDeJuegoActual) >
                (convertirTiempoASegundos(mas_jugado.tiempoDeJuegoActual))) {
            mas_jugado = listaJuegos[i];
        }
    }

    return mas_jugado;
}

//////////////////////////////////////////////////////////////////
//Nombre de la funci�n: convertirTiempoASegundos
// Descripci�n: Convierte una estructura TipoTiempo que contiene una cantidad de tiempo
//               expresada en horas, minutos y segundos a �nicamente segundos. �til para
//               comparar dos estructuras TipoTiempo distintas.
// Par�metros: TipoTiempo t -> estructura que contiene una cantidad de tiempo expresada en
//                              horas, minitos y segundos
// Return: Cantidad de segundos representados por la estructura t
//////////////////////////////////////////////////////////////////
int convertirTiempoASegundos(TipoTiempo t)
{
    return t.horas*3600 + t.minutos*60 + t.segundos;
}
