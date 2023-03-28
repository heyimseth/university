package PaqViviendas;

public abstract class Vivienda implements Comparable {
    protected double precio;
    protected double numeroDePlantas;
    protected int metros;

    public Vivienda(double precio, double numeroDePlantas, int metros) {
        this.precio = precio;
        this.numeroDePlantas = numeroDePlantas;
        this.metros = metros;
    }

    public double impuesto() {
        return (this.precio * 20) / 100;
    }

    public int getMetros() {
        return this.metros;
    }

    /**
     * Comparar este objeto con el objeto dado.
     * @param object el objeto a ser comparado.
     * @return 0 o -1 en función de si el objeto indicado es igual o distinto de este objeto, respectivamente.
     */
    @Override
    public int compareTo(Object object) {
        if (object.getClass() == this.getClass()) {
            if (((Vivienda) object).impuesto() == this.impuesto()) {
                return 0;
            } else if (((Vivienda) object).impuesto() > this.impuesto()) {
                return 1;
            }
        }
        return -1;
    }

    public abstract String toString();
}
