import java.util.Date;

/**
 * Clase Persona que representa a una persona específica.
 * @author Álvaro Martínez Alfaro
 * @version 1.0
 */
public class Persona {
    private String nombre;
    private String nombreDePila;
    private String apellido;
    private int edad;
    private int telefono;
    private int aNacimiento;


    /**
     * Obtener el nombre de la persona.
     * @return                  el nombre de la persona.
     */
    public String getNombre() { return this.nombre; }

    /**
     * Asignar el nombre de la persona.
     * @param nombre            el nombre de la persona.
     */
    public void setNombre(String nombre) { this.nombre = nombre; }

    /**
     * Obtener el nombre de pila de la persona.
     * @return                  el nombre de pila de la persona.
     */
    public String getNombreDePila() { return this.nombreDePila; }

    /**
     * Asignar el nombre de pila de la persona.
     * @param nombreDePila      el nombre de pila de la persona.
     */
    public void setNombreDePila(String nombreDePila) { this.nombreDePila = nombreDePila; }

    /**
     * Obtener el apellido de la persona.
     * @return                  el apellido de la persona.
     */
    public String getApellido() { return this.apellido; }

    /**
     * Asignar el apellido de la persona.
     * @param apellido          el apellido de la persona.
     */
    public void setApellido(String apellido) { this.apellido = apellido; }

    /**
     * Obtener la edad de la persona.
     * @return                  la edad de la persona.
     */
    public int getEdad() { return this.edad; }

    /**
     * Asignar la edad de la persona.
     * @param edad              la edad de la persona.
     */
    public void setEdad(int edad) { this.edad = edad; }

    /**
     * Obtener el teléfono de la persona.
     * @return                  el teléfono de la persona.
     */
    public int getTelefono() { return this.telefono; }

    /**
     * Asignar el teléfono de la persona.
     * @param telefono          el teléfono de la persona.
     */
    public void setTelefono(int telefono) { this.telefono = telefono; }

    /**
     * Obtener el año de nacimiento de la persona.
     * @return                  el año de nacimiento de la persona.
     */
    public int getaNacimiento() { return this.aNacimiento; }

    /**
     * Asignar el año de nacimiento de la persona. También calcula su edad a partir de la diferencia entre
     * el año actual y aNacimiento.
     * @param aNacimiento       el año de nacimiento de la persona.
     */
    public void setaNacimiento(int aNacimiento) {
        this.aNacimiento = aNacimiento;
        this.edad = new Date().getYear() + 1900 - aNacimiento;
    }


    /**
     * Construye y devuelve una cadena en la que se indica el nombre de la persona
     * @return                  String con la información de la persona.
     */
    public String mostrar() {
        return this.nombre + " " + this.apellido + "(" + this.nombreDePila + ") tiene " + this.edad + " y su "
        + "teléfono es " + this.telefono;
    }

    /**
     * Cambia el nombre por el nombre completo de la persona, resultado de concatenar los atributos nombre y
     * apellido.
     */
    public void constructName() { this.nombre += " " + this.apellido; }
}
