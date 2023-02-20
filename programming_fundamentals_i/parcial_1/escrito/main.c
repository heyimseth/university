/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Grupo: 1B
 ******************************************************************************/
#include <stdio.h>


float aproximacionRaiz( int z, int v );


int main() {
    char opcion, c;
    int i, x, q_digitos = 0;
    int a, b;

    do {
        printf("\na. Ejercicio 1\n");
        printf("b. Ejercicio 2\n");
        printf("c. Ejercicio 3\n");
        printf("d. Salir\n");
        fflush(stdin);
        scanf("%c", &opcion);

        switch ( opcion ) {
            case 'a':
                printf("Indica una secuencia de caracteres finalizada"
                       " en punto (.): ");
                do {
                    c = getchar();
                    if ( (c-48) <= 9 && (c-48) >= 0 ) {
                        q_digitos++;
                    }
                } while ( c != '.' );
                printf("Se han introducido %d digitos.\n", q_digitos);
                break;
            case 'b':
                i = 25;
                x = 0;
                while ( i >= 3 ) {
                    if ( (i)%3 == 0 ) {
                        x++;
                        printf("%d ", x);
                    }
                    i--;
                }
                printf("\nx = %d", x);
                break;
            case 'c':
                printf("Indica un entero para calcular su raiz: ");
                scanf("%d", &a);
                printf("Indica el numero de interaciones: ");
                scanf("%d", &b);
                printf("Una aproximacion a la raiz de %d con %d "
                       "iteraciones es %.4f.\n", a, b, aproximacionRaiz(a, b));
                break;
            case 'd':
                break;
            default:
                printf("Indica una opcion correcta (a, b, c, d).\n");
        }
    } while ( opcion != 'd' );
    return 0;
}


float aproximacionRaiz( int z, int v ) {
    float n = z;
    int i;

    for ( i = 1; i <= v; i++ ) {
        n = (((z/n)+n)/2);
    }

    return n;
}
