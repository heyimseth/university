package PaqComercio;

import java.time.LocalDateTime;
import java.util.Arrays;

abstract class Comercio {
    private String nombre;
    private String direccion;
    private String cif;
    private double[][] ventasDiarias;
    protected int[] stock;
    private Empleado[] empleados;



    /*######################################### Constructores ##############################################*/
    /**
     * Constructor de la clase Comercio. Construye un nuevo comercio a partir de su nombre, dirección, CIF,
     * y un empleado.
     * @param nombre            el nombre del comercio.
     * @param direccion         la dirección del comercio.
     * @param cif               el CIF del comercio.
     * @param empleado          primer Empleado del comercio.
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
    /*######################################################################################################*/



    /*####################################### Getters y setters ############################################*/
    /**
     * Obtener el nombre del comercio.
     * @return                  el nombre del comercio.
     */
    public String getNombre() { return this.nombre; }

    /**
     * Asignar nombre al comercio.
     * @param nombre            el nombre del comercio.
     */
    public void setNombre(String nombre) { this.nombre = nombre; }

    /**
     * Obtener la dirección del comercio.
     * @return                  la dirección del comercio.
     */
    public String getDireccion() { return this.direccion; }

    /**
     * Asignar la dirección del comercio.
     * @param direccion         la dirección del comercio.
     */
    public void setDireccion(String direccion) { this.direccion = direccion; }

    /**
     * Obtener el CIF del comercio.
     * @return                  el CIF del comercio.
     */
    public String getCif() { return this.cif; }

    /**
     * Asignar el CIF del comercio.
     * @param cif               el CIF del comercio.
     */
    public void setCif(String cif) { this.cif = cif; }

    /**
     * Obtener las ventas que se han realizado en el día y mes indicados.
     * @param dia               el día del que obtener las ventas.
     * @param mes               el mes del que obtener las ventas.
     * @return                  ventas realizadas el "día" del "mes".
     */
    public double getVentasDia(int dia, int mes) {
        if (diaMesValido(dia, mes)) {
            return this.ventasDiarias[mes-1][dia-1];
        }

        return -1;
    }

    // TODO la asignación de Stock la deben realizar las clases hijas
//    /**
//     * Obtener el stock de un artículo específico.
//     * @param articulo          la posición del artículo a obtener el stock.
//     * @return                  el stock del artículo.
//     */
//    public int getStock(int articulo) {
//        if (articuloValido(articulo)) {
//            return this.stock[articulo];
//        }
//
//        return -1;
//    }
//
//    /**
//     * Asginar la cantidad de stock para un artículo específico.
//     * @param articulo          la posición del artículo al que modificar la cantidad.
//     * @param cantidad          la nueva cantidad del artículo.
//     */
//    public void setStock(int articulo, int cantidad) {
//        if (articuloValido(articulo)) {
//            this.stock[articulo] = cantidad;
//        }
//    }

    /**
     * Busca y devuelve al empleado cuyo nombre coincida con el nombre indicado como parámetro. Devuelve un
     * empleado nulo si no se ha encontrado a ninguno con ese nombre.
     * @param nombre            el nombre del empleado.
     * @return                  el empleado.
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
     * @param empleado          el empleado a añadir a la lista de empleados.
     */
    public void setEmpleado(Empleado empleado) {
        if (empleado != null && this.getEmpleado(empleado.getNombre()) == null) {
            this.empleados = Arrays.copyOf(this.empleados, this.empleados.length+1);
            this.empleados[this.empleados.length-1] = empleado;
        }
    }
    /*######################################################################################################*/



    /*######################################### Otros métodos ##############################################*/
    /**
     * Calcula el total de las ventas realizadas por el comercio.
     * @return                  suma total de las ventas realizadas.
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
     * @param mes               el mes en el que calcular el total.
     * @return                  el total de ventas realizadas en el mes indicado.
     */
    public double calcularVentasMes(int mes) {
        double total = 0;

        if (mes >= 1 && mes <= 12) {
            for (int i = 0; i < this.ventasDiarias[mes-1].length; i++) {
                total += this.ventasDiarias[mes-1][i];
            }

            return total;
        }

        return -1;
    }

    /**
     * Calcula el mes en el que se han realizado más ventas y lo devuelve en formato numérico (enero - 1,
     * febrero - 2, ..., diciembre - 12).
     * @return                  el mes en el que se han realizado más ventas.
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
                mes = i+1;
            }
            total_actual = 0;
        }

        return mes;
    }

    /**
     * Actualiza las ventas del día y mes en curso, asignando como cantidad vendida en el día el valor pasado
     * por parámetro.
     * @param cantidad          la cantidad vendida en el día actual.
     */
    public void actualizarVentas(double cantidad) {
        int d_actual = LocalDateTime.now().getDayOfMonth(), m_actual = LocalDateTime.now().getMonthValue();

        this.ventasDiarias[m_actual-1][d_actual-1] = cantidad;
    }

    /**
     * Devuelve una cadena en la que se indican las ventas diarias del mes actual.
     * @return                  cadena con las ventas diarias del mes actual.
     */
    public StringBuffer toStringVentasDiarias() {
        int m_actual = LocalDateTime.now().getMonthValue();
        StringBuffer ventas = new StringBuffer("Ventas diarias de "
                + LocalDateTime.now().getMonth().toString() + "\n");

        for ( int i = 0; i < this.ventasDiarias[m_actual-1].length; i++) {
            if (this.ventasDiarias[m_actual-1][i] != 0) {
                ventas.append("Día ").append(i + 1).append(": ").append(this.ventasDiarias[m_actual - 1][i])
                        .append("€\n");
            }
        }

        return ventas;
    }

    @Override
    public Object clone() {
        // TODO implementar
        return null;
    }

    public abstract String toStringStock();

    private boolean diaMesValido(int dia, int mes) {
        return mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31;
    }

    private boolean articuloValido(int articulo) {
        return articulo >= 0 && articulo < this.stock.length;
    }
    /*######################################################################################################*/
}
