package PaqPruebas;

import PaqComercio.*;

import java.time.LocalDateTime;

public class Main {
    public static void main(String[] args) throws CloneNotSupportedException {
        // Pruebas concesionario
        System.out.println("#####################");
        System.out.println("Pruebas concesionario");
        System.out.println("#####################");
        System.out.println("\nNuevo concesionario:");
        Concesionario concesionario = new Concesionario("Opel", "Calle Inventada, 32",
                "72810956D", new Empleado("Pepe", "Calle Nueva, 12", 671829312,
                "pepe@correo.es", "12/09/2015", 2561, "Jefazo"),
                new VehiculoVenta("Opel", "Crossland X", "1234-KGB", 17500,
                        3));
        System.out.println(concesionario.toStringVehiculosVenta());
        System.out.println(concesionario.toStringStock());

        System.out.println("\nAñadir vehículo a la venta:");
        concesionario.addVenta(new VehiculoVenta("Citroen", "C4", "6789-TPO",
                14960, 5));
        System.out.println(concesionario.toStringVehiculosVenta());
        System.out.println(concesionario.toStringStock());

        System.out.println("\nAñadir vehículo a reparar:");
        concesionario.addReparar(new VehiculoParaReparar("Peugeot", "C206", "4321-PIT",
                "Rueda pinchada", 2));
        System.out.println(concesionario.toStringVehiculosReparar());
        System.out.println("\nAñadir otro vehículo a reparar:");
        concesionario.addReparar(new VehiculoParaReparar("Citroen", "C3", "4567-CTR",
                "Golpe frontal", 1));
        System.out.println(concesionario.toStringVehiculosReparar());
        System.out.println("Recoger vehículo no reparado:" +
                concesionario.recogerVehiculo("4321-PIT"));
        concesionario.repararVehiculo(1);
        System.out.println("Recoger vehículo reparado: " + concesionario.recogerVehiculo("4321-PIT"));
        System.out.println(concesionario.toStringVehiculosReparar());

        System.out.println("Vender vehículo con matrícula 1234-KGB:");
        System.out.println("Vendido: " + concesionario.venderVehiculo(0).toString());
        System.out.println(concesionario.toStringVehiculosVenta());
        System.out.println("Mes con más ventas: " + concesionario.mesConMasVentas());
        System.out.println("Ventas del mes actual: " +
                concesionario.calcularVentasMes(LocalDateTime.now().getMonthValue()));
        System.out.println("Total ventas: " + concesionario.calcularTotalVentas());
        System.out.println("Ventas diarias: \n" + concesionario.toStringVentasDiarias());
        Concesionario concClonado = concesionario.clone();
        System.out.println("Nombre concesionario original: " + concesionario.getNombre());
        System.out.println("Nombre concesionario clonado: " + concClonado.getNombre());
        concClonado.setNombre("Otro nombre");
        System.out.println("Nombre concesionario original: " + concesionario.getNombre());
        System.out.println("Nombre concesionario clonado (ahora cambiado): " + concClonado.getNombre());


        // Pruebas empleado
        System.out.println("#####################");
        System.out.println("Pruebas Empleado");
        System.out.println("#####################");
        System.out.println("\nNuevo empleado:");
        Empleado empleado = new Empleado("Juan", "Calle Inventada, 3", "18/03/2020",
                3200, "Programador");
        System.out.println(empleado.toString());
        System.out.println("Comprobar si un empleado es igual a otro (iguales): " + empleado.equals(
                new Empleado("Juan", "Calle Inventada, 3", "18/03/2020", 3200,
                        "Programador")));
        System.out.println("Comprobar si un empleado es igual a otro (distintos): " + empleado.equals(
                new Empleado("Jorge", "Calle Programación, 7", "18/10/2013",
                        2100, "Técnico")
        ));
    }
}
