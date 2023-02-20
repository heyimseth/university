/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: definir los tipos de datos necesarios para representar un
 *            polinomio que tendra como maximo 15 terminos. Cada uno de los
 *            terminos tendra dos valores, el coeficiente y el exponente. Crear
 *            un subprograma que permita introducir un polinomio, y otro que
 *            muestre por pantalla un polinomio en su formato tradicional.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#define MAX_TERM 15


typedef struct {
    float coeficiente;
    int exp;
} POLINOMIO;
typedef POLINOMIO t_polinomio;

typedef t_polinomio polinomio[15];

void solicitarPolinomio( polinomio p, int *q_term );
void mostrarPolinomio( polinomio p, int q_term );


int main() {
    polinomio pol;
    int q = 0;

    solicitarPolinomio(pol, &q);
    mostrarPolinomio(pol, q);

    return 0;
}


bool buscarTermino( polinomio poli, int exp, int q ) {
    int i = 0;
    bool encontrado = false;

    while ( i < q && !encontrado ) {
        if ( poli[i].exp == exp ) {
            encontrado = true;
        }
        i++;
    }

    return encontrado;
}


void solicitarPolinomio( polinomio p, int *q_term ) {
    float c;
    int e;

    do {
        printf("Indica termino %d (Cx^E) o C=0 para salir: ", *q_term+1);
        fflush(stdin);
        scanf("%fx^%d", &c, &e);

        if ( c != 0 ) {
            if (buscarTermino(p, e, *q_term)) {
                printf("[ERROR] Ya se ha introducido un termino con este "
                       "exponente.\n");
            } else if (e > 0 && e <= MAX_TERM) {
                p[*q_term].coeficiente = c;
                p[*q_term].exp = e;
                (*q_term)++;
            } else {
                printf("[ERROR] Indica un exponente positivo menor o igual"
                       " que %d.\n", MAX_TERM);
            }
        }
    } while ( c != 0 );
}

void mostrarPolinomio( polinomio p, int q_term ) {
    for ( int i = 0; i < q_term-1; i++ ) {
        printf("%.2fx^%d + ", p[i].coeficiente, p[i].exp);
    }
    printf("%.2fx^%d", p[q_term-1].coeficiente, p[q_term-1].exp);
}
