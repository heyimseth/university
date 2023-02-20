#include <stdio.h>

/* Programa que lee el numero premiado del sorteo de la ONCE
 * e imprime en pantalla la ultima cifra del mismo */
int main() {
    int num;

    printf("Indica el numero premiado del sorteo de la ONCE:\t");
    scanf("%d", &num);

    /* El resto de la division entera por 10 es la ultima cifra
     * del numero indicado. Por ejemplo, si el numero premiado
     * es 82734, el resultado de la division entera 82734 / 10
     * es 8273, y el resto 4. */
    printf("El ultimo digito de %d es %d.", num, num % 10);

    return 0;
}
