public class Perro {
    private String nombre;

    Perro(String n) {
        nombre = n;
    }

    public void ladra() {
        System.out.println(nombre + ": guau!");
    }

    @Override
    public String toString() {
        return "Soy el perro " + nombre;
    }
}
