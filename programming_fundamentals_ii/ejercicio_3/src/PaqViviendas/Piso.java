package PaqViviendas;

public class Piso extends Vivienda {
    protected boolean terraza;

    public Piso(double precio, int metros, boolean terraza) {
        super(precio, 1, metros);
        this.terraza = terraza;
    }

    @Override
    public double impuesto() {
        return super.getMetros() * 1.5;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("Piso que cuesta " + this.precio + "€ (con un impuesto de " +
                this.impuesto() + ").");

        if (this.terraza) {
            sb.append(" Con terraza.");
        } else {
            sb.append(" Sin terraza.");
        }

        return sb.toString();
    }
}
