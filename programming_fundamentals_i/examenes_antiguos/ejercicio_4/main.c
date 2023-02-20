/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa:
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>

void sumaVocales( char vector[], int tam, int suma[] );

int main() {
    int tam, suma[5] = {0,0,0,0,0};

    printf("Indica longitud del vector: ");
    scanf("%d", &tam);
    char vector[tam];

    for ( int i = 0; i < tam; i++ ) {
        fflush(stdin);
        printf("Indica caracter: ");
        scanf("%c", &vector[i]);
    }

    sumaVocales(vector, tam, suma);
    for ( int i = 0; i < 5; i++ ) {
        printf("%d ", suma[i]);
    }

    return 0;
}

void sumaVocales( char vector[], int tam, int suma[] ) {
    for ( int i = 0; i < tam; i++ ) {
        switch(toupper(vector[i])) {
            case 'A':
                suma[0] += 1;
                break;
            case 'E':
                suma[1] += 1;
                break;
            case 'I':
                suma[2] += 1;
                break;
            case 'O':
                suma[3] += 1;
                break;
            case 'U':
                suma[4] += 1;
                break;
        }
    }
}
