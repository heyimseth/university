package PaqComercio;

public class Empleado {
    private String nombre;
    private String direccion;
    private int telefono;
    private String email;
    private String fechaInicio;
    private double salario;
    private String cargo;



    /*########################### Constructores ##############################*/
    public Empleado(String nombre, String direccion, String fechaInicio,
                    double salario, String cargo) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.fechaInicio = fechaInicio;
        this.salario = salario;
        this.cargo = cargo;
    }

    public Empleado(String nombre, String direccion, int telefono, String email,
                    String fechaInicio, double salario, String cargo) {
        this(nombre, direccion, fechaInicio, salario, cargo);
        this.telefono = telefono;
        this.email = email;
    }
    /*########################################################################*/



    /*######################### Getters y Setters ############################*/
    public String getNombre() { return this.nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }

    public String getDireccion() { return this.direccion; }
    public void setDireccion(String direccion) { this.direccion = direccion; }

    public int getTelefono() { return this.telefono; }
    public void setTelefono(int telefono) { this.telefono = telefono; }

    public String getEmail() { return this.email; }
    public void setEmail(String email) { this.email = email; }

    public String getFechaInicio() { return this.fechaInicio; }
    public void setFechaInicio(String fechaInicio) {
        this.fechaInicio = fechaInicio;
    }

    public double getSalario() { return this.salario; }
    public void setSalario(double salario) { this.salario = salario; }

    public String getCargo() { return this.cargo; }
    public void setCargo(String cargo) { this.cargo = cargo; }
    /*########################################################################*/



    /*########################### Otros métodos ##############################*/
    @Override
    public String toString() {
        return this.nombre + " con dirección " + this.direccion + ", teléfono "
                + this.telefono + " y correo electrónico " + this.email
                + " comenzó a trabajar en la empresa en " + this.fechaInicio
                + " cobra un total de " + this.salario + "€ y ocupa el puesto"
                + " de " + this.cargo;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() == this.getClass()) {
            return this.nombre.equals(((Empleado) obj).getNombre());
        }

        return false;
    }

    @Override
    public Empleado clone() {
        return new Empleado(this.nombre, this.direccion, this.telefono,
                this.email, this.fechaInicio, this.salario, this.cargo);
    }
    /*########################################################################*/
}
