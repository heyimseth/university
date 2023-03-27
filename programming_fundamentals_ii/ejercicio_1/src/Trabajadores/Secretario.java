package Trabajadores;

public class Secretario extends Empleado {
    @Override
    public double getSalario() {
        return super.getSalario() + 5000;
    }

    public String getEstado() {
        return "Estoy haciendo fotocopias.";
    }
}
