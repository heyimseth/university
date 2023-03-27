package Trabajadores;

public class Abogado extends Empleado {
    @Override
    public int getHoras() {
        return super.getHoras() + 5;
    }

    @Override
    public double getSalario() {
        return super.getSalario() + 10000;
    }

    @Override
    public int getVacaciones() {
        return super.getVacaciones() / 2;
    }

    @Override
    public String getMesVacaciones() {
        return "Julio";
    }

    public String getEstado() {
        return "Estoy en el tribunal.";
    }
}
