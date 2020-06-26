import java.util.Scanner;

public class solution_42 {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int revX = revNumber(x);
            int revY = revNumber(y);
            System.out.println(revNumber(revX + revY));
        }
    }

    public static int revNumber(int num) {
        int rev = 0;
        while (num != 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }

        return rev;
    }
}