package Lab2Project;

public class Main {
    public static void main(String[] args) {
        NumComplejo operando1 = new NumComplejo(7.8, 1.5);
        NumComplejo operando2 = new NumComplejo(9, 4);
        NumComplejo resultado;

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
        System.out.println("\nMultiplicación complejos: (" + operando1.toString() +
                ") * (" + operando2.toString() + ") = " + resultado.toString());
    }
}