import org.w3c.dom.ls.LSOutput;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String cadena1, palabra1, cadena2, palabra2;

        System.out.print("Indica una frase: ");
        cadena1 = sc.nextLine();
        System.out.print("Indica otra frase: ");
        cadena2 = sc.nextLine();


        System.out.println("\nPrimera cadena introducida: '" + cadena1 + "'.");
        palabra1 = Cadenas.encontrarPalabraMayor(cadena1);
        System.out.println("La palabra de mayor longitud es: '" + palabra1 + "' con " + palabra1.length() +
                " caracteres.");

        System.out.println("\nSegunda cadena introducida: '" + cadena2 + "'.");
        palabra2 = Cadenas.encontrarPalabraMayor(cadena2);
        System.out.println("La palabra de mayor longitud es: '" + palabra2 + "' con " + palabra2.length() +
                " caracteres.");

        System.out.println("\nLa cadena resultado de intercalar ambas cadenas es: '" +
                Cadenas.intercalarCadenas(cadena1, cadena2) + "'.");

        System.out.print("\nLas letras que no han aparecido en '" + cadena1 + "' han sido: ");
        Cadenas.letrasNoEncontradas(cadena1);

        System.out.print("\nLas letras que no han aparecido en '" + cadena2 + "' han sido: ");
        Cadenas.letrasNoEncontradas(cadena2);

        System.out.println("\n\nLa cadena '" + cadena1 + "' codificada es: '" + Cadenas.codificar(cadena1) +
                "'.");
    }
}