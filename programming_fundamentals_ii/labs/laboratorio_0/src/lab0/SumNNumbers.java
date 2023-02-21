package lab0;

public class SumNNumbers {
    static int sum1(int n) {
        int sum = 0;

        for ( int i = 0; i <= n; i++ ) {
            sum = sum + i;
        }

        return sum;
    }

    static int sum2(int n) {
        return (n*(n+1))/2;
    }

    public static void main(String[] args) {
        int salida1, salida2;
        int[] array = {3,4,13,21,67,102,155,365,1007};

        for ( int i = 0; i < 46340; i++ ) {
            salida1 = sum1(i);
            salida2 = sum2(i);
            if ( salida1 != salida2 ) {
                System.out.println("[ERROR] Salidas distintas para " + i + "." +
                        " Sum1: " + salida1 + ". Sum2: " + salida2);
                System.out.println("---------------------------");
            }
        }
    }
}