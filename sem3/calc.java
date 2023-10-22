import java.util.Scanner;

public class calc {

    static float num1, num2, total = 0;
    static boolean first = true;

    public static void main(String[] args) {
        clearScreen();

        Scanner scanner = new Scanner(System.in);

        int operator;

        System.out.println("  Calculator  ");
        System.out.println("===============");
        System.out.printf("Total = %.1f\n", total);

        if (first) {
            System.out.print("\nInput Number : ");
            num1 = scanner.nextFloat();
            total = num1;
        }

        System.out.println("\n[1] Addition");
        System.out.println("[2] Subtraction");
        System.out.println("[3] Multiplication");
        System.out.println("[4] Division");
        System.out.println("[5] Modulo");
        System.out.println("[6] Clear Total");
        System.out.println("[7] Exit");

        System.out.print("\nOperator : ");
        operator = scanner.nextInt();

        if (operator == 6) {
            total = 0;
            main(null);
        }
        if (operator == 7) {
            clearScreen();
            System.exit(1);
        }

        System.out.print("\nInput Number : ");
        num2 = scanner.nextFloat();

        first = false;

        calculate(operator);

        scanner.close();
    }

    public static void calculate(int operator) {
        switch (operator) {
            case 1:
                total += num2;
                break;
            case 2:
                total -= num2;
                break;
            case 3:
                total *= num2;
                break;
            case 4:
                total /= num2;
                break;
            case 5:
                total = (int) total % (int) num2;
                break;
        }
        main(null);
    }

    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
