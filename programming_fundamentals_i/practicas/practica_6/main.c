#include <stdio.h>
#include <string.h>
#define MAX_COCHES_SECCION 10
#define MAX_PLANTAS 3
#define MAX_SECCION 4

// Deja el parking vacio de coches aparcados
void vaciarAparcamiento( int m[MAX_PLANTAS][MAX_SECCION],int disponibles[]);
// Muestra el total de plazas disponibles por planta y por seccion
void ocupacion( int m[MAX_PLANTAS][MAX_SECCION],int disponibles[MAX_PLANTAS],
                char colorPlanta[MAX_PLANTAS][15]);
// Dado un numero de planta, devuelve la primera seccion en la que hay plazas
// libres
int plazasLibresPlanta( int m[MAX_PLANTAS][MAX_SECCION], int planta );
// Dado un numero de planta, la funcion busca una seccion libre en la planta
// para aparcar, si no encuentra ninguna, continua en el resto de plantas hasta
// alcanzar la superior. Devuelve el numero de planta en el que se ha aparcado
// o -1 si no hay plazas disponibles.
int aparcar( int m[MAX_PLANTAS][MAX_SECCION], int planta, int *total_libres,
             int disponibles[] );
// asigna a p un numero de planta en funcion de color, o -1 si el color de
// planta no existe
void colorAPlanta( char color[], int *p );


int main()
{   char colorPlanta[MAX_PLANTAS][15]={"roja","azul","amarilla"},
        color[15];
    int planta, total;
    int aparcamiento[MAX_PLANTAS][MAX_SECCION];
    int disponibles[MAX_PLANTAS];
    int opcion = 0, num_planta;
    vaciarAparcamiento( aparcamiento, disponibles );

    while ( opcion != 4 ) {
        printf("\nPARKING \n***********************\n\n\t");
        printf("1.Vaciar Aparcamiento\n\t");
        printf("2.Aparcar Coche (LA PLANTA BAJA ES LA 0)\n\t");
        printf("3.Comprobar ocupacion\n\t");
        printf("4.Salir\n\n\t\t");
        printf("Opcion:");
        scanf("%d",&opcion);

        switch ( opcion ) {
         case 1:
             vaciarAparcamiento( aparcamiento, disponibles );
                break;

         case 2:
                printf("Introduzca el color de la planta donde quiere "
                       "aparcar: ");
                scanf("%s", color);
                colorAPlanta(color, &num_planta);
                if ( num_planta >= 0 && num_planta < MAX_PLANTAS ) {
                    planta = aparcar(aparcamiento, num_planta,
                                     &total, disponibles);
                    if (planta != -1) {
                        printf("Se ha aparcado en la planta %s.\n",
                               colorPlanta[planta]);
                        printf("Plazas disponibles: %d", total);
                    } else {
                        printf("No hay plazas disponibles.");
                    }
                } else {
                    printf("Introduce un color de planta correcto (roja,"
                           " azul, amarilla).\n");
                }
                break;
            case 3:
                ocupacion( aparcamiento, disponibles, colorPlanta );
                break;
            case 4:
                printf("Fin de la Aplicacion");
                break;
            default:
                printf("Opcion Incorrecta ...");
        }
    }
}


void vaciarAparcamiento(int m[MAX_PLANTAS][MAX_SECCION],int disponibles[] ) {
    int i,j;

    for ( j = 0; j < MAX_PLANTAS; j++ ) {
        disponibles[j] = MAX_COCHES_SECCION * MAX_SECCION;
    }
       for ( i = 0; i < MAX_PLANTAS; i++ )
           for( j = 0; j < MAX_SECCION; j++ )
               m[i][j] = 0;
}


void ocupacion( int m[MAX_PLANTAS][MAX_SECCION], int disponibles[MAX_PLANTAS],
                char colorPlanta[MAX_PLANTAS][15] ) {
    int i,j;

    printf("\nPANEL DE CONTROL DE PLAZAS\n");

    for ( i = 0; i < MAX_PLANTAS; i++ ) {
        printf("\nExisten %d plazas disponibles en la planta %s\n\n",
               disponibles[i], colorPlanta[i]);
        for ( j = 0; j < MAX_SECCION; j++ ) {
            if ( m[i][j] != 0 )
               printf("\nPlanta %s Existen %d plazas disponibles en la "
                      "seccion %d\n",colorPlanta[i],
                      MAX_COCHES_SECCION-m[i][j],j+1);
        }
    }
}

int plazasLibresPlanta( int m[MAX_PLANTAS][MAX_SECCION], int planta ) {
    int seccion = -1, i = 0;

    while ( i < MAX_SECCION && seccion == -1 ) {
        if ( m[planta][i] < MAX_COCHES_SECCION ) {
            seccion = i;
        }
        i++;
    }

    return seccion;
}

int aparcar( int m[MAX_PLANTAS][MAX_SECCION], int planta, int *total_libres,
             int disponibles[] ) {
    int planta_aparcado = -1, i = planta;
    *total_libres = 0;

    if (plazasLibresPlanta(m, planta) != -1 ) {
        planta_aparcado = planta;
        disponibles[planta]--;
    } else {
        do {
            for ( int j = 0; j < MAX_SECCION; j++ ) {
                if ( plazasLibresPlanta(m, i) != -1 ) {
                    planta_aparcado = i;
                    disponibles[i]--;
                }
            }
            i++;
            if ( i == MAX_PLANTAS ) {
                i = 0;
            }
        } while ( i != planta );
    }

    for ( i = 0; i < MAX_PLANTAS; i++ ) {
        *total_libres = *total_libres + disponibles[i];
    }

    return planta_aparcado;
}

void colorAPlanta( char color[], int *p ) {
    if ( strcmp(color, "roja") == 0 ) {
        *p = 0;
    } else if ( strcmp(color, "azul") == 0 ) {
        *p = 1;
    } else if ( strcmp(color, "amarilla") == 0 ) {
        *p = 2;
    } else {
        *p = -1;
    }
}
