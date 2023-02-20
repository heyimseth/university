/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: escribe un programa que reciba dos matrices de numeros en coma
 *            flotante, y devuelva su multiplicacion. Para ello, ha de comprobar
 *            primero que las matrices son compatibles, es decir, que el numero
 *            de columnas de la primera es igual al numero de la segunda.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define N 10


void leerMatriz( int f, int c, int matriz[f][c] );
void mostrarMatriz( int f, int c, int matriz[f][c] );
bool multiplicacionMatrices( int f1, int c1, int m1[f1][c1],
                             int f2, int c2, int m2[f2][c2],
                             int mult[f1][c2] );


int main() {
    int fil1, fil2, col1, col2;
    bool e;

    printf("Multiplicacion de matrices.\n");
    printf("Max. filas = %d.\nMax. cols. = %d.\n", N, N);
    do {
        printf("Indica tamano matriz 1 (NxM): ");
        scanf("%dx%d", &fil1, &col1);
        printf("Indica tamano matriz 2 (NxM): ");
        scanf("%dx%d", &fil2, &col2);

        if ( fil1 > 10 || col1 > 10 || fil2 > 10 || col2 > 10 ) {
            printf("[ERROR] El maximo de filas es %d y de columnas %d.\n",
                   N, N);
        }
    } while ( fil1 > 10 || col1 > 10 || fil2 > 10 || col2 > 10 );

    int matriz1[fil1][col1], matriz2[fil2][col2], multi[fil1][col2];

    leerMatriz(fil1, col1, matriz1);
    leerMatriz(fil2, col2, matriz2);
    mostrarMatriz(fil1, col1, matriz1);
    printf("\n");
    mostrarMatriz(fil2, col2, matriz2);
    printf("\n\n");

    e = multiplicacionMatrices(fil1, col1, matriz1, fil2, col2, matriz2, multi);
    if ( e ) {
        mostrarMatriz(fil1, col2, multi);
    } else {
        printf("[ERROR] El numero de columnas de la matriz 1 es distinto"
               " del numero de filas de la matriz 2. No se puede multiplicar.\n");
    }

    return 0;
}


void leerMatriz( int f, int c, int matriz[f][c] ) {
    for ( int i = 0; i < f; i++ ) {
        printf("Datos de la fila %d.\n", i+1);
        for ( int j = 0; j < c; j++ ) {
            printf("\tColumna %d: ", j+1);
            fflush(stdin);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz( int f, int c, int matriz[f][c] ) {
    for ( int i = 0; i < f; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

bool multiplicacionMatrices( int f1, int c1, int m1[f1][c1],
                             int f2, int c2, int m2[f2][c2],
                             int mult[f1][c2] ) {
    if ( c1 != f2 ) {
        return false;
    }

    for ( int i = 0; i < f1; i++ ) { // filas de multi
        for ( int j = 0; j < c2; j++ ) { // columnas de multi
            mult[i][j] = 0;
            for ( int k = 0; k < c1; k++ ) {
                mult[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return true;
}
