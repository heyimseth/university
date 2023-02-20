/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: dada la definicion de registro que permite representar en memoria
 *            un conjunto de numeros reales, crear un subprograma que dados dos
 *            conjuntos de valores calcule y devuelva un nuevo conjunto que sea
 *            la union de los dos iniciales. Debe tenerse en cuenta que dentro
 *            de cada uno de los conjuntos de partida por separado no debe haber
 *            numero repetidos, aunque si que puede estar el mismo numero en los
 *            dos conjuntos. El conjunto resultado tampoco debe tener elementos
 *            repetidos.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num_elems;
    float elem[100];
} CONJUNTO;
typedef CONJUNTO t_conjunto;

typedef struct {
    int num_elems;
    float elem[200];
} UNION;
typedef UNION t_union;

void solicitarElementosConjunto( t_conjunto *c );
void conjuntoUnion( t_conjunto c1, t_conjunto c2, t_union *u );


int main() {
    t_conjunto con1 = {.num_elems = 0}, con2 = {.num_elems = 0};
    t_union un;

    printf("\nElementos del conjunto 1.\n");
    solicitarElementosConjunto( &con1 );
    printf("\nElementos del conjunto 2.\n");
    solicitarElementosConjunto( &con2 );
    conjuntoUnion( con1, con2, &un );

    printf("Union del conjunto 1 y 2: ");
    for ( int i = 0; i < un.num_elems; i++ ) {
        printf("%f ", un.elem[i]);
    }

    return 0;
}


bool elementoRepetido( float v[], int q, float e ) {
    bool encontrado = false;
    int i = 0;

    while ( i < q && !encontrado ) {
        if ( e == v[i] ) {
            encontrado = true;
        }
        i++;
    }

    return encontrado;
}

void solicitarElementosConjunto( t_conjunto *c ) {
    float i;

    do {
        printf("Indica un numero real (o 0 para terminar): ");
        scanf("%f", &i);

        if ( i != 0 ) {
            if (elementoRepetido(c->elem, c->num_elems, i)) {
                printf("[ERROR] El numero ya se encuentra en el conjunto.\n");
            } else {
                c->elem[c->num_elems] = i;
                c->num_elems++;
            }
        }
    } while ( i != 0 );
}

void conjuntoUnion( t_conjunto c1, t_conjunto c2, t_union *u ) {
    for ( int i = 0; i < c1.num_elems; i++ ) {
        u->elem[i] = c1.elem[i];
        u->num_elems++;
    }

    for ( int i = 0; i < c2.num_elems; i++ ) {
        if ( !elementoRepetido(u->elem, u->num_elems, c2.elem[i]) ) {
            u->elem[u->num_elems] = c2.elem[i];
            u->num_elems++;
        }
    }
}
