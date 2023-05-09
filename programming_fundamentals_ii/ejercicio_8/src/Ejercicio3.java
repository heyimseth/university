import java.util.ArrayList;

public class Ejercicio3 {
    public static void main(String[] args) {
        ArrayList todos = new ArrayList();

        // Añadir animales
        todos.add(new Perro("Bobby"));
        todos.add(new Gato("Garfield"));
        todos.add(new Gato("ConBotas"));
        todos.add(new Perro("Jimmy"));
        todos.add(new Perro("Oasis"));
        todos.add(new Gato("DGato"));
        todos.add(new Perro("Sanson"));

        // Recorre ese ArrayList básico con un for mejorado (for-each), y hazlos maullar o ladrar, según
        // corresponda, pero sin tener que conocer a priori en qué índice hay un gato o un perro.
        for (Object animal: todos) {
            if (animal.getClass() == Perro.class) {
                ((Perro) animal).ladra();
            } else if (animal.getClass() == Gato.class) {
                ((Gato) animal).maulla();
            }
        }

        // Crea un ArrayList que sólo contenga perros, e intenta añadir "Bobby", "Jimmy", "Oasis" y "Sanson",
        // y los gatos "Garfield", "ConBotas", "DGato"
        ArrayList<Perro> perros = new ArrayList<>();

        perros.add(new Perro("Bobby"));
        // perros.add(new Gato("Garfield")); // ERROR
        // perros.add(new Gato("ConBotas")); // ERROR
        perros.add(new Perro("Jimmy"));
        perros.add(new Perro("Oasis"));
        // perros.add(new Gato("DGato"));    // ERROR
        perros.add(new Perro("Sanson"));
    }
}
