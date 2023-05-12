import java.util.Random;

public class Edificio extends Vivienda{
     Propietario [][] ed;
     Propietario presidente;

     public Edificio() {
          Random r = new Random();
          ed = new Propietario[10][5];
          for (int i = 0; i < 20; i++) {
               int f = r.nextInt(10);
               int c = r.nextInt(5);
               if (ed[f][c] == null) ed[f][c] = new Propietario(100000+i);
               else i--;
          }
     }
}
