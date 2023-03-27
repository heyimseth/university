import Trabajadores.*;

public class Main {
    public static void main(String[] args) {
        Empleado[] empleados = {
                new Abogado(), new Conserje(), new Empleado(), new Secretario(),
                new Conserje(), new Secretario(), new Abogado(), new Abogado(),
                new Empleado(), new Secretario()
        };

        for (int i = 0; i < empleados.length; i++) {
            System.out.print("Empleado tipo " + empleados[i].getClass() + " tiene un salario de " +
                    empleados[i].getSalario() + ", trabaja un total de " + empleados[i].getHoras() +
                    " horas por semana, tiene " + empleados[i].getVacaciones() + " días de vacaciones al " +
                    "año y su mes de vacaciones es " + empleados[i].getMesVacaciones() + ". ");
            if (empleados[i].getClass() == Abogado.class) {
                System.out.print(((Abogado) empleados[i]).getEstado());
            } else if (empleados[i].getClass() == Secretario.class) {
                System.out.print(((Secretario) empleados[i]).getEstado());
            }

            System.out.println();
        }
    }
}