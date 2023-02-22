package Lab2Project;

public class Main {
    public static void main(String[] args) {
        NumComplejo operando1 = new NumComplejo(3.5, 2.86);
        NumComplejo operando2 = new NumComplejo(2.4, 5.3);
        NumComplejo resultado;
        VariosNumComplejos numeros = new VariosNumComplejos(10);
        Escalar escalar = new Escalar(2.5);

        System.out.println("Número complejo 1: " + operando1.toString());
        System.out.println("Número complejo 2: " + operando2.toString());

        resultado = NumComplejo.sumar(operando1, operando2);
        System.out.println("\nSuma: (" + operando1.toString() + ") + (" +
                operando2.toString() + ") = " + resultado.toString());

        resultado = NumComplejo.restar(operando1, operando2);
        System.out.println("\nResta: (" + operando1.toString() + ") - (" +
                operando2.toString() + ") = " + resultado.toString());

        resultado = NumComplejo.multiplicar(operando1, 7.3);
        System.out.println("\nMultiplicación por escalar: (" +
                operando1.toString() + ") * " + 7.3 + " = " +
                resultado.toString());

        resultado = NumComplejo.multiplicar(operando1, operando2);
        System.out.println("\nMultiplicación complejos: (" +
                operando1.toString() + ") * (" + operando2.toString() + ") = "
                + resultado.toString());

        System.out.println("Números generados aleatoriamente:\n" +
                numeros.toString());

        System.out.println("La suma de todos estos números es: " +
                numeros.sumaTodos());

        numeros.setComplejo(3,4,7.32);
        System.out.println("Setter sobre el número en posición 3 con parte real"
                + " 4 y parte imaginaria 7.32: " + numeros.getComplejo(3));

        System.out.println("Multiplicación con clase Escalar de (" +
                operando1.toString() + ") * " + escalar.getEscalar() + " = " +
                NumComplejo.multiplicar(operando1, escalar).toString());
    }
}