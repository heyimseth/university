package Lab2Project;

/**
 * Clase que define un escalar (número real).
 *
 * @author Álvaro Martínez Alfaro
 * @version 1.0, 02/22/2023
 */
public class Escalar {
    private double escalar;

    /**
     * Construye un objeto Escalar con el número real indicado.
     * @param escalar       número real a utilizar
     */
    public Escalar(double escalar) {
        this.escalar = escalar;
    }

    /**
     * Construye un objeto Escalar con el objeto Double indicado.
     * @param escalar       objeto Double a utilizar.
     */
    public Escalar(Double escalar) {
        this.escalar = escalar;
    }

    /**
     * Obtener el valor del escalar.
     * @return              escalar almacenado
     */
    public double getEscalar() { return this.escalar; }

    /**
     * Guarda el número real indicado en el objeto escalar.
     * @param escalar       Double con el número real.
     */
    public void setEscalar(Double escalar) {
        this.escalar = escalar.doubleValue();
    }

    /**
     * Guarda el número real indicado en el objeto escalar.
     * @param escalar       número real.
     */
    public void setEscalar(double escalar) {
        this.escalar = escalar;
    }
}
