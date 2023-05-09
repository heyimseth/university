public class Gato {
    private String nombre;

    Gato(String n) {
        nombre = n;
    }

    public void maulla() {
        System.out.println(nombre + ": miau!");
    }

    @Override
    public String toString() {
        return "Soy el gato " + nombre;
    }
}
