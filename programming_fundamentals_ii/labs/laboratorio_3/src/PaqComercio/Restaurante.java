package PaqComercio;

/**
 * Clase que define un Comercio de tipo Restaurante. Un restaurante, además de la información típica de un
 * comercio, también almacena el número de mesas disponibles, la capacidad total, y el menú diario para toda
 * la semana.
 *
 * @see Comercio
 */
public class Restaurante extends Comercio {
    private String[] menuDiario;
    private int numMesas;
    private int capacidad;


    /**
     * Constructor de la clase Restaurante. Construye un nuevo restaurante a partir de su nombre, dirección,
     * CIF, un empleado, el número de mesas y la capacidad del restaurante..
     *
     * @param nombre el nombre del restaurante.
     * @param direccion la dirección del restaurante.
     * @param cif el CIF del restaurante.
     * @param empleado primer Empleado del restaurante.
     * @param numMesas el número de mesas del restaurante.
     * @param capacidad la capacidad del restaurante.
     */
    public Restaurante(String nombre, String direccion, String cif, Empleado empleado, int numMesas,
                       int capacidad) {
        super(nombre, direccion, cif, empleado);
        this.menuDiario = new String[7];
        this.setNumMesas(numMesas);
        this.setCapacidad(capacidad);
    }


    /**
     * Obtener el número de mesas de este Restaurante.
     * @return el número de mesas del restaurante.
     */
    public int getNumMesas() { return this.numMesas; }


    /**
     * Asigna el número de mesas que tendrá este Restaurante. Si el número de mesas es menor que 1, por
     * defecto se asigna una mesa.
     * @param numMesas el número de mesas del restaurante.
     */
    public void setNumMesas(int numMesas) {
        if (numMesas < 1) {
            numMesas = 1;
        }

        this.numMesas = numMesas;
    }


    /**
     * Obtener la capacidad de este Restaurante.
     * @return la capacidad del restaurante.
     */
    public int getCapacidad() { return this.capacidad; }


    /**
     * Asigna la capacidad que tendrá este Restaurante. Si la capacidad es inferior a 4, se asigna 4 por
     * defecto, puesto que siempre habrá, al menos una mesa.
     * @param capacidad la capacidad del restaurante.
     */
    public void setCapacidad(int capacidad) {
        if (capacidad < 4) {
            capacidad = 4;
        }

        this.capacidad = capacidad;
    }


    /**
     * Fija el menú del día de la semana indicado. El día debe ser un número positivo comprendido entre 1 y
     * 7, ambos incluidos.
     * @param menuDia menú del día.
     * @param dia día de la semana en la que fijar el menú.
     */
    public void fijarMenuDia(String menuDia, int dia) {
        if (menuDia != null && dia >= 1 && dia <= 7) {
            this.menuDiario[dia-1] = menuDia;
        }
    }


    /**
     * Devuelve el menú del día indicado, o null si el día no está comprendido entre 1 y 7, ambos incluidos.
     * @param dia día de la semana del que obtener el menú.
     * @return menú del día indicado.
     */
    public String verMenuDia(int dia) {
        if (dia >= 1 && dia <= 7) {
            return this.menuDiario[dia-1];
        }

        return null;
    }


    // TODO: implementar
    @Override
    public String toStringStock() {
        return null;
    }
}
