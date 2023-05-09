public class Mascota {
     protected String nombre;

    public Mascota(String nombre) {
        this.nombre = nombre;
    }

    public void mostrarMascota() {
        System.out.println("Soy la mascota " + this.nombre);
    }
}
