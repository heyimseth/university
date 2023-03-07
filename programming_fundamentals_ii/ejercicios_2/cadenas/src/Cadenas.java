public class Cadenas {
    /* Ejercicio 1 */
    public static String encontrarPalabraMayor(String cadena) {
        String mayor = "";

        for (String palabra: cadena.split(" ")) {
            if (palabra.length() > mayor.length()) {
                mayor = palabra;
            }
        }

        return mayor;
    }

    /* Ejercicio 2*/
    public static StringBuffer intercalarCadenas(String c1, String c2) {
        StringBuffer cIntercalada = new StringBuffer();
        int lng = c2.length();

        if (c1.length() < c2.length()) {
            lng = c1.length();
        }

        for (int i = 0; i < lng; i++) {
            cIntercalada.append(c1.charAt(i));
            cIntercalada.append(c2.charAt(i));
        }

        if (lng == c1.length()) {
            cIntercalada.append(c2.substring(lng));
        } else {
            cIntercalada.append(c1.substring(lng));
        }

        return cIntercalada;
    }

    /* Ejercicio 3 */
    public static void letrasNoEncontradas(String cadena) {
        for (int i = 'a'; i <= 'z'; i++) {
            if (cadena.toLowerCase().indexOf((char) i) == -1) {
                System.out.print((char) i + " ");
            }
        }
    }

    /* Ejercicio 4 */
    public static StringBuffer codificar(String cadena) {
        StringBuffer codificada = new StringBuffer();

        return codificada;
    }
}
