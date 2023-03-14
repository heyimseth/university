package PaqComercio;

import java.util.Arrays;

public class Concesionario extends Comercio {
    private VehiculoVenta[] v;
    private VehiculoParaReparar[] r;



    /*######################################### Constructores ##############################################*/
    /**
     * Constructo de la clase Concesionario, que permite crear un comercio de tipo concesionario a partir de
     * su nombre, dirección, CIF, un empleado, y un vehículo a poner a la venta. Hace uso de
     * {@link Vehiculo#Vehiculo(String, String, String) Vehiculo}.
     * @param nombre            el nombre del concesionario.
     * @param direccion         la dirección del concesionario.
     * @param cif               el CIF del concesionario.
     * @param empleado          primer empleado del concesionario.
     * @param vehiculo          primer vehículo a la venta en el concesionario.
     */
    public Concesionario(String nombre, String direccion, String cif, Empleado empleado,
                         VehiculoVenta vehiculo) {
        super(nombre, direccion, cif, empleado);
        this.v = new VehiculoVenta[1];
        v[0] = vehiculo;
        super.stock[0] = 1;
        this.r = new VehiculoParaReparar[0];
    }
    /*######################################################################################################*/



    /*####################################### Getters y setters ############################################*/
    /**
     * Busca y devuelve un vehículo que se encuentre a la venta y cuya matrícula coincida con la indicada,
     * o nulo si no se ha encontrado ninguno coincidente.
     * @param matricula         matrícula del vehículo a la venta.
     * @return                  vehículo a la venta encontrado.
     */
    public VehiculoVenta getVehiculoVenta(String matricula) {
        VehiculoVenta vehiculo = null;
        int i = 0;

        while (vehiculo == null && i < this.v.length) {
            if (this.v[i].getMatricula().equals(matricula)) vehiculo = this.v[i];
            i++;
        }


        return vehiculo;
    }

    /**
     * Busca y devuelve un vehículo que se encuentre a la venta y cuya matrícula coincida con la indicada,
     * o nulo si no se ha encontrado ninguno coincidente.
     * @param matricula         matrícula del vehículo a reparar.
     * @return                  vehículo a reparar encontrado.
     */
    public VehiculoParaReparar getVehiculoParaReparar(String matricula) {
        VehiculoParaReparar vr = null;

        for (int i = 0; i < this.r.length && vr == null; i++) {
            if (this.r[i].getMatricula().equals(matricula)) {
                vr = this.r[i];
            }
        }

        return vr;
    }

    /*######################################################################################################*/



    /*######################################### Otros métodos ##############################################*/
    /**
     * Construye y devuelve una cadena con los vehículos que se encuentran a la venta.
     * @return                  cadena con los vehículos a la venta.
     */
    public String toStringVehiculosVenta() {
        StringBuffer sb = new StringBuffer("Vehículos a la venta:\n\t");

        for (int i = 0; i < this.v.length; i++) {
            sb.append(this.v[i].toString()).append("\n\t");
        }

        return sb.toString();
    }

    /**
     * Construye y devuelve una cadena con los vehículos que se encuentran pendientes de reparar.
     * @return                  cadena con los vehículos a reparar.
     */
    public String toStringVehiculosReparar() {
        StringBuffer sb = new StringBuffer("Vehículos pendientes de reparar:\n\t");

        for (int i = 0; i < this.r.length; i++) {
            sb.append(this.r[i].toString()).append("\n\t");
        }

        return sb.toString();
    }

    /**
     * Añade un vehículo al listado de vehículos a la venta si este no se encuentra ya en el listado de
     * vehículos a la venta o en el listado de vehículos a reparar. Se entiende que dos vehículos son iguales
     * si tienen la misma matrícula, independientemente del resto de información del vehículo.
     * @param vehiculoVenta                 nuevo vehículo a poner a la venta.
     */
    public void addVenta(VehiculoVenta vehiculoVenta) {
        if (this.buscarVehiculo(vehiculoVenta.getMatricula()) == -1) {
            this.v = Arrays.copyOf(this.v, this.v.length+1);
            this.v[this.v.length-1] = vehiculoVenta;
            this.stock = Arrays.copyOf(this.stock, this.stock.length+1);
            this.stock[this.stock.length-1] = 1;
        }
    }

