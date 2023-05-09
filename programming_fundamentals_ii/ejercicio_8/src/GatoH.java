public class GatoH extends Mascota {
    public GatoH(String nombre) {
        super(nombre);
    }

    public void maulla() {
        System.out.println(this.nombre + ": miau!");
    }

    @Override
    public String toString() {
        return "Soy el gato " + this.nombre;
    }
}
