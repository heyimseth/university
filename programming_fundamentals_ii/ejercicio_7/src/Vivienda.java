import java.util.Random;

public abstract class Vivienda {
    int numCatastro;
    private int metros;
    private Propietario propietario;



    public Vivienda()   {
        Random r = new Random();
        this.numCatastro = r.nextInt(1000000, 9999999);
    }
    public int getMetros() {
        return metros;
    }

    public void setMetros(int metros) {
        this.metros = metros;
    }

    public Propietario getPropietario() {
        return propietario;
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = propietario;
    }
}