    /**
     * Añade un vehículo al listado de vehículos a reparar si este no se encuentra ya en el listado de
     * vehículos a la venta o en el listado de vehículos a reparar. Se entiende que dos vehículos son iguales
     * si tienen la misma matrícula, independientemente del resto de información del vehículo.
     * @param vehiculoParaReparar           vehículo pendiente de reparar.
     */
    public void addReparar(VehiculoParaReparar vehiculoParaReparar) {
        boolean insertado = false;

        if (this.buscarVehiculo(vehiculoParaReparar.getMatricula()) == -1) {
            this.r = Arrays.copyOf(this.r, this.r.length+1);

            for (int i = 0; i < this.r.length && !insertado; i++) {
                if (this.r[i] != null) {
                    if (this.r[i].getPrioridad() > vehiculoParaReparar.getPrioridad()) {
                        for (int j = this.r.length-1; j > i; j--) {
                            this.r[j] = this.r[j-1];
                        }
                    }
                }
                this.r[i] = vehiculoParaReparar;
                insertado = true;
            }
        }
    }

    /**
     * Vende el vehículo en la posición indicada del listado. La posición debe encontrarse en el rango válido
     * de vehículos a la venta. En caso de que la posición indicada no sea válida, el valor devuelto será
     * nulo.
     * @param posicion          posición en la que se encuentra el vehículo.
     * @return                  vehículo vendido.
     */
    public VehiculoVenta venderVehiculo(int posicion) {
        VehiculoVenta vv = null;

        if (posicion >= 0 && posicion < this.v.length) {
            vv = this.v[posicion];
            for (int i = posicion; i < this.v.length-1; i++) {
                this.v[i] = this.v[i+1];
                this.stock[i] = this.stock[i+1];
            }
            this.v = Arrays.copyOf(this.v, this.v.length-1);
            this.stock = Arrays.copyOf(this.stock, this.stock.length-1);
        }

        return vv;
    }


    /**
     * Busca el vehículo con la matrícula indicada en el listado de vehículos a reparar. Devuelve el vehículo
     * si lo ha encontrado y este se encuentra reparado, o nulo si no se ha encontrado el vehículo o todavía
     * no ha sido reparado.
     * @param matricula         matrícula del vehículo a recoger.
     * @return                  el vehículo.
     */
    public VehiculoParaReparar recogerVehiculo(String matricula) {
        VehiculoParaReparar vr = null;
        int pos = this.buscarVehiculo(matricula);

        if (pos != -1 && this.r[pos].isReparado()) {
            vr = this.r[pos];
            for (int i = pos; i < this.r.length-1; i++) {
                this.r[i] = this.r[i+1];
            }
            this.r = Arrays.copyOf(this.r, this.r.length-1);
        }

        return vr;
    }

    /**
     * Dada una posición del listado de vehículos a reparar, marca el vehículo como reparado.
     * @param posicion          la posición en el listado del vehículo a marcar como reparado.
     */
    public void repararVehiculo(int posicion) {
        if (posicion >= 0 && posicion < this.r.length && this.r[posicion] != null) {
            this.r[posicion].setReparado(true);
        }
    }

    /**
     * Construye y devuelve una cadena con el stock disponible de cada vehículo a la venta.
     * @return                  cadena con el stock de cada vehículo.
     */
    public String toStringStock() {
        StringBuffer sb = new StringBuffer();

        for (int i = 0; i < v.length && v[i] != null; i++) {
            sb.append(this.v[i].toString()).append(" - Stock:").append(super.stock[i]).append("\n");
        }

        return sb.toString();
    }


    private int buscarVehiculo(String matricula) {
        int p = -1;

        if (matricula != null) {
            for (int i = 0; i < this.v.length && p == -1; i++) {
                if (this.v[i].getMatricula().equals(matricula)) {
                    p = i;
                }
            }

            for (int i = 0; i < this.r.length && p == -1; i++) {
                if (this.r[i].getMatricula().equals(matricula)) {
                    p = i;
                }
            }
        }

        return p;
    }
    /*######################################################################################################*/
}
