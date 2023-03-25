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
        System.out.println(empleado2.getNombre());
        empleado2.setNombre("Pepe");
        System.out.println(empleado2.getNombre());

        System.out.println(empleado2.getDireccion());
        empleado2.setDireccion("Calle Mentirosa, 4");
        System.out.println(empleado2.getDireccion());

        System.out.println(empleado2.getTelefono());
        empleado2.setTelefono(123456789);
        System.out.println(empleado2.getTelefono());

        System.out.println(empleado2.getEmail());
        empleado2.setEmail("pepe@correo.es");
        System.out.println(empleado2.getEmail());

        System.out.println(empleado2.getFechaInicio());
        empleado2.setFechaInicio("25/03/2021");
        System.out.println(empleado2.getFechaInicio());

        System.out.println(empleado2.getSalario());
        empleado2.setSalario(1200);
        System.out.println(empleado2.getSalario());

        System.out.println(empleado2.getCargo());
        empleado2.setCargo("Programador junior");
        System.out.println(empleado2.getCargo());

        System.out.println(empleado2);

        System.out.println(empleado2.equals(empleado1));
        empleado1 = empleado2.clone();
        System.out.print("Empleado igual a clonado:" + empleado2.equals(empleado1));


        /*#################################### VehículoParaReparar #########################################*/
        VehiculoParaReparar reparar1 = new VehiculoParaReparar(
                "Peugeout", "C206", "1234-ANT",
                "Rueda pinchada", 2
        );

        VehiculoParaReparar reparar2 = new VehiculoParaReparar(
                "Opel", "Crossland X", "4321-TNA",
                "Cambio de aceite", 1
        );

        System.out.println(reparar1.getMarca());
        reparar1.setMarca("Nueva marca");
        System.out.println(reparar1.getMarca());

        System.out.println(reparar1.getModelo());
        reparar1.setModelo("Nuevo modelo");
        System.out.println(reparar1.getModelo());

        System.out.println(reparar1.getMatricula());
        reparar1.setMatricula("Nueva matrícula");
        System.out.println(reparar1.getMatricula());

        System.out.println(reparar1.getAveria());
        reparar1.setAveria("Está roto");
        System.out.println(reparar1.getAveria());

        System.out.println(reparar1.isReparado());
        reparar1.setReparado(true);
        System.out.println(reparar1.isReparado());

        System.out.println(reparar1.getPrioridad());
        reparar1.setPrioridad(3);
        System.out.println(reparar1.getPrioridad());
        reparar1.setPrioridad(6);
        System.out.println(reparar1.getPrioridad());

        System.out.println(reparar1);

        System.out.println(reparar2.equals(reparar1));
        VehiculoParaReparar reparar3 = reparar2.clone();
        System.out.println(reparar2.equals(reparar3));


        /*####################################### VehiculoVenta ############################################*/
        VehiculoVenta venta1 = new VehiculoVenta(
                "Ferrari", "Veloz", "5678-XPSV",
                1234567, 1
        );

        VehiculoVenta venta2 = new VehiculoVenta(
                "Lamborghini", "Carísimo", "9812-PFF",
                123456789, 0
        );

        System.out.println(venta1.getPrecio());
        venta1.setPrecio(5612345);
        System.out.println(venta1.getPrecio());

        System.out.println(venta1.getDescuento());
        venta1.setDescuento(2);
        System.out.println(venta1.getDescuento());

        System.out.println(venta1);

        VehiculoVenta venta3 = venta2.clone();

        /*                            Testeo de clases Concesionario y Restaurante                          */
        /*######################################## Restaurante #############################################*/

    }
}
