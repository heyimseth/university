import java.util.ArrayList;
import java.util.Iterator;

import excepciones.*;

public class Urbanizacion {
    //las filas 0 y 1 son adosados y el resto son edificios.
    Vivienda [][] U;

    /**
     * Constructor de la clase Urbanización. Inicializa la Urbanización a partir del número de plantas y
     * número de pisos por planta, siempre que estos sean un número entero positivo. En caso contrario, se
     * inicializa la Urbanización con una planta y un piso por planta.
     * @param nPlantas número de plantas de la Urbanización
     * @param nPisos número de pisos de la Urbanización
     */
    public Urbanizacion(int nPlantas, int nPisos) {
        if (nPlantas > 0 && nPisos > 0) {
            this.U = new Vivienda[nPlantas][nPisos];
        } else {
            this.U = new Vivienda[1][1];
        }
    }

    // las excepciones son de tipo checked
    public void anadeVivienda(Vivienda v, int i, int j) throws LugarIncorrectoException,
            ViviendaYaExisteException {
        if ((i < 0 || i >= this.U.length) || (j < 0 || j >= this.U[0].length) ||
                (v.getClass() == Adosado.class && i >= 2) || (v.getClass() == Edificio.class && i < 2)) {
            throw new LugarIncorrectoException();
        }

        if (this.U[i][j] != null) {
            throw new ViviendaYaExisteException();
        }

        this.U[i][j] = v;
    }

    // la excepción será de tipo unchecked
    public void eliminaVivienda(Vivienda v) throws NoExisteViviendaException {
        int c = 2, l = this.U.length;

        if (v.getClass() == Adosado.class) {
            c = 0;
            l = 2;
        }

        for (int nPlanta = c; nPlanta < l; nPlanta++) {
            for (int nPiso = 0; nPiso < this.U[nPlanta].length; nPiso++) {
                if (this.U[nPlanta][nPiso] != null && this.U[nPlanta][nPiso].numCatastro == v.numCatastro) {
                    this.U[nPlanta][nPiso] = null;
                    return;
                }
            }
        }

        throw new NoExisteViviendaException();
    }

    // Ejercicio 2 - Crea en la clase Urbanización un método llamado convertir1 que devuelva, usando la
    // sentencia return, un ArrayList de adosados con todos los adosados de la urbanización en orden inverso.
    private ArrayList<Adosado> convertir1() {
        ArrayList<Adosado> adosados = new ArrayList<>();

        for (int i = 1; i >= 0; i-- ) {
            for (int j = this.U[i].length-1; j >= 0; j--) {
                if (this.U[i][j] != null) {
                    adosados.add((Adosado) this.U[i][j]);
                }
            }
        }

        return adosados;
    }

    // Ejercicio 3 - Crea en la clase Urbanización un método llamado convertir2 que devuelva, usando la
    // sentencia return, un ArrayList de edificios con todos los edificios de la urbanización en orden
    // inverso.
    private ArrayList<Edificio> convertir2() {
        ArrayList<Edificio> edificios = new ArrayList<>();

        for (int i = this.U.length-1; i >= 2; i--) {
            for (int j = this.U[i].length-1; j >= 0; j--) {
                if (this.U[i][j] != null) {
                    edificios.add((Edificio) this.U[i][j]);
                }
            }
        }

        return edificios;
    }

    // Ejercicio 4 - Crea en la clase Urbanización un método llamado convertir3 que devuelva, usando la
    // sentencia return, un ArrayList que consista en la unión del vector devuelto en el ejercicio 1 con el
    // vector devuelto en el ejercicio 2.
    public ArrayList convertir3() {
        ArrayList viviendas = new ArrayList();

        viviendas.addAll(this.convertir1());
        viviendas.addAll(this.convertir2());

        return viviendas;
    }

    // Ejercicio 5 - Crea en la clase Urbanización un método llamado buscaViviendas que acepte como
    // argumento un propietario y devuelva en un ArrayList todas las viviendas que ha comprado un propietario.
    public ArrayList<Vivienda> buscaViviendas(Propietario propietario) {
        ArrayList<Vivienda> viviendas = new ArrayList<>();

        if (propietario != null) {
            for (int nPlanta = 0; nPlanta < this.U.length; nPlanta++) {
                for (int nPiso = 0; nPiso < this.U[nPlanta].length; nPiso++) {
                    if (this.U[nPlanta][nPiso] != null) {
                        if (this.U[nPlanta][nPiso].getPropietario() != null &&
                                this.U[nPlanta][nPiso].getPropietario().equals(propietario)) {
                            viviendas.add(this.U[nPlanta][nPiso]);
                        }
                    }
                }
            }
        }

        return viviendas;
    }

    // Ejercicio 6 - Crea en la clase Urbanización un método llamado eliminar que, dada una referencia
    // catastral, borre la vivienda que coincida con esa referencia catastral del ArrayList devuelto por el
    // método convertir3 usando un iterador.
    public ArrayList<Vivienda> eliminar(int refCatastral) {
        ArrayList<Vivienda> viviendas = this.convertir3();
        Iterator iterador = viviendas.iterator();

        while (iterador.hasNext()) {
            if (((Vivienda) iterador.next()).numCatastro == refCatastral) {
                iterador.remove();
            }
        }

        return viviendas;
    }
}
