/*******************************************************************************
 * Autor: Álvaro Martínez Alfaro
 ******************************************************************************/
#include <stdio.h>
#include <math.h>

void obtenerMedias( int n, double *geometrica, double *armonica );
double mediaGeometrica( int n );
double mediaArmonica( int n );

int main() {
    int n;
    double m_geometrica, m_armonica;
    
    do {
        printf("Calcular media geometrica y armonica de n numeros.\n");
        printf("Indica un numero entero n (mayor que 0): ");
        fflush(stdin);
        scanf("%d", &n);
    } while ( n <= 0 );

    printf("Ahora debes indicar %d numeros mayores que 0 para calcular "
           "la media geometrica, y otros %d numeros mayores que 0 para calcular"
           " la media armonica. Si introduces un valor menor o igual que 0 no"
           "contara: \n", n, n);
    obtenerMedias( n, &m_geometrica, &m_armonica );
    printf("La media geometrica es %f y la media armonica es %f.\n",
           m_geometrica, m_armonica);

    printf("Ahora se va a calcular la media geometrica y armonica de "
           "12 numeros. Indica 12 numeros para la geometrica y otros 12 para"
           "la armonica, tambien mayores que 0: ");
    obtenerMedias( 12, &m_geometrica, &m_armonica );
    printf("La media geometrica es %f y la media armonica es %f.\n",
           m_geometrica, m_armonica);

    return 0;
}

void obtenerMedias( int n, double *geometrica, double *armonica ) {
    *geometrica = mediaGeometrica( n );
    *armonica = mediaArmonica( n );
}

double mediaGeometrica( int n ) {
    int i = 1, num = 0;
    double base = 1;
    double media_geometrica;

    do {
        fflush(stdin);
        scanf("%d", &num);
        if ( num > 0 ) {
            base *= num;
            i++;
        }
    } while ( i <= n );
    media_geometrica = pow(base, 1.0/n);

    return media_geometrica;
}

double mediaArmonica( int n ) {
    float denominador = 0;
    int i = 1, num;
    double media_geometrica;

    do {
        fflush(stdin);
        scanf("%d", &num);
        if ( num > 0 ) {
            denominador += 1.0 / num;
            i++;
        }
    } while( i <= n );
    media_geometrica = n / denominador;

    return media_geometrica;
}
