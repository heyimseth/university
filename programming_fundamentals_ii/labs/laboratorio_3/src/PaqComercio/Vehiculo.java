package PaqComercio;

/**
 * Clase abstracta que define un vehículo. La información almacenada sobre un vehículo es la marca, modelo y
 * matrícula.
 */
abstract class Vehiculo implements Cloneable {
    private String marca;
    private String modelo;
    private String matricula;


    public Vehiculo(String marca, String modelo, String matricula) {
        this.marca = marca;
        this.modelo = modelo;
        this.matricula = matricula;
    }


    public String getMarca() { return this.marca; }
    public void setMarca(String marca) { this.marca = marca; }

    public String getModelo() { return this.modelo; }
    public void setModelo(String modelo) { this.modelo = modelo; }

    public String getMatricula() { return this.matricula; }
    public void setMatricula(String matricula) {this.matricula = matricula; }


    @Override
    public abstract String toString();

    public Vehiculo clone() throws CloneNotSupportedException {
        Vehiculo copia = (Vehiculo) super.clone();

        copia.marca = new String(this.marca.getBytes());
        copia.modelo = new String(this.modelo.getBytes());
        copia.matricula = new String(this.matricula.getBytes());

        return copia;
    }

    @Override
    public boolean equals(Object object) {
        if (object instanceof Vehiculo) {
            return this.matricula.equals(((Vehiculo) object).getMatricula());
        }

        return false;
    }
}
