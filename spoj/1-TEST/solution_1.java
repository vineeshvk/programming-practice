import java.util.Scanner;

class solution_1 {
    private static Scanner sc;

    public static void main(final String... a) {

        sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            final int val = sc.nextInt();
            if (val == 42)
                return;
            System.out.println(val);

        }
    }
}