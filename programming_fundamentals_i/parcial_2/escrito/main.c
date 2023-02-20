#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//Escribe aqui tu nombre, tu dni y el grupo en el que estas matriculado
// Alvaro Martinez Alfaro
// Grupo 1 B
// DNI: 

#define N1 4
#define N2 3
// Para ejercicio 1, matriz de pixeles
#define N 250
#define M 400


//Define aqui los tipos de datos pedidos en el ejercicio 1
typedef struct {
    unsigned short int colores[3], contraste;
    short int exposicion;
} T_PIXEL;

typedef struct {
    T_PIXEL imagen[N][M];
    char modelo_camara[25];
    int velocidad_disparo;
    float abertura_diafragma;
    bool flash;
} T_IMAGEN;

T_IMAGEN img;



//Completa esta funcion como respuesta al ejercicio 2
//Debes completar la cabecera y el cuerpo
void Subcadena ( char cadena[], int p, int n, char subcadena[] ) {
    if ( p > strlen(cadena) ) {
        p = strlen(cadena);
    }
    if ( n > p ) {
        n = p;
    }
    subcadena[n] = '\0';

    while ( n > 0 && p > 0 ) {
        subcadena[n-1] = cadena[p-1];
        n--, p--;
    }
}


void intercambiaDiagonales(int n, int m[n][n]){
//Completa el cuerpo de esta funcion como respuesta a la pregunta 4 del examen
    int aux;

    for ( int i = 0; i < n; i++ ) {
        aux = m[i][i];
        m[i][i] = m[i][n-1-i];
        m[i][n-1-i] = aux;
    }
}


int main() {
    int opc;
    int m1[N1][N1]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int m2[N2][N2]={{1,2,3},{4,5,6},{7,8,9}};
    int f,c;
    int pos, num;
    char cadena[150], subcadena[150];

    printf("-----------------------------------------------------\n");
    printf("EXAMEN DE FUNDAMENTOS DE PROGRAMACION I\n");
    printf("-----------------------------------------------------\n");
    do {
        printf ("3.- Ejercicio Cadenas\n");
        printf ("4.- Ejercicio Matrices\n");
        printf ("5.- Salir\n");
        scanf("%d",&opc);
        switch(opc){
            case 3://Completa esta parte del programa como respuesta al ejercicio 3
                printf("\nIndica una cadena (max. 150 caracteres): ");
                fflush(stdin);
                gets(cadena);
                printf("Indica posicion: ");
                scanf("%d", &pos);
                printf("Indica numero de caracteres: ");
                scanf("%d", &num);
                Subcadena(cadena, pos, num, subcadena);
                printf("\nLa subcadena obtenida es '%s'.\n\n", subcadena);
                break;
            case 4:
                intercambiaDiagonales(N1,m1);
                for(f=0;f<N1;f++) {
                    for (c = 0; c < N1; c++) printf("%3d\t", m1[f][c]);
                    printf("\n");
                }
                intercambiaDiagonales(N2,m2);
                for(f=0;f<N2;f++) {
                    for (c = 0; c < N2; c++) printf("%3d\t",m2[f][c]);
                    printf("\n");
                }
                break;
            case 5: printf("Biennnnnn.  Voy a a probar\n");
                break;

            default: printf("Opcion incorrecta. elija otra\n");

        }
    }while(opc!=5);
    return 0;
}
