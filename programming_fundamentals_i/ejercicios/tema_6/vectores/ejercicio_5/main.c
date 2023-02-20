#include <stdio.h>

#define MAX_L_VECT 100

int SolicitarValores( int v[MAX_L_VECT] );
void MostrarValoresVector( int v[MAX_L_VECT], int l );


int main() {
    int vector[MAX_L_VECT], v_long;

    v_long = SolicitarValores(vector);
    MostrarValoresVector(vector, v_long);

    return 0;
}


int SolicitarValores( int v[MAX_L_VECT] ) {
    int num, i = 0;
    printf("Introduce numeros enteros (como maximo %d y acabada en 0).\n",
           MAX_L_VECT);

    do {
        printf("Introduce un numero (0 para acabar): ");
        scanf("%d", &num);

        if ( num != 0 ) {
            v[i] = num;
            i++;
        }
    } while ( num != 0 && i < MAX_L_VECT );

    return i;
}

void MostrarValoresVector( int v[MAX_L_VECT], int l ) {
    printf("Los %d valores que se encuentran en el vector son:\n", l);
    for ( int i = 0; i < l-1; i++ ) printf("%d, ", v[i]);
    printf("%d.", v[l-1]);
}
