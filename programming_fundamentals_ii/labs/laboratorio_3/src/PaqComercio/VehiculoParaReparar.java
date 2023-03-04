package PaqComercio;

public class VehiculoParaReparar extends Vehiculo {
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
    public VehiculoParaReparar clone() {
        VehiculoParaReparar v = new VehiculoParaReparar(super.getMarca(),
                super.getModelo(), super.getMatricula(), this.averia,
                this.prioridad);

        v.setReparado(this.reparado);

        return v;
    }
    /*########################################################################*/
}
