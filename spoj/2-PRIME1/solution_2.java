import java.util.Scanner;

public class solution_2 {
    public static void main(String[] a) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            prime(start, end);
            System.out.println();
        }
        sc.close();
    }

    public static void prime(int start, int end) {
        for (int i = start; i <= end; i++) {
            int n = 2;
            boolean prime = i != 1;

            while (n * n <= i && prime) {
                prime = i % n != 0;
                n++;
            }

            if (prime)
                System.out.println(i);
        }
    }
}