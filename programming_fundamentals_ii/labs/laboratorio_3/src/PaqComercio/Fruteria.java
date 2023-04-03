package PaqComercio;

public class Fruteria extends Comercio {


    public Fruteria(String nombre, String direccion, String cif, Empleado empleado) {
        super(nombre, direccion, cif, empleado);
    }

    @Override
    public String toStringStock() {
        return null;
    }
}
