public class PerroH extends Mascota {
    public PerroH(String nombre) {
        super(nombre);
    }

    public void ladra() {
        System.out.println(this.nombre + ": guau!");
    }

    @Override
    public String toString() {
        return "Soy el perro " + this.nombre;
    }
}
