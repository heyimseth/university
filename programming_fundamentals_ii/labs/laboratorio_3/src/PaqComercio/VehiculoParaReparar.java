package PaqComercio;

import java.io.*;

/**
 * Clase que define un vehículo pendiente de reparar o reparado. La información que se almacena, además de
 * la información típica de un vehículo, como marca, modelo o matrícula, es el tipo de avería, si este ha sido
 * reparado o aún está pendiente de reparar y la prioridad de reparación.
 *
 * @see Vehiculo
 */
public class VehiculoParaReparar extends Vehiculo implements Serializable {
    private String averia;
    private boolean reparado;
    private int prioridad;


    /**
     * Constructor de la clase VehiculoParaReparar. Construye un objeto para un vehículo pendiente de
     * reparación a partir de su marca, modelo, matrícula, avería y prioridad.
     * @param marca la marca del vehículo.
     * @param modelo el modelo del vehículo.
     * @param matricula la matrícula del vehículo.
     * @param averia la avería del vehículo.
     * @param prioridad la prioridad del vehículo.
     */
    public VehiculoParaReparar(String marca, String modelo, String matricula,
                               String averia, int prioridad) {
        super(marca, modelo, matricula);
        this.averia = averia;
        this.prioridad = prioridad;
    }


    /**
     * Obtener la avería de este vehículo.
     * @return la avería.
     */
    public String getAveria() { return this.averia; }


    /**
     * Asignar una avería a reparar a este vehículo.
     * @param averia la avería del vehículo.
     */
    public void setAveria(String averia) { this.averia = averia; }

    /**
     * Comprobar si este vehículo ya ha sido reparado.
     * @return booleano indicando si el vehículo ya ha sido reparado.
     */
    public boolean isReparado() { return this.reparado; }


    /**
     * Cambiar el estado de reparación de este vehículo a reparado (true) o no reparado (false).
     * @param reparado booleano indicando el nuevo estado de reparación.
     */
    public void setReparado(boolean reparado) { this.reparado = reparado; }


    /**
     * Obtener la prioridad de reparación de este vehículo.
     * @return prioridad de reparación.
     */
    public int getPrioridad() { return this.prioridad; }


    /**
     * Asignar una prioridad de reparación a este vehículo. El valor debe estar comprendido entre 1 y 3,
     * ambos incluidos.
     * @param prioridad prioridad de reparación a asignar.
     */
    public void setPrioridad(int prioridad) {
        if (prioridad >= 1 && prioridad <= 3) {
            this.prioridad = prioridad;
        }
    }


    /**
     * Devuelve una cadena con la información de este vehículo a reparar, indicando su marca, modelo, la
     * avería, y si ha sido o no reparado de la misma, así como su prioridad de reparación.
     * @return la cadena con la información del vehículo a reparar.
     */
    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer(this.getMarca() + " " + this.getModelo());

        if (this.reparado) {
            sb.append(" ya ha sido reparado de " + this.averia + ".");
        } else {
            sb.append(" debe ser reparado de " + this.averia + " con prioridad " + this.prioridad + ".");
        }

        return sb.toString();
    }


    /**
     * Realiza una deep copy de este vehículo para reparar.
     * @return la deep copy del vehículo para reparar.
     * @throws CloneNotSupportedException se realiza una llamada al método clone de la clase superior, es
     *      * posible que se lance la excepción si la clase no implementa la interfaz Cloneable.
     */
    public VehiculoParaReparar clone() throws CloneNotSupportedException {
        VehiculoParaReparar copia = (VehiculoParaReparar) super.clone();

        copia.averia = new String(this.averia);
        copia.prioridad = this.prioridad;
        copia.reparado = this.reparado;

        return copia;
    }
}
