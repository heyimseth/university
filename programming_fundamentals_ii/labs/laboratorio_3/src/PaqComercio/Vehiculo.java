package PaqComercio;

/**
 * Clase abstracta que define un vehículo. La información almacenada sobre un vehículo es la marca, modelo y
 * matrícula.
 */
abstract class Vehiculo implements Cloneable {
    private String marca;
    private String modelo;
    private String matricula;


    /**
     * Constructor de la clase Vehículo. Construye un vehículo a partir de su marca, modelo y matrícula.
     *
     * @param marca marca del vehículo.
     * @param modelo modelo del vehículo.
     * @param matricula matrícula del vehículo.
     */
    public Vehiculo(String marca, String modelo, String matricula) {
        this.marca = marca;
        this.modelo = modelo;
        this.matricula = matricula;
    }


    /**
     * Obtener la marca de este vehículo.
     *
     * @return marca del vehículo.
     */
    public String getMarca() { return this.marca; }


    /**
     * Asignar la marca de este vehículo.
     * @param marca marca del vehículo.
     */
    public void setMarca(String marca) { this.marca = marca; }


    /**
     * Obtener el modelo de este vehículo.
     * @return modelo del vehículo.
     */
    public String getModelo() { return this.modelo; }


    /**
     * Asignar el modelo de este vehículo.
     * @param modelo modelo del vehículo.
     */
    public void setModelo(String modelo) { this.modelo = modelo; }


    /**
     * Obtener la matrícula de este vehículo.
     * @return matrícula del vehículo.
     */
    public String getMatricula() { return this.matricula; }


    /**
     * Asignar la matrícula de este vehículo.
     * @param matricula matrícula del vehículo.
     */
    public void setMatricula(String matricula) {this.matricula = matricula; }


    @Override
    public abstract String toString();


    /**
     * Clona este vehículo.
     *
     * @return clonación del vehículo.
     * @throws CloneNotSupportedException se realiza una llamada al método clone de la clase superior, es
     *                                    posible que se lance la excepción si la clase no implementa la
     *                                    interfaz Cloneable.
     */
    public Vehiculo clone() throws CloneNotSupportedException {
        Vehiculo copia = (Vehiculo) super.clone();

        copia.marca = new String(this.marca);
        copia.modelo = new String(this.modelo);
        copia.matricula = new String(this.matricula);

        return copia;
    }


    /**
     * Comprueba si un objeto es igual a este vehículo comparando la clase y, si son iguales, la matrícula del
     * vehículo.
     *
     * @param object el objeto a comprobar si es igual a este vehículo.
     * @return verdadero o falso en función de si son o no iguales.
     */
    @Override
    public boolean equals(Object object) {
        if (object instanceof Vehiculo) {
            return this.matricula.equals(((Vehiculo) object).getMatricula());
        }

        return false;
    }
}
