/*******************************************************************************
 * Autor: Alvaro Martinez Alfaro
 * Programa: gestor de planificacion anual de empleados de una residencia.
 *           Para cada dia de trabajo, se crea una ficha en la que se anota
 *           turno de trabajo (libre, mañana, tarde, noche), trabajo a
 *           desarrollar (limpieza, comida, aseo personal), hora de entrada y
 *           salida. Esta informacion se almacena para cada dia del año
 *           clasificados por meses.
 *              a) Definir los tipos necesarios para almacenar la informacion
 *              de la planificacion de un trabajador.
 *              b) Crear una funcion que dado el numero de un mes calcule y
 *              devuelva el numero de dias que ha trabajado en el turno de noche
 ******************************************************************************/
#include <stdio.h>

typedef enum {libre, manana, tarde, noche} TURNO_TRABAJO;

typedef enum {limpieza, comida, aseo_personal} TIPO_TRABAJO;

typedef struct {
    int hora;
    int min;
} HORA;

typedef struct {
    TURNO_TRABAJO turno;
    int planta;
    TIPO_TRABAJO trabajo;
    HORA hora_entrada;
    HORA hora_salida;
} FICHA;

int cantidadDiasTurnoNoche( FICHA planificacion[12][31], int mes );



int main() {
    FICHA planificacion_trabajador[12][31];

    return 0;
}

int cantidadDiasTurnoNoche( FICHA planificacion[12][31], int mes ) {
    int q, total_dias = 0;

    if ( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10
            || mes == 12 ) q = 31;
    else if ( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) q = 30;
    else q = 28;

    for ( int i = 0; i < q; i++ )
        if ( planificacion[mes-1][i].turno == noche ) total_dias++;

    return total_dias;
}
