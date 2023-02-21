package Lab2Project;
import java.util.Random;

/**
 * Clase que define objetos con conjuntos de números complejos y permite la suma
 * de todos ellos. Los números se generan aleatoriamente, con valores entre 1 y
 * 16.5.
 *
 * @author Álvaro Martínez Alfaro
 * @version 1.0, 02/16/2023
 */

public class VariosNumComplejos {
    private NumComplejo[] numeros;

    /**
     * Constructor para la clase VariosNumComplejos. Genera, aleatoriamente,
     * n números complejos, siempre que n sea mayor que 0, y con valores para
     * la parte real e imaginaria entre 1 y 16.5
     * @param n         cantidad de números complejos a generar. Debe ser mayor
     *                      que 0
     *                      que 0
     */
    public VariosNumComplejos(int n) {
        if ( n > 0 ) {
            this.numeros = new NumComplejo[n];
            Random r = new Random();

            for ( int i = 0; i < n; i++ ) {
                this.numeros[i] = new NumComplejo(
                        r.nextInt(5)*3.1 + 1,
                        r.nextInt(5)*3.1 + 1
                );
            }
        }
    }

    /**
     * Obtener el número complejo en la posición p.
     * @param p         posición en la que se encuentra el número complejo.
     * @return          objeto NumComplejo en la posición p si p es una posición
     *                      válida.
     */
    public NumComplejo getComplejo(int p) {
        if ( p >= 0 && p < this.numeros.length) {
            return this.numeros[p];
        }

        return new NumComplejo(0,0);
    }

    /**
     * Asigna al número complejo p los valores indicados para la parte real e
     * imaginaria.
     * @param p             posición del número complejo
     * @param real          valor a asignar a la parte real.
     * @param imaginaria    valor a asignar a la parte imaginaria.
     */
    public void setComplejo(int p, double real, double imaginaria) {
        if ( p >= 0 && p < this.numeros.length ) {
            this.numeros[p].setReal(real);
            this.numeros[p].setImaginaria(imaginaria);
        }
    }

    /**
     * Calcula la suma de todos los números complejos creados.
     * @return      objeto NumComplejo con el resultado de sumar todos los
     *                  números complejos almacenados.
     */
    public NumComplejo sumaTodos() {
        NumComplejo num = new NumComplejo(0, 0);

        for ( int i = 0; i < this.numeros.length; i++ ) {
            num = NumComplejo.sumar(num, this.numeros[i]);
        }

        return num;
    }

    /**
     * Muestra todos los números complejos almacenados en un formato amigable.
     * @return      String con los números complejos en formato amigable,
     *                  "real + imaginaria(i)".
     */
    public String toString() {
        String str = " ";

        for ( int i = 0; i < this.numeros.length; i++ ) {
            str = str.concat(this.numeros[i].toString() + "\n");
        }

        return str;
    }


}
