import excepciones.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Ejercicio 7 - Haz un programa principal que use los métodos implementados en cada uno de los
        // apartados.
        Urbanizacion urbanizacion1 = new Urbanizacion(7, 9);
        Adosado adosadoPrueba = new Adosado();
        Edificio edificioPrueba1 = new Edificio();
        Edificio edificioPrueba2 = new Edificio();
        Propietario propietario1 = new Propietario(24);
        Propietario propietario2 = new Propietario(29);
        edificioPrueba1.setPropietario(propietario1);
        edificioPrueba2.setPropietario(propietario2);
        adosadoPrueba.setPropietario(propietario1);

        // Prueba de método anadeVivienda(...)
        try {
            urbanizacion1.anadeVivienda(new Adosado(), 0, 0);
            urbanizacion1.anadeVivienda(new Adosado(), 0, 1);
            urbanizacion1.anadeVivienda(new Adosado(), 0, 2);
            urbanizacion1.anadeVivienda(adosadoPrueba, 0, 3);
            urbanizacion1.anadeVivienda(new Adosado(), 1, 4);
            urbanizacion1.anadeVivienda(new Adosado(), 1, 5);
            urbanizacion1.anadeVivienda(adosadoPrueba, 1, 6);
            urbanizacion1.anadeVivienda(new Adosado(), 1, 7);

            urbanizacion1.anadeVivienda(edificioPrueba1, 2, 0);
            urbanizacion1.anadeVivienda(new Edificio(), 2, 1);
            urbanizacion1.anadeVivienda(new Edificio(), 3, 0);
            urbanizacion1.anadeVivienda(edificioPrueba1, 3, 3);
            urbanizacion1.anadeVivienda(new Edificio(), 4, 6);
            urbanizacion1.anadeVivienda(edificioPrueba2, 4, 1);

            //urbanizacion1.anadeVivienda(new Adosado(), 5, 0); // Lanza excepción LugarIncorrectoException
            urbanizacion1.anadeVivienda(new Edificio(), 3, 0); // Lanza excepción ViviendaYaExisteException
        } catch (LugarIncorrectoException lie) {
            System.out.println(lie.getMessage());
        } catch (ViviendaYaExisteException vyee) {
            System.out.println(vyee.getMessage());
        }

        // Método eliminaVivienda(...)
        urbanizacion1.eliminaVivienda(adosadoPrueba);
        //urbanizacion1.eliminaVivienda(new Adosado()); // Lanza excepción unchecked NoExisteViviendaException

        // Método convertir3(), que llama a convertir1() y convertir2()
        System.out.println(Arrays.asList(urbanizacion1.U[0])); // comprobar orden
        System.out.println(Arrays.asList(urbanizacion1.U[2])); // comprobar orden
        System.out.println(urbanizacion1.convertir3());        // ver si se muestran en orden contrario

        System.out.println(urbanizacion1.buscaViviendas(propietario1));

        // Método eliminar(...)
        ArrayList<Vivienda> viviendas = urbanizacion1.convertir3();
        System.out.println("\n\nViviendas antes del eliminado: " + viviendas.size());
        ArrayList<Vivienda> eliminado = urbanizacion1.eliminar(edificioPrueba2.numCatastro);
        System.out.println("\n\nViviendas después del eliminado: " + eliminado.size());
    }
}
