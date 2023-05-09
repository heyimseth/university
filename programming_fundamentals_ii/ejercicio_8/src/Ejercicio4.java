import java.util.ArrayList;
import java.util.Collection;
import java.util.ListIterator;

public class Ejercicio4 {
    public static void main(String[] args) {
        // Haz un ArrayList misMascotas que contenga solo objetos de la clase Mascota.
        ArrayList<Mascota> misMascotas = new ArrayList<>();

        // Intenta añadir los perros (esta vez de la clase PerroH) "Bobby", "Jimmy", "Oasis" y "Sanson", y
        // los gatos (esta vez de la clase GatoH) "Garfield", "ConBotas", "DGato".
        misMascotas.add(new PerroH("Bobby"));
        misMascotas.add(new PerroH("Jimmy"));
        misMascotas.add(new PerroH("Oasis"));
        misMascotas.add(new PerroH("Sanson"));
        misMascotas.add(new GatoH("Garfield"));
        misMascotas.add(new GatoH("ConBotas"));
        misMascotas.add(new GatoH("DGato"));

        // Recorre ese ArrayList genérico con un for mejorado, y hazlos maullar o ladrar según corresponda,
        // pero sin tener que reconocer a priori en qué índice hay un gato o un perro.
        for (Mascota mascota: misMascotas) {
            if (mascota.getClass() == PerroH.class) {
                ((PerroH) mascota).ladra();
            } else if (mascota.getClass() == GatoH.class) {
                ((GatoH) mascota).maulla();
            }
        }

        // Añade en Mascota un método cualquiera que imprima algo por pantalla, y vuelve a recorrer ese
        // ArrayList genérico llamando a ese método para todos los objetos del ArrayList. Encuentra la
        // diferencia en funcionamiento entre este punto y el anterior.
        for (Mascota mascota: misMascotas) {
            mascota.mostrarMascota();
        }

        // En el Main crea un ArrayList de PerroH, y añade cuatro perros con nombres distintos, intenta
        // llamar al método procesaElementos1 con él como argumento.
        ArrayList<PerroH> perros = new ArrayList<>();
        perros.add(new PerroH("BatDog"));
        perros.add(new PerroH("Dogin"));
        perros.add(new PerroH("Doger"));
        perros.add(new PerroH("Super Dog"));
        Ejercicio4.procesaElementos1(perros);

        // En el Main crea un ArrayList de GatoH, y añade tres gatos con nombres distintos, intenta llamar
        // al método procesaElementos1 con él como argumento.
        ArrayList<GatoH> gatos = new ArrayList<>();
        gatos.add(new GatoH("Catverine"));
        gatos.add(new GatoH("Wonder Cat"));
        gatos.add(new GatoH("Green Catern"));
        Ejercicio4.procesaElementos1(gatos);

        // En el Main crea un ArrayList de String, y añade los nombres de tus tres colores favoritos, e
        // intenta llamar al método procesaElementos1 con él como argumento.
        ArrayList<String> colores = new ArrayList<>();
        colores.add("Black");
        colores.add("White");
        colores.add("Red");
        // Ejercicio4.procesaElementos1(colores); // ERROR, no es un ArrayList de objetos que hereden de
        // la clase Mascota


        Ejercicio4.procesaElementos2(misMascotas);

        Ejercicio4.iteradorBasico(misMascotas);
        Ejercicio4.iteradorGenerico(misMascotas);

        // Crea un ArrayList de String que se llamará nombres. Con un for mejorado, añade en él los nombres
        // de todas las mascotas guardadas en misMascotas. Comprueba que nombres contiene los valores que
        // debería.
        ArrayList<String> nombres = new ArrayList<>();

        for (Mascota mascota: misMascotas) {
            nombres.add(mascota.nombre);
        }

        ListIterator<String> nombresItr = nombres.listIterator();
        while (nombresItr.hasNext()) {
            if (nombresItr.next().length() != 5) {
                nombresItr.remove();
            }
        }

        System.out.println("Nombres de longitud 5: " + nombres);

        // Haz lo mismo que has hecho, pero sin usar iteradores.
        ArrayList<String> nombres2 = new ArrayList<>();

        for (Mascota mascota: misMascotas) {
            nombres2.add(mascota.nombre);
        }

        int i_nombres2 = 0;

        while (i_nombres2 != nombres2.size()) {
            if (nombres2.get(i_nombres2).length() != 5) {
                nombres2.remove(i_nombres2);
                continue;
            }
            i_nombres2++;
        }

        System.out.println("Nombres de longitud 5: " + nombres2);
    }

    // Escribe dentro de la clase Ejercicio4 un método estático void procesaElementos1(ArrayList<? extends
    // Mascota>), que lo que haga sea llamar al método que tú mismo añadiste en el último punto del
    // ejercicio 4.
    public static void procesaElementos1(ArrayList<? extends Mascota> mascotas) {
        for (Mascota mascota: mascotas) {
            mascota.mostrarMascota();
        }
    }

    // Haz un método estático que sea void procesaElementos2(ArrayList<? super Mascota>) que haga las
    // mismas acciones de procesaElementos1. Mira con qué tipo de ArrayList lo podrías llamar, y créalo (si
    // no lo tienes) para comprobar que la llamada funciona.
    // ---Objetos de tipo Mascota y sus superclases. En este caso, Mascota y Object.
    public static void procesaElementos2(ArrayList<? super Mascota> mascotas) {
        for (Object mascota: mascotas) {
            if (mascota instanceof Mascota) {
                ((Mascota) mascota).mostrarMascota();
            }
        }
    }

    // Recorre el ArrayList misMascotas con un iterador básico (sin tipado) y muestra el nombre de todas
    // ellas una a una.
    public static void iteradorBasico(ArrayList<? extends Mascota> mascotas) {
        ListIterator iterator = mascotas.listIterator();

        System.out.println("Iterador básico:");
        while (iterator.hasNext()) {
            System.out.println(((Mascota) iterator.next()).nombre);
        }
    }

    // Recorre el ArrayList misMascotas con un iterador genérico (con tipado) y muestra el nombre de todas
    // ellas una a una.
    public static void iteradorGenerico(ArrayList<Mascota> mascotas) {
        ListIterator<Mascota> iterator = mascotas.listIterator();

        System.out.println("Iterador genérico:");
        while (iterator.hasNext()) {
            System.out.println((iterator.next()).nombre);
        }
    }
}
