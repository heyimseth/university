package PaqComercio;

public abstract class Vehiculo {
    private String marca;
    private String modelo;
    private String matricula;



    /*########################### Constructores ##############################*/
    public Vehiculo(String marca, String modelo, String matricula) {
        this.marca = marca;
        this.modelo = modelo;
        this.matricula = matricula;
    }
    /*########################################################################*/



    /*######################### Getters y Setters ############################*/
    public String getMarca() { return this.marca; }
    public void setMarca(String marca) { this.marca = marca; }

    public String getModelo() { return this.modelo; }
    public void setModelo(String modelo) { this.modelo = modelo; }

    public String getMatricula() { return this.matricula; }
    public void setMatricula(String matricula) {this.matricula = matricula; }
    /*########################################################################*/



    /*########################### Otros métodos ##############################*/
    @Override
    public String toString() {
        return "Vehiculo " + this.marca + " " + this.modelo + " con matrícula "
                + this.matricula;
    }

    @Override
    public boolean equals(Object object) {
        if (object instanceof Vehiculo) {
            return this.matricula.equals(((Vehiculo) object).getMatricula());
        }

        return false;
    }

    public abstract Object clone();
    /*########################################################################*/
}
