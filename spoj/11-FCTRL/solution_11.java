import java.util.Scanner;

public class solution_11 {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            System.out.println(trailingZeros(num));
        }
    }

    private static int trailingZeros(int num) {
        int zeros = 0;
        while (num >= 5) {
            num /= 5;
            zeros += num;
        }

        return zeros;
    }
}