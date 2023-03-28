package PaqViviendas;

public class Unifamiliar extends Vivienda {
    public Unifamiliar(double precio, int numeroDePlantas, int metros) {
        super(precio, numeroDePlantas, metros);
    }

    @Override
    public String toString() {
        return "Unifamiliar que cuesta " + this.precio + "€ (con un impuesto de " + this.impuesto() + ").";
    }
}
