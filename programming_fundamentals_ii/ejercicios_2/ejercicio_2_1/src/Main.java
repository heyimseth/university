public class Main {
    public static void main(String[] args) {
        Persona p = new Persona();

        p.setNombre("Luis");
        p.setNombreDePila("Luisito");
        p.setApellido("Ruiz");
        p.setEdad(27);
        p.setTelefono(912234513);
        p.setaNacimiento(1990);

        System.out.println("Nombre: " + p.getNombre() + ".\nNombre de pila: " + p.getNombreDePila()
                + ".\nApellido: " + p.getApellido() + ".\nEdad: " + p.getEdad() + ".\nTeléfono: "
                + p.getTelefono() + ".\nAño de nacimiento: " + p.getaNacimiento());

        System.out.println(p.mostrar());

        p.constructName();
        System.out.println("Nombre: " + p.getNombre());
    }
}