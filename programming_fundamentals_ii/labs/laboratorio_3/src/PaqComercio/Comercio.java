package PaqComercio;

import java.time.LocalDateTime;
import java.util.Arrays;

/**
 * Clase abstracta que define un Comercio. Almacena información que podría tener cualquier comercio, como el
 * nombre, dirección, cif, ventas diarias realizadas el año presente, el stock o los empleados del comercio.
 *
 * @see Empleado
 */
abstract class Comercio implements Cloneable {
    private String nombre;
    private String direccion;
    private String cif;
    private double[][] ventasDiarias;
    protected int[] stock;
    private Empleado[] empleados;


    /**
     * Constructor de la clase Comercio. Construye un nuevo comercio a partir de su nombre, dirección, CIF,
     * y un empleado.
     *
     * @param nombre    el nombre del comercio.
     * @param direccion la dirección del comercio.
     * @param cif       el CIF del comercio.
     * @param empleado  primer Empleado del comercio.
     */
    public Comercio(String nombre, String direccion, String cif, Empleado empleado) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.cif = cif;
        this.ventasDiarias = new double[12][31];
        this.stock = new int[1];
        this.empleados = new Empleado[1];
        this.empleados[0] = empleado;
    }


    /**
     * Obtener el nombre del comercio.
     *
     * @return el nombre del comercio.
     */
    public String getNombre() {
        return this.nombre;
    }


    /**
     * Asignar nombre al comercio.
     *
     * @param nombre el nombre del comercio.
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }


    /**
     * Obtener la dirección del comercio.
     *
     * @return la dirección del comercio.
     */
    public String getDireccion() {
        return this.direccion;
    }


    /**
     * Asignar la dirección del comercio.
     *
     * @param direccion la dirección del comercio.
     */
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }


    /**
     * Obtener el CIF del comercio.
     *
     * @return el CIF del comercio.
     */
    public String getCif() {
        return this.cif;
    }


    /**
     * Asignar el CIF del comercio.
     *
     * @param cif el CIF del comercio.
     */
    public void setCif(String cif) {
        this.cif = cif;
    }


    /**
     * Obtener las ventas que se han realizado en el día y mes indicados.
     *
     * @param dia el día del que obtener las ventas.
     * @param mes el mes del que obtener las ventas.
     * @return ventas realizadas el "día" del "mes".
     */
    public double getVentasDia(int dia, int mes) {
        if (diaMesValido(dia, mes)) {
            return this.ventasDiarias[mes - 1][dia - 1];
        }

        return -1;
    }


    /**
     * Busca y devuelve al empleado cuyo nombre coincida con el nombre indicado como parámetro. Devuelve un
     * empleado nulo si no se ha encontrado a ninguno con ese nombre.
     *
     * @param nombre el nombre del empleado.
     * @return el empleado.
     */
    public Empleado getEmpleado(String nombre) {
        Empleado e = null;
        int i = 0;

        while (e == null && i < empleados.length) {
            if (empleados[i].getNombre().equals(nombre)) e = empleados[i];
            i++;
        }

        return e;
    }


    /**
     * Añade un empleado a la lista de empleados del comercio si este no es nulo y si el empleado indicado
     * no es ya un empleado del comercio.
     *
     * @param empleado el empleado a añadir a la lista de empleados.
     */
    public void setEmpleado(Empleado empleado) {
        if (empleado != null && this.getEmpleado(empleado.getNombre()) == null) {
            this.empleados = Arrays.copyOf(this.empleados, this.empleados.length + 1);
            this.empleados[this.empleados.length - 1] = empleado;
        }
    }


    /**
     * Calcula el total de las ventas realizadas por el comercio.
     *
     * @return suma total de las ventas realizadas.
     */
    public double calcularTotalVentas() {
        double total = 0;

        for (int i = 0; i < this.ventasDiarias.length; i++) {
            for (int j = 0; j < this.ventasDiarias[i].length; j++) {
                total += this.ventasDiarias[i][j];
            }
        }

        return total;
    }


    /**
     * Calcula el total de ventas realizadas en un mes concreto indicado como parámetro. Si el mes no es
     * correcto (entero en el rango 1-12), la suma devuelta será -1.
     *
     * @param mes el mes en el que calcular el total.
     * @return el total de ventas realizadas en el mes indicado.
     */
    public double calcularVentasMes(int mes) {
        double total = 0;

        if (mes >= 1 && mes <= 12) {
            for (int i = 0; i < this.ventasDiarias[mes - 1].length; i++) {
                total += this.ventasDiarias[mes - 1][i];
            }

            return total;
        }

        return -1;
    }


    /**
     * Calcula el mes en el que se han realizado más ventas y lo devuelve en formato numérico (enero - 1,
     * febrero - 2, ..., diciembre - 12).
     *
     * @return el mes en el que se han realizado más ventas.
     */
    public int mesConMasVentas() {
        int mes = 1;
        double total_actual = 0, maximo = 0;

        for (int i = 0; i < this.ventasDiarias.length; i++) {
            for (int j = 0; j < this.ventasDiarias[i].length; j++) {
                total_actual += this.ventasDiarias[i][j];
            }
            if (total_actual > maximo) {
                maximo = total_actual;
                mes = i + 1;
            }
            total_actual = 0;
        }

        return mes;
    }


    /**
     * Actualiza las ventas del día y mes en curso, asignando como cantidad vendida en el día el valor pasado
     * por parámetro.
     *
     * @param cantidad la cantidad vendida en el día actual.
     */
    public void actualizarVentas(double cantidad) {
        int d_actual = LocalDateTime.now().getDayOfMonth(), m_actual = LocalDateTime.now().getMonthValue();

        this.ventasDiarias[m_actual - 1][d_actual - 1] = cantidad;
    }


    /**
     * Devuelve una cadena en la que se indican las ventas diarias del mes actual.
     *
     * @return cadena con las ventas diarias del mes actual.
     */
    public StringBuffer toStringVentasDiarias() {
        int m_actual = LocalDateTime.now().getMonthValue();
        StringBuffer ventas = new StringBuffer("Ventas diarias de " + LocalDateTime.now().getMonth().toString() + "\n");

        for (int i = 0; i < this.ventasDiarias[m_actual - 1].length; i++) {
            if (this.ventasDiarias[m_actual - 1][i] != 0) {
                ventas.append("Día ").append(i + 1).append(": ").append(this.ventasDiarias[m_actual - 1][i]).append("€\n");
            }
        }

        return ventas;
    }


    /**
     * Realiza una deep copy del objeto.
     *
     * @return la deep copy del objeto.
     * @throws CloneNotSupportedException se realiza una llamada al método clone de la clase superior, es
     *                                    * posible que se lance la excepción si la clase no implementa la interfaz Cloneable.
     */
    public Comercio clone() throws CloneNotSupportedException {
        Comercio clone = (Comercio) super.clone();

        // clonación de tipos de datos simples
        clone.nombre = new String(this.nombre);         // las cadenas son inmutables
        clone.direccion = new String(this.direccion);
        clone.cif = new String(this.cif);
        clone.empleados = new Empleado[this.empleados.length];

        // clonación de tipos de datos compuestos
        for (int i = 0; i < this.empleados.length; i++) {
            clone.empleados[i] = this.empleados[i].clone(); // el método Empleado.clone() clona serializando
        }

        for (int i = 0; i < this.stock.length; i++) {
            clone.stock[i] = this.stock[i]; // datos primitivos, copiamos valor
        }

        for (int i = 0; i < this.ventasDiarias.length; i++) {
            for (int j = 0; j < this.ventasDiarias[i].length; j++) {
                clone.ventasDiarias[i][j] = this.ventasDiarias[i][j]; // datos primitivos, copiamos valor
            }
        }

        return clone;
    }


    public abstract String toStringStock();


    private boolean diaMesValido(int dia, int mes) {
        return mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31;
    }
}
