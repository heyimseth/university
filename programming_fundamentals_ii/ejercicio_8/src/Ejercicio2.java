import java.util.ArrayList;

public class Ejercicio2 {
    private ArrayList<String> ejerc1Gen = new ArrayList<>();

    public Ejercicio2() {
        this.addElementos();
        this.imprimirArrayList();
        this.addPink();
        this.imprimirArrayList();
        this.addBlue();
        this.imprimirArrayList();
        this.addPurple();
        this.imprimirArrayList();
        this.elementosPares();
        this.color4();
        this.imprimirArrayList();
        this.mostrarLongitud3();
    }

    public void addElementos() {
        this.ejerc1Gen.add("Red");
        this.ejerc1Gen.add("Green");
        this.ejerc1Gen.add("Orange");
        this.ejerc1Gen.add("White");
        this.ejerc1Gen.add("Black");
    }

    // Imprime el contenido del ArrayList.
    public void imprimirArrayList() {
        System.out.println(this.ejerc1Gen);
    }

    // Sobre el ArrayList del apartado anterior, añade la cadena "Pink" en la posición 0. Muestra el
    // contenido para comprobar
    public void addPink() {
        this.ejerc1Gen.add(0, "Pink");
        System.out.println(this.ejerc1Gen);
    }

    // Ahora cambia la posición 3 actual, que contiene "Orange" y pon en su lugar "Blue".
    public void addBlue() {
        this.ejerc1Gen.remove(3);
        this.ejerc1Gen.add(3, "Blue");
        System.out.println(this.ejerc1Gen);
    }

    // Añade por el final el elemento "Purple". Muestra el contenido para comprobar.
    public void addPurple() {
        this.ejerc1Gen.add("Purple");
        System.out.println(this.ejerc1Gen);
    }

    // Lee específicamente lo que hay en las posiciones pares.
    public void elementosPares() {
        for (int i = 0; i < this.ejerc1Gen.size(); i+=2) {
            System.out.println("Elemento par: " + this.ejerc1Gen.get(i));
        }
    }

    // Elimina el color que exista en la posición 4. Muetra el contenido para comprobar.
    public void color4() {
        this.ejerc1Gen.remove(4);
        System.out.println(this.ejerc1Gen);
    }

    // Muestra en pantalla la longitud de la cadena en la posición 3 del ArrayList.
    public void mostrarLongitud3() {
        System.out.println(ejerc1Gen.get(3).toString().length());
    }
}
