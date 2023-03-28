package PaqViviendas;

public class CasaDeCampo extends Vivienda {
    protected double metrosParcela;
    protected Chalet chalet;

    public CasaDeCampo(double precio, int numeroDePlantas, int metros, double metrosParcela, Chalet chalet) {
        super(precio, numeroDePlantas, metros);
        this.metrosParcela = metrosParcela;
        this.chalet = chalet;
    }

    @Override
    public double impuesto() {
        return chalet.impuesto() + (0.5 * this.metrosParcela);
    }

    @Override
    public String toString() {
        return "Casa de campo que cuesta " + this.precio + "€ (con un impuesto de " + this.impuesto() + ").";
    }
}
