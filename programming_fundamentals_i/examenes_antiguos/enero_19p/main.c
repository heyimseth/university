/*Nombre: Alvaro Martinez Alfaro
 * Grupo: 1B
 * DNI:                                                    */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 15
typedef struct  {
    int exp;
    float coef;
}termino;

 typedef struct _polinom {
    int numTerminos;
    termino t[N];
}polinomio;

/*NOTA.
*Los terminos no tienen que estar en orden del exponente.
* No puede haber mas de un termino con el mismo exponente 
  ej = 3x2+ 5x3+ x  */



void inicializaPolinomio(polinomio *pol);//inicializa el polinomio, numero de de terminos del polinomio sera 0
void introducePol(polinomio *pol, int numTerm) ;//introduce numTerm de monimios (terminos)en el polinomio pol

//Sumara dos polinomios pol1 y pol2 y la devuelve en suma
void sumapolinomio(polinomio pol1, polinomio pol2,polinomio *suma);
void imprime(polinomio pol);
int grado (polinomio p); // devuelve el grado de un polinomio
void cambiaSigno (polinomio *p); //cambia el signo de todos los terminos del polinomio



int main(int argc, char** argv) {

    polinomio polinomio1={4,{{2,7},{1,-6},{4,3},{5,3}} }; //7X2+6X+3X4+3X5.
    polinomio polinomio2, resultado;
    int ter;
    int opcion;
    inicializaPolinomio(&polinomio2);
    imprime(polinomio1);//muestra polinomio 1
    printf("\n: introduce el polinomio 2 \n");
    printf("\nintroduce cuantos terminos tiene el polinomio \n");
    scanf("%d", &ter);
    introducePol(&polinomio2,ter);
    imprime(polinomio2);//muestra polinomio 2
     
    do{
    printf("\nMENU\n") ;   
    printf("\nintroduce 1: muestra el grado del prolinomio1 )");
    printf("\nintroduce 2: cambia de signo e imprime el polimomio1 ");
    printf("\nintroduce 3: sumar polinomio1 y polinomio2");
    printf("\nintroduce 4: terminar\n");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("Grado del polinomio ");
            imprime(polinomio1);
            printf(" : %d", grado(polinomio1));
            break;
        case 2:
            cambiaSigno(&polinomio1);
            imprime(polinomio1);//muestra polinomio 1
            break;
        case 3:  
              printf("las suma de polinomios es");
            sumapolinomio(polinomio1, polinomio2, &resultado);
            imprime(resultado);         
            break;       
        case 4:
            printf("Terminar\n");
    }
    }while (opcion!=4);
    return (EXIT_SUCCESS);
}
//inicializa el polinomio, numero de de terminos del polinomio sera 0
void inicializaPolinomio(polinomio *pol){
    
     pol->numTerminos=0;
}

// devuelve el grado de un polinomio (polinomio no ordenado)
int grado(polinomio p) {
    int mayor = 1;

    for ( int i = 0; i < p.numTerminos; i++ ) {
        if ( p.t[i].exp > mayor ) {
            mayor = p.t[i].exp;
        }
    }

    return mayor;
}
 
//modifica el polonomio cambiando el signo de los coeficientes del polinomio
void cambiaSigno (polinomio *p){
    for ( int i = 0; i < p->numTerminos; i++ ) {
        p->t[i].coef = -p->t[i].coef;
    }
}

//introduce desde teclado los valores de un termino
 termino introduceMon() {
    termino ter;
    printf("introduce el termino  del polinomio( coeficiente y exponente) \n");
    scanf("%f %d", &ter.coef, &ter.exp);
    return ter;
    
}

//introduce numTerm de monimios (terminos)en el polinomio pol
void introducePol(polinomio *pol, int numTerm) {
    termino t;
    bool existe = false;

    while ( numTerm != 0 ) {
        t = introduceMon();

        for ( int i = 0; i < pol->numTerminos; i++ ) {
            if ( pol->t[i].exp == t.exp ) {
                existe = true;
            }
        }

        if ( existe ) {
            printf("[ERROR] Ya has introducido un termino con ese "
                   "grado. No puede haber dos terminos de mismo grado.\n");
        } else {
            pol->t[pol->numTerminos] = t;
            pol->numTerminos++;
            numTerm--;
        }
        existe = false;
    }
}


//devuelve el indice donde se encuentra el primer termino con exponente exp dado
int buscaExponente(polinomio pol, int exp ){
    int i,j=0;
    
    for(i=0;i< pol.numTerminos;i++){ 
        if (pol.t[i].exp ==exp)
            return i;
    }
    return -1;
}

//Sumara dos polinomios pol1 y pol2 y la devuelve en suma
void sumapolinomio(polinomio pol1, polinomio pol2, polinomio *suma) {
    int i,aux; //los polinomios no repiten exponentes 
   
    *suma = pol1;
    for (i = 0; i < pol2.numTerminos; i++) {
         aux = buscaExponente(*suma, pol2.t[i].exp);
         printf("\n\n%d\n\n", aux);
         if ( aux == -1 ) {
             aux = suma->numTerminos;
             suma->numTerminos++;
             suma->t[aux].exp = pol2.t[i].exp;
         }
         suma->t[aux].coef += pol2.t[i].coef;
    }
}

//lo muestre por pantalla en su formato tradicional.(ej   3x2+ 5x3+ x . ) 
void imprime(polinomio pol) {
    for ( int i = 0; i < pol.numTerminos; i++ ) {
        if ( pol.t[i].coef > 0 && i != 0 ) printf("+ ");
        printf("%.2fx%d ", pol.t[i].coef, pol.t[i].exp);
    }
}