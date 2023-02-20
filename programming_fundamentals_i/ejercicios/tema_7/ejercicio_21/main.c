/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Enunciado: se desea almacenar informacion relativa a las notas de los alumnos
 *            en una escuela. Las notas se almacenaran por cursos, de forma que
 *            de cada alumno se tenga la siguiente informacion: DNI, nombre,
 *            direccion, y las notas de los tres cursos. Se pide:
 *                  -crear la estructura de datos para almacenar dicha
 *                   informacion.
 *                  -escribir una funcion para introducir los datos de todos los
 *                   alumnos de la escuela.
 *                  -escribir una funcion que nos devuelva la nota media de un
 *                   alumno en un curso determinado.
 ******************************************************************************/
#include <stdio.h>
#define CURSOS 3
#define ASIGN_CURSO 5
#define MAX_ALUMNOS 1000

typedef struct {
    int dni;
    char nombre_completo[50];
    char direccion[50];
    float notas[CURSOS][ASIGN_CURSO];
} TIPO_ALUMNO;

TIPO_ALUMNO alumnos[MAX_ALUMNOS];
int num_alumnos = 0;


void introducirAlumnos( int num );
float notaMediaCurso( int d, int c );


int main() {
    int n = 0, dni, curso;

    printf("Indica cuantos alumnos hay en la escuela (max. %d): ",
           MAX_ALUMNOS);
    scanf("%d", &n);

    introducirAlumnos(n);
    printf("\n\nIndica DNI del alumno del que calcular la media: ");
    scanf("%d", &dni);
    printf("Indica curso: ");
    scanf("%d", &curso);

    printf("\nLa nota media del alumno en ese curso es: %.2f.\n",
           notaMediaCurso(dni, curso));

    return 0;
}


void introducirAlumnos( int num ) {
    while ( num_alumnos < num ) {
        printf("Indica DNI del alumno: ");
        scanf("%8d", &alumnos[num_alumnos].dni);
        printf("Indica nombre completo del alumno: ");
        fflush(stdin);
        gets(alumnos[num_alumnos].nombre_completo);
        printf("Indica direccion del alumno: ");
        fflush(stdin);
        gets(alumnos[num_alumnos].direccion);
        printf("Indica notas del alumno: ");
        for ( int i = 0; i < CURSOS; i++ ) {
            printf("Curso %d.\n", i+1);
            for ( int j = 0; j < ASIGN_CURSO; j++ ) {
                printf("\tAsignatura %d: ", j+1);
                scanf("%f", &alumnos[num_alumnos].notas[i][j]);
            }
        }
        num_alumnos++;
    }
}

int buscarAlumno( int dni ) {
    int pos = -1, i = 0;

    while ( pos == -1 && i < num_alumnos ) {
        if ( alumnos[i].dni == dni ) {
            pos = i;
        }

        i++;
    }

    return pos;
}

float notaMediaCurso( int d, int c ) {
    int pos;
    float media = 0;

    pos = buscarAlumno(d);
    if ( pos != -1 ) {
        for ( int j = 0; j < ASIGN_CURSO; j++ ) {
            media += alumnos[pos].notas[c-1][j];
        }
    }

    return media / ASIGN_CURSO;
}
