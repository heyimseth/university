package PaqViviendas;

public class Chalet extends Unifamiliar {
    public double metrosJardin;

    public Chalet(double precio, int numeroDePlantas, int metros, double metrosJardin) {
        super(precio, numeroDePlantas, metros);
        this.metrosJardin = metrosJardin;
    }
}
