package PaqPruebas;

import PaqComercio.*;

public class Main {
    public static void main(String[] args) throws CloneNotSupportedException {
        /*                   Testeo de clases Empleado, VehículoParaReparar y VehículoVenta                 */
        /*######################################### Empleado ###############################################*/
        Empleado empleado1 = new Empleado(
                "Álvaro", "Calle Inventada, 3", "26/03/2015",
                2300.3, "Programador"
        );

        Empleado empleado2 = new Empleado(
                "Pablo", "Calle Ficticia, 29", 613151413,
                "pablo@correo.es", "12/01/2020", 2150.15,
                "Programador"
        );

        System.out.println("\tPruebas de la clase Empleado\n");
        System.out.println("Nombre: " + empleado1.getNombre());
        empleado1.setNombre("Pepe");
        System.out.println("Nombre: " + empleado1.getNombre());

        System.out.println("Dirección: " + empleado1.getDireccion());
        empleado1.setDireccion("Calle Mentirosa, 4");
        System.out.println("Dirección: " + empleado1.getDireccion());

        System.out.println("Teléfono: " + empleado1.getTelefono());
        empleado1.setTelefono(123456789);
        System.out.println("Teléfono: " + empleado1.getTelefono());

        System.out.println("Email: " + empleado1.getEmail());
        empleado1.setEmail("pepe@correo.es");
        System.out.println("Email: " + empleado1.getEmail());

        System.out.println("Fecha inicio: " + empleado1.getFechaInicio());
        empleado1.setFechaInicio("25/03/2021");
        System.out.println("Fecha inicio: " + empleado1.getFechaInicio());

        System.out.println("Salario: " + empleado1.getSalario());
        empleado1.setSalario(1200);
        System.out.println("Salario: " + empleado1.getSalario());

        System.out.println("Cargo: " + empleado1.getCargo());
        empleado1.setCargo("Programador junior");
        System.out.println("Cargo: " + empleado1.getCargo());

        System.out.println(empleado1);

        empleado1 = empleado2.clone();
        System.out.println("Empleado1 == clonado: " + (empleado2 == empleado1));
        System.out.print("Empleado1.equals(clonado): " + empleado2.equals(empleado1));



        /*#################################### VehículoParaReparar #########################################*/
        VehiculoParaReparar reparar1 = new VehiculoParaReparar(
                "Peugeout", "C206", "1234-ANT",
                "Rueda pinchada", 2
        );

        VehiculoParaReparar reparar2 = new VehiculoParaReparar(
                "Opel", "Crossland X", "4321-TNA",
                "Cambio de aceite", 1
        );

        System.out.println("\n\n\tPruebas de la clase VehiculoParaReparar\n");
        System.out.println("Marca: " + reparar1.getMarca());
        reparar1.setMarca("Nueva marca");
        System.out.println("Marca: " + reparar1.getMarca());

        System.out.println("Modelo: " + reparar1.getModelo());
        reparar1.setModelo("Nuevo modelo");
        System.out.println("Modelo: " + reparar1.getModelo());

        System.out.println("Matrícula: " + reparar1.getMatricula());
        reparar1.setMatricula("Nueva matrícula");
        System.out.println("Matrícula: " + reparar1.getMatricula());

        System.out.println("Avería: " + reparar1.getAveria());
        reparar1.setAveria("Está roto");
        System.out.println("Avería: " + reparar1.getAveria());

        System.out.println("Reparado: " + reparar1.isReparado());
        reparar1.setReparado(true);
        System.out.println("Reparado: " + reparar1.isReparado());

        System.out.println("Prioridad: " + reparar1.getPrioridad());
        reparar1.setPrioridad(3);
        System.out.println("Prioridad: " + reparar1.getPrioridad());

        System.out.println(reparar1);

        VehiculoParaReparar reparar3 = reparar2.clone();
        System.out.println("Reparar2 == clonado: " + (reparar3 == reparar2));
        System.out.println("Reparar2.equals(clonado): " + reparar2.equals(reparar3));
        System.out.println("Reparar2.getMarca() == clonado.getMarca(): " +
                (reparar2.getMarca() == reparar3.getMarca()));



        /*####################################### VehiculoVenta ############################################*/
        VehiculoVenta venta1 = new VehiculoVenta(
                "Ferrari", "Veloz", "5678-XPSV",
                1234567, 1
        );

        VehiculoVenta venta2 = new VehiculoVenta(
                "Lamborghini", "Carísimo", "9812-PFF",
                123456789, 0
        );

        System.out.println("\n\n\tPruebas de la clase VehiculoParaReparar\n");
        System.out.println("Precio: " + venta1.getPrecio());
        venta1.setPrecio(5612345);
        System.out.println("Precio: " + venta1.getPrecio());

        System.out.println("Descuento: " + venta1.getDescuento());
        venta1.setDescuento(2);
        System.out.println("Descuento: " + venta1.getDescuento());

        System.out.println(venta1);

        VehiculoVenta venta3 = venta2.clone();
        System.out.println("Venta2 == clonado: " + (venta2 == venta3));
        System.out.println("Venta2.equals(clonado): " + venta2.equals(venta3));



        /*                            Testeo de clases Concesionario y Restaurante                          */
        /*######################################## Restaurante #############################################*/
        Restaurante restaurante1 = new Restaurante(
                "Bar Pepe", "Calle Inexistente, 3", "12345678S",
                empleado1, 16, 16*4
        );

        System.out.println("\n\n\tPruebas de la clase Restaurante\n");
        System.out.println("Nombre: " + restaurante1.getNombre());
        restaurante1.setNombre("Bar José");
        System.out.println("Nombre: " + restaurante1.getNombre());

        System.out.println("Dirección: " + restaurante1.getDireccion());
        restaurante1.setDireccion("Calle Existente, 7");
        System.out.println("Dirección: " + restaurante1.getDireccion());

        System.out.println("CIF: " + restaurante1.getCif());
        restaurante1.setCif("92317234P");
        System.out.println("CIF: " + restaurante1.getCif());

        System.out.println("Número de mesas: " + restaurante1.getNumMesas());
        restaurante1.setNumMesas(25);
        System.out.println("Número de mesas: " + restaurante1.getNumMesas());

        System.out.println("Capacidad: " + restaurante1.getCapacidad());
        restaurante1.setCapacidad(25*4);
        System.out.println("Capacidad: " + restaurante1.getCapacidad());

        System.out.println(restaurante1);

        restaurante1.fijarMenuDia("Tortilla de patatas", 1);
        restaurante1.fijarMenuDia("Lentejas", 2);
        restaurante1.fijarMenuDia("Patatas con huevo", 3);
        restaurante1.fijarMenuDia("Paella", 4);
        restaurante1.fijarMenuDia("Gazpacho manchego", 5);
        restaurante1.fijarMenuDia("Gazpacho andaluz", 6);
        restaurante1.fijarMenuDia("Migas", 7);
        System.out.println(restaurante1.verMenuDia(3));
        System.out.println(restaurante1.toStringStock());

        Restaurante restaurante2 = restaurante1.clone();
        System.out.println("Restaurante1 == clonado: " + (restaurante1 == restaurante2));



        /*####################################### Concesionario ############################################*/
        Concesionario concesionario1 = new Concesionario(
                "Coches Lucas", "P.I. Campollano, Calle C, 3", "81726745C",
                empleado2, venta2
        );

        System.out.println("\n\n\tPruebas de la clase Concesionario\n");
        System.out.println("Vehículo a la venta: " + concesionario1.getVehiculoVenta(venta2.getMatricula()));

        System.out.println("Vehículo para reparar: " +
                concesionario1.getVehiculoParaReparar(reparar2.getMatricula())
        );
        concesionario1.addReparar(reparar2);
        System.out.println("Vehículo para reparar: " +
                concesionario1.getVehiculoParaReparar(reparar2.getMatricula())
        );

        System.out.println(concesionario1.toStringVehiculosVenta());
        concesionario1.addVenta(venta1);
        System.out.println(concesionario1.toStringVehiculosVenta());

        System.out.println(concesionario1.toStringVehiculosReparar());
        concesionario1.addReparar(reparar1);
        System.out.println(concesionario1.toStringVehiculosReparar());

        System.out.println(concesionario1.toStringVehiculosVenta());
        concesionario1.venderVehiculo(0);
        System.out.println(concesionario1.toStringVehiculosVenta());

        System.out.println(concesionario1.toStringVehiculosReparar());
        concesionario1.recogerVehiculo(reparar1.getMatricula());
        System.out.println(concesionario1.toStringVehiculosReparar());

        System.out.println(concesionario1.toStringVehiculosReparar());
        concesionario1.repararVehiculo(0);
        System.out.println(concesionario1.toStringVehiculosReparar());

        System.out.println(concesionario1.toStringStock());

        Concesionario concesionario2 = concesionario1.clone();
        System.out.println("Concesionario1 == clonado: " + (concesionario1 == concesionario2));
    }
}
