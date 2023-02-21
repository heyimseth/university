package Lab2Project;

/**
 * Clase que define objetos de números complejos y permite operaciones de suma,
 * resta, producto de dos números complejos, y producto de un número complejo
 * por un escalar. También se define la comparación de dos números complejos.
 *
 * @author Álvaro Martínez Alfaro
 * @version 1.0, 02/16/2023
 */

public class NumComplejo {
    private double real;
    private double imaginaria;

    /**
     * Constructor para la clase NumComplejo. Asigna el valor 0 a la parte real
     * y a la imaginaria.
     */
    public NumComplejo() {
        this.real = 0;
        this.imaginaria = 0;
    }

    /**
     * Constructor para la clase NumComplejo. Utiliza parámetros enteros para
     * construir el objeto.
     * @param real          entero que corresponde a la parte real.
     * @param imaginaria    entero que corresponde a la parte imaginaria.
     */
    public NumComplejo(int real, int imaginaria) {
        this.real = real;
        this.imaginaria = imaginaria;
    }

    /**
     * Constructor para la clase NumComplejo. Utiliza parámetros dobles (reales)
     * para construir el objeto.
     * @param real          doble que corresponde a la parte real.
     * @param imaginaria    doble que corresponde a la parte imaginaria.
     */
    public NumComplejo(double real, double imaginaria) {
        this.real = real;
        this.imaginaria = imaginaria;
    }

    /**
     * Constructor para la clase NumComplejo. Copia la parte real e imaginaria
     * del número complejo pasado como parámetro.
     * @param complejo      objeto NumComplejo del que copiar los datos.
     */
    public NumComplejo(NumComplejo complejo) {
        this.real = complejo.real;
        this.imaginaria = complejo.real;
    }

    /* Métodos */

    /**
     * Obtener el valor de la parte real.
     * @return              parte real del número.
     */
    public double getReal() { return this.real; }

    /**
     * Obtener el valor de la parte imaginaria.
     * @return              parte imaginaria del número.
     */
    public double getImaginaria() { return this.imaginaria; }
    // Setters

    /**
     * Asigna el número real pasado como parámetro a la parte real del número
     * complejo..
     * @param real          número (double) a asignar a la parte real
     */
    public void setReal(double real) { this.real = real; }

    /**
     * Asigna el número real pasado como parámetro a la parte imaginaria del
     * número complejo.
     * @param imaginaria    número (double) a asignar a la parte imaginaria.
     */
    public void setImaginaria(double imaginaria) { this.imaginaria = imaginaria; }

    /**
     * Recibe dos números complejos y calcula la suma de ambos. Para ello,
     * suma, por un lado, la parte real de ambos números, y por otro, la parte
     * imaginaria.
     * @param num1          NumComplejo que se usará como primer sumando.
     * @param num2          NumComplejo que se usará como segundo sumando.
     * @return              NumComplejo resultado de la suma.
     */
    public static NumComplejo sumar(NumComplejo num1, NumComplejo num2) {
        NumComplejo resultado = new NumComplejo();

        resultado.real = num1.real + num2.real;
        resultado.imaginaria = num1.imaginaria + num2.imaginaria;

        return resultado;
    }

    /**
     * Recibe dos números complejos y calcula la resta de ambos. Para ello,
     * resta, por un lado, la parte real de ambos números, y por otro, la parte
     * imaginaria.
     * @param num1          NumComplejo usado como primer operando.
     * @param num2          NumComplejo usado como segundo operando.
     * @return              NumComplejo resultado de la resta.
     */
    public static NumComplejo restar(NumComplejo num1, NumComplejo num2) {
        NumComplejo resultado = new NumComplejo();

        resultado.real = num1.real - num2.real;
        resultado.imaginaria = num1.imaginaria - num2.imaginaria;

        return resultado;
    }

    /**
     * Recibe un número complejo y un escalar, y calcula el producto entre
     * ambos.
     * @param num1          NumComplejo a usar como operando.
     * @param escalar       número por el que multiplicar num1.
     * @return              NumComplejo con el resultado del producto.
     */
    public static NumComplejo multiplicar(NumComplejo num1, double escalar) {
        NumComplejo resultado = new NumComplejo();

        resultado.real = num1.real * escalar;
        resultado.imaginaria = num1.imaginaria * escalar;

        return resultado;
    }

    /**
     * Recibe dos números complejos y calcula el producto entre ambos.
     * @param num1          NumComplejo a usar como operando.
     * @param num2          NumComplejo a usar como segundo operando.
     * @return              NumComplejo con el resultado del producto.
     */
    public static NumComplejo multiplicar(NumComplejo num1, NumComplejo num2) {
        NumComplejo resultado = new NumComplejo();

        resultado.real = (num1.real * num2.real) - (num1.imaginaria * num2.imaginaria);
        resultado.imaginaria = (num1.real * num2.imaginaria) + (num1.imaginaria * num2.real);

        return resultado;
    }

    /**
     * Compara dos números complejos, comprobando si la parte real y la parte
     * imaginaria son iguales en ambos.
     * @param num1          NumComplejo a usar como operando.
     * @param num2          NumComplejo a usar como segundo operando.
     * @return              resultado de la comparación. true si ambos son
     *                          iguales y false en caso contrario.
     */
    public static boolean comparar(NumComplejo num1, NumComplejo num2) {
        return (num1.real == num2.real) && (num1.imaginaria == num2.imaginaria);
    }

    /**
     * Muestra el número complejo en un formato amigable.
     * @return              String con el número complejo en formato amigable,
     *                          "real + imaginaria(i)".
     */
    public String toString() {
        return Math.round(this.real * 100.0)/100.0 + " + " +
                Math.round(this.imaginaria * 100.0)/100.0 + "i";
    }
}
