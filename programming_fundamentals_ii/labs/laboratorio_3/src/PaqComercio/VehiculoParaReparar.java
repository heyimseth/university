package PaqComercio;

import java.io.*;

public class VehiculoParaReparar extends Vehiculo implements Serializable {
    private String averia;
    private boolean reparado;
    private int prioridad;



    /*########################### Constructores ##############################*/
    public VehiculoParaReparar(String marca, String modelo, String matricula,
                               String averia, int prioridad) {
        super(marca, modelo, matricula);
        this.averia = averia;
        this.prioridad = prioridad;
    }
    /*########################################################################*/



    /*######################### Getters y Setters ############################*/
    public String getAveria() { return this.averia; }
    public void setAveria(String averia) { this.averia = averia; }

    public boolean isReparado() { return this.reparado; }
    public void setReparado(boolean reparado) { this.reparado = reparado; }

    public int getPrioridad() { return this.prioridad; }
    public void setPrioridad(int prioridad) {
        if (prioridad >= 1 && prioridad <= 3) {
            this.prioridad = prioridad;
        }
    }
    /*########################################################################*/



    /*########################### Otros métodos ##############################*/
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
    /*########################################################################*/
}
