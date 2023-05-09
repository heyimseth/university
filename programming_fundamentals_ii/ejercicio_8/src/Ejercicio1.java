import java.util.ArrayList;

public class Ejercicio1 {
    private ArrayList ejerc1 = new ArrayList();

    public Ejercicio1() {
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
        this.addEntero();
        this.imprimirArrayList();
        this.mostrarLongitud3();
    }

    public void addElementos() {
        this.ejerc1.add("Red");
        this.ejerc1.add("Green");
        this.ejerc1.add("Orange");
        this.ejerc1.add("White");
        this.ejerc1.add("Black");
    }

    // Imprime el contenido del ArrayList.
    public void imprimirArrayList() {
        System.out.println(this.ejerc1);
    }

    // Sobre el ArrayList del apartado anterior, añade la cadena "Pink" en la posición 0. Muestra el
    // contenido para comprobar
    public void addPink() {
        this.ejerc1.add(0, "Pink");
        System.out.println(this.ejerc1);
    }

    // Ahora cambia la posición 3 actual, que contiene "Orange" y pon en su lugar "Blue".
    public void addBlue() {
        this.ejerc1.remove(3);
        this.ejerc1.add(3, "Blue");
        System.out.println(this.ejerc1);
    }

    // Añade por el final el elemento "Purple". Muestra el contenido para comprobar.
    public void addPurple() {
        this.ejerc1.add("Purple");
        System.out.println(this.ejerc1);
    }

    // Lee específicamente lo que hay en las posiciones pares.
    public void elementosPares() {
        for (int i = 0; i < this.ejerc1.size(); i+=2) {
            System.out.println("Elemento par: " + this.ejerc1.get(i));
        }
    }

    // Elimina el color que exista en la posición 4. Muetra el contenido para comprobar.
    public void color4() {
        this.ejerc1.remove(4);
        System.out.println(this.ejerc1);
    }

    // Añade un entero cualquiera. Muestra el contenido para comprobar.
    public void addEntero() {
        this.ejerc1.add(8);
        System.out.println(this.ejerc1);
    }

    // Muestra en pantalla la longitud de la cadena en la posición 3 del ArrayList.
    public void mostrarLongitud3() {
        System.out.println(ejerc1.get(3).toString().length());
    }
}
