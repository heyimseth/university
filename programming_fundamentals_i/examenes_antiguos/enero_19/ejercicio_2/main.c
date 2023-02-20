#include <stdio.h>
#include <stdbool.h>
#define F 20
#define C 40


bool nLibres(char fila[], int n);
void filasButacasLibre(char c[F][C], int n, int l[F]);


int main() {
    char cine[F][C];
//    char cine[F][C] = {
//            {'L','L','R','R','L','L','L','R','R'},
//            {'L','R','R','R','L','R','L','L','R'},
//            {'R','R','R','R','R','L','L','R','R'},
//            {'L','L','L','R','R','L','L','L','L'},
//            {'L','L','R','L','L','L','L','R','R'},
//            {'L','R','R','R','L','R','L','L','R'},
//            {'L','L','L','L','L','L','L','R','R'}
//    };
    int fila, n, libres[F];

    for ( int i = 0; i < F; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            cine[i][j] = 'L';
        }
    }

    printf("Indica fila en la que buscar: ");
    scanf("%d", &fila);
    printf("Indica numero de butacas: ");
    scanf("%d", &n);

    if ( nLibres(cine[fila],n) ) {
        printf("Hay mas de %d butacas libres en la fila %d.\n", n, fila);
    } else {
        printf("No hay tantas butacas libres.\n");
    }

    n=3;
    filasButacasLibre(cine, n, libres);

    for ( int i = 0; i < F; i++ ) printf("%d ", libres[i]);

    return 0;
}


bool nLibres(char fila[], int n) {
    int total = 0;

    for ( int i = 0; i < C; i++ ) {
        if ( fila[i] == 'L' ) {
            total++;
        }
    }

    if ( total > n ) return true;
    else return false;
}

void filasButacasLibre(char cine[F][C], int n, int libres[F]) {
    int cuenta = 1, pos = 0;

    for ( int i = 0; i < F; i++ ) {
        libres[i] = -1;

        if ( nLibres(cine[i], n) ) {
            for ( int j = 1; j < C; j++ ) {
                if ( cine[i][j] == 'L' && cine[i][j-1] == 'L' ) {
                    cuenta++;
                }
            }
            if ( cuenta >= n ) {
                libres[pos] = i;
                pos++;
            }
            cuenta = 1;
        }
    }
}
