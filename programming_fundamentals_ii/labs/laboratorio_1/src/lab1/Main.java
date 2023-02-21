package lab1;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NumeroNatural numero1 = new NumeroNatural();
        int exp;

        System.out.print("Indica un número natural: ");
        numero1.setNumero(sc.nextInt());
        System.out.println("El número almacenado es " + numero1.getNumero());

        numero1.incrementar();
        System.out.println("El número tras incrementar es " +
                numero1.getNumero());

        numero1.decrementar();
        System.out.println("El número tras decrementar es " +
                numero1.getNumero());

        if ( numero1.esPar() ) {
            System.out.println("El número " + numero1.getNumero() + " es par.");
        } else {
            System.out.println("El número " + numero1.getNumero() + " es impar.");
        }

        if ( numero1.esPrimo() ) {
            System.out.println("El número " + numero1.getNumero() + " es primo.");
        } else {
            System.out.println("El número " + numero1.getNumero() + " no es primo.");
        }

        if ( numero1.esPerfecto() ) {
            System.out.println("El número " + numero1.getNumero() + " es perfecto.");
        } else {
            System.out.println("El número " + numero1.getNumero() + " no es perfecto.");
        }

        System.out.print("Indica exponente: ");
        exp = sc.nextInt();
        System.out.println("El resultado de " + numero1.getNumero() + "^" +
                exp + " = " + numero1.pow(exp));

        System.out.println("El resultado de " + numero1.getNumero() + "/2 = " +
                numero1.half());

        NumeroNatural numero2 = new NumeroNatural();
        numero2.setNumero(16);
        NumeroNatural numero3 = numero1.distancia(numero2);
        System.out.println("|" + numero1.getNumero() + " - " + numero2.getNumero() +
                "| = " + numero3.getNumero());

        numero1.syncToMinor(numero2);
        System.out.println("Resultado tras sincronizar al menor: " +
                numero1.getNumero() + " " + numero2.getNumero());
    }
}