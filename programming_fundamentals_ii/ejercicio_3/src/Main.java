import PaqViviendas.*;

public class Main {
    public static void main(String[] args) {
        Inmobiliaria inmobiliaria = new Inmobiliaria(3);
        Chalet chalet = new Chalet(95000, 2, 130, 200);
        Unifamiliar unifamiliar = new Unifamiliar(65000, 1, 120);
        CasaDeCampo casaDeCampo = new CasaDeCampo(255000, 2,130, 350, chalet);

        inmobiliaria.incluirVivienda(chalet);
        inmobiliaria.incluirVivienda(unifamiliar);
        inmobiliaria.incluirVivienda(casaDeCampo);
        System.out.println("Unifamiliares no chalets en la inmobiliaria: " +
                inmobiliaria.unifamiliaresNoChalets());
        int vivMayorImpuesto = 0;

        for (int i = 1; i < 3; i++) {
            if (inmobiliaria.getVivienda(i).impuesto() > inmobiliaria.getVivienda(vivMayorImpuesto).impuesto()) {
                vivMayorImpuesto = i;
            }
        }

        System.out.println("Vivienda con mayor impuesto en la Inmobiliaria: ");
        System.out.println(inmobiliaria.getVivienda(vivMayorImpuesto));
    }
}