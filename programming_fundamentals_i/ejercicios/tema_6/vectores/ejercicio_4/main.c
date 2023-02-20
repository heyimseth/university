/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: modifica el programa anterior para que la impresion del vector se
 *            haga mediante una funcion. Dicha funcion ha de imprimir los
 *            numeros separados por comas, y escribir un punto en el ultimo
 *            lugar.
 ******************************************************************************/
#include <stdio.h>

#define L_VECT 10

void SolicitarValores( int v[L_VECT] );
void MostrarValoresVector( int v[L_VECT] );


int main() {
    int vector[L_VECT];

    SolicitarValores(vector);
    MostrarValoresVector(vector);

    return 0;
}


void SolicitarValores( int v[L_VECT] ) {
    printf("Introduce %d numeros enteros.\n", L_VECT);
    for ( int i = 0; i < L_VECT; i++ ) {
        printf("Indica el numero %d: ", i+1);
        fflush(stdin);
        scanf("%d", &v[i]);
    }
}

void MostrarValoresVector( int v[L_VECT] ) {
    printf("Los valores que se encuentran en el vector son:\n");
    for ( int i = 0; i < L_VECT-1; i++ ) printf("%d, ", v[i]);
    printf("%d.", v[L_VECT-1]);
}
