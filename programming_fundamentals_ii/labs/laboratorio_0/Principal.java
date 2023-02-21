package DEBUG;

import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {

        perfectos(3, 30);
        Scanner S = new Scanner(System.in);
        System.out.println(("\nDame a"));
        int n1 = S.nextInt();
        System.out.println(("\nDame b"));
        int n2 = S.nextInt();
        perfectos(n1, n2);


    }


    static boolean esPerfecto(int N) {
        int sum = 0;
        for (int i = 1; i < N; i++)
            if (N % i == 0) sum = sum + i;
        return sum == N;

    }

    static void perfectos(int a, int b) {
        for (int i = a; i <= b; i++) {
            if (esPerfecto(i)) System.out.print(i + " ");
        }

    }
}

