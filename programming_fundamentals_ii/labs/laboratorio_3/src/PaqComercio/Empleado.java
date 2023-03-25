package PaqComercio;

import java.io.Serializable;
import java.io.ByteArrayOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.IOException;

/**
 * Clase que define a un Empleado de un comercio. La información (atributos) definida para el empleado son
 * su nombre, dirección, número de teléfono, correo electrónico, fecha de inicio en el comercio, salario y
 * cargo o puesto en la empresa.</br></br>
 * Se implementa la interfaz Serializable para la clonación del objeto.
 *
 * @see java.io.Serializable
 */
public class Empleado implements Serializable {
    private String nombre;
    private String direccion;
    private int telefono;
    private String email;
    private String fechaInicio;
    private double salario;
    private String cargo;


    /**
     * Constructor de la clase Empleado que utiliza el nombre, la dirección la fecha en que comenzó a
     * trabajar en el comercio, su salario y el cargo o puesto que ocupa.</br>
     * El salario indicado debe ser mayor que 0, en caso contrario se tomará como salario 0.
     *
     * @param nombre      el nombre del empleado.
     * @param direccion   la dirección del empleado.
     * @param fechaInicio la fecha en que comenzó a trabajar en el comercio.
     * @param salario     el salario del empleado.
     * @param cargo       el cargo que ocupa el empleado.
     */
    public Empleado(String nombre, String direccion, String fechaInicio, double salario, String cargo) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.fechaInicio = fechaInicio;
        this.salario = salario > 0 ? salario : 0;
        this.cargo = cargo;
    }

    /**
     * Constructor de la clase Empleado que hace uso del constructor
     * {@link #Empleado(String, String, String, double, String) Empleado} (comprobar para más información)
     * para asignar un nombre, dirección, la fecha de inicio en el comercio, el salario y el cargo del
     * empleado, y además guarda su teléfono y correo electrónico.
     *
     * @param nombre      el nombre del empleado.
     * @param direccion   la dirección del empleado.
     * @param telefono    telefóno del empleado.
     * @param email       correo electrónico del empleado.
     * @param fechaInicio la fecha en que comenzó a trabajar en el comercio.
     * @param salario     el salario del empleado.
     * @param cargo       el cargo que ocupa el empleado.
     */
    public Empleado(String nombre, String direccion, int telefono, String email, String fechaInicio,
                    double salario, String cargo) {
        this(nombre, direccion, fechaInicio, salario, cargo);
        this.telefono = telefono;
        this.email = email;
    }


    /**
     * Obtener el nombre del empleado.
     *
     * @return el nombre del empleado.
     */
    public String getNombre() {
        return this.nombre;
    }

    /**
     * Asignar el nombre del empleado.
     *
     * @param nombre el nombre del empleado.
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * Obtener la dirección del empleado.
     *
     * @return la dirección del empleado.
     */
    public String getDireccion() {
        return this.direccion;
    }

    /**
     * Asignar la dirección del empleado.
     *
     * @param direccion la dirección del empleado.
     */
    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    /**
     * Obtener el teléfono del empleado.
     *
     * @return el teléfono del empleado.
     */
    public int getTelefono() {
        return this.telefono;
    }

    /**
     * Asignar el teléfono del empleado.
     *
     * @param telefono el teléfono del empleado.
     */
    public void setTelefono(int telefono) {
        this.telefono = telefono;
    }

    /**
     * Obtener el correo electrónico del empleado.
     *
     * @return el correo electrónico del empleado.
     */
    public String getEmail() {
        return this.email;
    }

    /**
     * Asignar el correo electrónico del empleado.
     *
     * @param email el correo electrónico del empleado.
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /**
     * Obtener la fecha en que el empleado comenzó a trabajar en el comercio.
     *
     * @return fecha de inicio.
     */
    public String getFechaInicio() {
        return this.fechaInicio;
    }

    /**
     * Asignar la fecha en que el empleado comenzó a trabajar en el comercio.
     *
     * @param fechaInicio fecha de inicio.
     */
    public void setFechaInicio(String fechaInicio) {
        this.fechaInicio = fechaInicio;
    }

    /**
     * Obtener el salario del empleado.
     *
     * @return salario del empleado.
     */
    public double getSalario() {
        return this.salario;
    }

    /**
     * Asignar el salario al empleado si es mayor que 0, si el valor indicado es menor o igual que 0, se
     * asigna 0 en su lugar.
     *
     * @param salario salario del empleado.
     */
    public void setSalario(double salario) {
        this.salario = salario > 0 ? salario : 0;
    }

    /**
     * Obtener el cargo del empleado en el comercio.
     *
     * @return cargo del empleado.
     */
    public String getCargo() {
        return this.cargo;
    }

    /**
     * Asignar el cargo del empleado en el comercio.
     *
     * @param cargo cargo del empleado.
     */
    public void setCargo(String cargo) {
        this.cargo = cargo;
    }


    /**
     * Construye una cadena indicando el nombre, la dirección, el teléfono, correo electrónico, fecha de
     * comienzo en el comercio, salario y puesto del empleado.
     *
     * @return cadena con la información del empleado.
     */
    @Override
    public String toString() {
        return this.nombre + " con dirección " + this.direccion + ", teléfono "
                + this.telefono + " y correo electrónico " + this.email
                + " comenzó a trabajar en la empresa en " + this.fechaInicio
                + " cobra un total de " + this.salario + "€ y ocupa el puesto"
                + " de " + this.cargo;
    }

    /**
     * Comprueba si el objeto (obj) que se le pasa al método es del tipo Empleado y, si lo es, compara el
     * nombre de obj con el nombre de este empleado para verificar si se trata de la misma persona.
     *
     * @param obj objeto a comprobar si es igual a este empleado.
     * @return booleano indicando si los empleados son o no iguales.
     */
    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() == this.getClass()) {
            return this.nombre.equals(((Empleado) obj).getNombre());
        }

        return false;
    }

    /**
     * Realiza una "deep-copy" de este empleado. En caso de fallo en su realización, el valor devuelto es
     * nulo.
     *
     * @return la copia de este empleado o null.
     */
    @Override
    public Empleado clone() {
        Empleado copia = null;

        try {
            // Serializar objeto
            ByteArrayOutputStream bos = new ByteArrayOutputStream();
            ObjectOutputStream out = new ObjectOutputStream(bos);
            out.writeObject(this);

            // Deserializar objeto y guardarlo en copia
            ByteArrayInputStream bis = new ByteArrayInputStream(bos.toByteArray());
            ObjectInputStream in = new ObjectInputStream(bis);
            copia = (Empleado) in.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e);
        }

        return copia;
    }
}
