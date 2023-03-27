package Trabajadores;

public class Conserje extends Empleado {
    @Override
    public int getVacaciones() {
        return super.getVacaciones() + 5;
    }

    @Override
    public String getMesVacaciones() {
        return "Septiembre";
    }
}
