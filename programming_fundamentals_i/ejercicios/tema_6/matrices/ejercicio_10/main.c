/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: se tiene una secuencia de longitud indeterminada acabada en punto,
 *            formada unicamente por letras minusculas. Se pide un programa que
 *            determine todas las parejas de letras que aparecen, diga cuales
 *            son y cuantas hay. La salida debe producirse en orden alfabetico.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define MAX_SEC 2000

int parejas( char sec[], char parejas[][2], int q_par[] );


int main() {
    char secuencia[MAX_SEC], par[MAX_SEC*2][2];
    int q, q_parejas[MAX_SEC*2];

    printf("Indica una secuencia terminada en punto (.) y max. %d "
           "caracteres: ", MAX_SEC);
    gets(secuencia);
    q = parejas( secuencia, par, q_parejas );
    for ( int i = 0; i < q; i++ ) {
        printf("Pareja %d: %c %c - %d\n", i+1, par[i][0], par[i][1],
               q_parejas[i]);
    }

    return 0;
}


int buscarPareja( char p_act[], char ps[][2], int q ) {
    int i = 0, pos = -1;

    while ( i < q && pos == -1 ) {
        if ( p_act[0] == ps[i][0] && p_act[1] == ps[i][1] ) pos = i;
        i++;
    }

    return pos;
}

void insertarPareja( char p[], char ps[][2], int q_p[], int *q ) {
    int i = 0;
    bool insertada = false;

    while ( i < *q && !insertada ) {
        if ( p[0]+p[1] < ps[i][0]+ps[i][1] ) {
            for ( int j = *q; j > i; j-- ) {
                ps[j][0] = ps[j-1][0];
                ps[j][1] = ps[j-1][1];
                q_p[j] = q_p[j-1];
            }
            ps[i][0] = p[0];
            ps[i][1] = p[1];
            q_p[i] = 1;
            insertada = true;
        }
        i++;
    }

    if ( !insertada ) {
        ps[*q][0] = p[0];
        ps[*q][1] = p[1];
        q_p[*q]++;
    }
    (*q)++;
}

int parejas( char sec[], char parejas[][2], int q_par[] ) {
    int i = 0, q_parejas = 0, pos;
    char pareja_actual[2];

    while ( sec[i] != '.' && sec[i+1] != '.' ) {
        if ( sec[i+1] != ' ' ) {
            pareja_actual[0] = sec[i];
            pareja_actual[1] = sec[i+1];
            pos = buscarPareja( pareja_actual, parejas, q_parejas );
            if ( pos != -1 ) {
                q_par[pos]++;
            } else {
//                parejas[q_parejas][0] = pareja_actual[0];
//                parejas[q_parejas][1] = pareja_actual[1];
//                q_par[q_parejas]++;
//                q_parejas++;
                insertarPareja( pareja_actual, parejas, q_par, &q_parejas );
            }
            i++;
        } else {
            i += 2;
        }
    }

    return q_parejas;
}
