package PaqComercio;

import java.time.LocalDateTime;

public abstract class Comercio {
    private String nombre;
    private String direccion;
    private String cif;
    private double[][] ventasDiarias;
    private int[] stock;
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

    /**
     * Obtener el stock de un artículo específico.
     * @param articulo          la posición del artículo a obtener el stock.
     * @return                  el stock del artículo.
     */
    public int getStock(int articulo) {
        if (articuloValido(articulo)) {
            return this.stock[articulo];
        }

        return -1;
    }

    /**
     * Asginar la cantidad de stock para un artículo específico.
     * @param articulo          la posición del artículo al que modificar la cantidad.
     * @param cantidad          la nueva cantidad del artículo.
     */
    public void setStock(int articulo, int cantidad) {
        if (articuloValido(articulo)) {
            this.stock[articulo] = cantidad;
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
     * correcto, la suma devuelta será -1.
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

        this.ventasDiarias[d_actual-1][m_actual-1] = cantidad;
    }

    //public String toStringStock() {}
    //public String toStringVentasDiarias() {}

    @Override
    public abstract Object clone();

    private boolean diaMesValido(int dia, int mes) {
        return mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31;
    }

    private boolean articuloValido(int articulo) {
        return articulo >= 0 && articulo < this.stock.length;
    }
    /*######################################################################################################*/
}
