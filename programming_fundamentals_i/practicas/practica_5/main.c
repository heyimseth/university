/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 10/11/2022
 * Programa: práctica 5
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "misterio.h"

// Prototipos de las funciones

void usa_letra(char palabra[], char aciertos[], char letra);
    // Comprueba si la letra existe en palabra, y si existe,
    // sustituye la letra en el vector aciertos (cambia '_' por
    // la 'letra')

int iguales(char p1[], char p2[]);
    // Devuelve 1 si palabra1 (p1) y palabra2 (p2) son
    // iguales y 0 si no lo son

void pide_entrada(char entrada[]);
    // lee la entrada del usuario y la guarda en entrada

int check_entrada(char palabra[],char aciertos[], char entrada[]);
    /* Si la entrada es un carácter (longitud de entrada = 1):
     *   comprueba si la letra aparece en la solución => usa_letra(...)
     *   y comprueba si hemos acertado la palabra  => iguales(...)
     *
     * Si la entrada es una cadena:
     *    mira si directamente es la solución => iguales()
     *
     * Devuelve 1 si se ha acertado la palabra y 0 si no.
     */

void pistas( char aciertos[], char palabra[] );
    // coloca las vocales en aciertos


int main(){
    // Variables que guardan el estado del juego.
    int INTENTOS ;		// Numero de intentos permitido
    char palabra[20];   // Palabra oculta a descubrir
    char entrada[20];   // Entrada del usuario;
    char aciertos[20];	// Cadena que se va rellenando con los aciertos
    int respuesta;
    int tam;            // Tamaño de la palabra oculta
    int jugadas=0;      // Contador de intentos
    int acertado = 0;



    printf("Inicio del juego.\n\n");

    eligePalabra(palabra);
    tam = strlen(palabra);


    INTENTOS = tam + 1;

    //Este código inicializa la cadena aciertos.
    for (int i=0;i<tam;i++) {
        aciertos[i] = '_';
    }
    aciertos[tam]='\0'; // Añade el carácter de fin de cadena

    printf("1. No quiero pistas...\n");
    printf("2. Dame pistas ...\n");
    scanf("%d",&respuesta);

    // HACER:
    // Llama al método "pistas" en función de la respuesta.
    if ( respuesta == 2 ) {
        pistas( aciertos, palabra );
    }

    printf("Palabra:" );
    printf("%s", aciertos);
    printf("(%d)\n\n", tam);

    while ( jugadas < INTENTOS && !acertado ) {
        printf("Indica una letra o la palabra completa: ");
        pide_entrada(entrada);
        acertado = check_entrada( palabra, aciertos, entrada );
        if ( !acertado ) {
            jugadas++;
            printf("Palabra:");
            printf("%s", aciertos);
            printf("\nIntentos restantes: %d\n\n", INTENTOS-jugadas);
        }
    }

    if (acertado)
        printf("\n%s!!! Acertado en %d jugadas!", palabra, jugadas);
    else
        printf("\nLa palabra correcta era: %s",palabra);
}


// Funciones
void pide_entrada(char entrada[]) {
    scanf("%s", entrada);
}


int check_entrada(char palabra[],char aciertos[], char entrada[]) {
    int long_entrada = strlen(entrada);
    char ltr;
    int acertado;

    if ( long_entrada == 1 ) {
        ltr = entrada[0];
        usa_letra(palabra, aciertos, ltr);
        acertado = iguales(palabra, aciertos);
    } else {
        acertado = iguales(palabra, entrada);
    }

    return acertado;
}


int iguales(char p1[], char p2[]) {
    int long1 = strlen(p1), long2 = strlen(p2), i, igual = 1;

    if ( long1 != long2 ) {
        igual = 0;
    } else {
        for ( i = 0; i < long1; i++ ) {
            if ( p1[i] != p2[i] ) {
                igual = 0;
            }
        }
    }

    return igual;
}


void usa_letra(char palabra[], char aciertos[], char letra) {
    int long_palabra = strlen(palabra), i;

    for ( i = 0; i < long_palabra; i++ ) {
        if ( palabra[i] == letra ) {
            aciertos[i] = letra;
        }
    }
}

void pistas( char aciertos[], char palabra[] ) {
    int long_palabra = strlen(palabra), i;

    for ( i = 0; i < long_palabra; i++ ) {
        switch ( toupper(palabra[i]) ) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                aciertos[i] = palabra[i];
                break;
        }
    }
}
