/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: desarrolla un subprograma que dados dos vectores V1 y V2 de
 *            numeros enteros, de dimensiones N1 y N2 respectivamente, ordenados
 *            ascendentemente y sin valores repetidos, obtenga un tercer vector
 *            FUSION de dimension N1+N2, resultado de la fusion de V1 y V2, de
 *            forma que se mantenga el orden y no se repitan elementos
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define MAX_V_LONG 50


void leerVector( int v[], int l );
void mostrarVector( int v[], int l );
void ordenarVector( int v[], int l );
bool buscarElemento( int v[], int l, int num );
int vectorUnion( int v1[], int l1, int v2[], int l2, int v3[] );


int main() {
    int v1[MAX_V_LONG], v1_long, v2[MAX_V_LONG], v2_long, fusion[MAX_V_LONG*2],
        f_long;

    printf("Indica longitud del vector 1 (o 0 para %d): ", MAX_V_LONG);
    scanf("%d", &v1_long);
    if ( v1_long == 0 ) v1_long = MAX_V_LONG;
    printf("Indica datos del vector 1.\n");
    leerVector(v1, v1_long);
    ordenarVector(v1, v1_long);

    printf("Indica longitud del vector 2 (o 0 para %d): ", MAX_V_LONG);
    scanf("%d", &v2_long);
    if ( v2_long == 0 ) v2_long = MAX_V_LONG;
    printf("Indica datos del vector 2.\n");
    leerVector(v2, v2_long);
    ordenarVector(v2, v2_long);

    f_long = vectorUnion(v1, v1_long, v2, v2_long, fusion);
    mostrarVector(fusion, f_long);

    return 0;
}


void leerVector( int v[], int l ) {
    int i = 0, num;

    while ( i < l ) {
        printf("Indica el numero %d: ", i+1);
        scanf("%d", &num);

        if ( !buscarElemento(v, i+1, num) ) {
            v[i] = num;
            i++;
        } else {
            printf("[ERROR] El numero %d ya se encuentra en el vector.\n",
                   num);
        }
    }
}

void ordenarVector( int v[], int l ) {
    int aux;

    for ( int i = 1; i < l; i++ ) {
        for ( int j = i; j > 0; j-- ) {
            if ( v[j] < v[j-1] ) {
                aux = v[j-1], v[j-1] = v[j], v[j] = aux;
            }
        }
    }
}

void mostrarVector( int v[], int l ) {
    for ( int i = 0; i < l; i++ ) printf("%d ", v[i]);
}

bool buscarElemento( int v[], int l, int num ) {
    bool encontrado = false;
    int pos = 0;

    while ( !encontrado && pos < l ) {
        if ( v[pos] == num ) {
            encontrado = true;
        }
        pos++;
    }

    return encontrado;
}

int vectorUnion( int v1[], int l1, int v2[], int l2, int v3[] ) {

}
