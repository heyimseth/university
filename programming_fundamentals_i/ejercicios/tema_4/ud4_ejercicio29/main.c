/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 * Fecha: 07/11/2022
 * Programa: escribir un programa que muestre por pantalla el menú:
 *                  1. Factorial.
 *                  2. Numero automorfico.
 *                  3. Ecuacion de segundo grado.
 *                  4. Fin.
 *                  Elige opcion:
 *           y calcule el resultado correspondiente.
 ******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double factorial( int num );
bool esAutomorfico( int num );
void ecSegundoGrado( float a, float b, float c );

int main() {
    int opcion, num;
    float a, b, c, res1, res2;
    bool ec_res;

    do {
        printf("\n\n1. Factorial\n");
        printf("2. Numero automorfico\n");
        printf("3. Ecuacion de segundo grado\n");
        printf("4. Fin\n");
        printf("Elige opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Has escogido la opcion %d.\n", opcion);
                printf("Indica un numero: ");
                fflush(stdin);
                scanf("%d", &num);
                printf("El factorial de %d es %f", num, factorial( num ));
                break;
            case 2:
                printf("Has escogido la opcion %d.\n", opcion);
                printf("Indica un numero: ");
                fflush(stdin);
                scanf("%d", &num);
                if ( esAutomorfico(num) ) {
                    printf("El numero %d es automorfico.\n", num);
                } else {
                    printf("El numero %d no es automorfico.\n", num);
                }
                break;
            case 3:
                printf("Has escogido la opcion %d.\n", opcion);
                printf("Indica el valor de a: ");
                scanf("%f", &a);
                printf("Indica el valor de b: ");
                scanf("%f", &b);
                printf("Indica el valor de c: ");
                scanf("%f", &c);
                ecSegundoGrado(a, b, c);
                break;
            case 4:
                printf("Fin de la aplicacion.\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    } while ( opcion != 4 );
    return 0;
}

double factorial( int num ) {
    if ( num == 1 ) {
        return num * 1;
    }
    return num * factorial(num-1);
}

bool esAutomorfico( int num ) {
    int cuad = num*num, num_c = num, q_dig = 0, i;
    bool automorfico = true;

    while ( num_c > 0 ) {
        num_c = num_c / 10;
        q_dig++;
    }

    for ( i=1; i<=q_dig; i++ ) {
        if ( num % 10 != cuad % 10 ) {
            automorfico = false;
        }
        num = num / 10;
        cuad = cuad / 10;
    }

    return automorfico;
}

void ecSegundoGrado( float a, float b, float c ) {
    float discriminante = (b*b) - (4*a*c);

    if ( discriminante < 0 ) {
        printf("Sin soluciones.\n\n");
    }
}
