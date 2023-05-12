public class Propietario {

    private int dni;

    public Propietario(int dni) {
        this.dni = dni;
    }



    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }


    // Modificaciones propias
    @Override
    public boolean equals(Object propietario) {
        if (propietario instanceof Propietario) {
            if (this.dni == ((Propietario) propietario).getDni()) {
                return true;
            }
        }

        return false;
    }
}
