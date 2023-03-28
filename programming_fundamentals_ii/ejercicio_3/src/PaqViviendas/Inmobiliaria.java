package PaqViviendas;

public class Inmobiliaria {
    private Vivienda[] viviendas;

    public Inmobiliaria(int n) {
        this.viviendas = new Vivienda[n];
    }

    public Vivienda getVivienda(int n) {
        return this.viviendas[n];
    }

    public void incluirVivienda(Vivienda vivienda) {
        boolean incluida = false;

        if (vivienda != null) {
            for (int i = 0; i < this.viviendas.length && !incluida; i++) {
                if (this.viviendas[i] == null) {
                    this.viviendas[i] = vivienda;
                    incluida = true;
                }
            }
        }
    }

    public int unifamiliaresNoChalets() {
        int total = 0;

        for (int i = 0; i < this.viviendas.length; i++) {
            if (this.viviendas[i].getClass() != Chalet.class) {
                total++;
            }
        }

        return total;
    }
}
