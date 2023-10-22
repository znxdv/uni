import java.util.Scanner;
import java.util.ArrayList;

public class GSLCs4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> names = new ArrayList<>();
        ArrayList<String> passs = new ArrayList<>();
        ArrayList<Long> phones = new ArrayList<>();
        
        clearConsole();
        
        int choice;
        do {
            displayMenu();
            System.out.print("\nYour choice : ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    clearConsole();
                    inputData(scanner, names, passs, phones);
                    break;
                case 2:
                    clearConsole();
                    showData(names, passs, phones);
                    break;
                case 3:
                    clearConsole();
                    deleteData(scanner, names, passs, phones);
                    break;
                case 4:
                    clearConsole();
                    System.out.println("Thank you for using this program.");
                    break;
                default:
                    clearConsole();
                    System.out.println("Invalid choice.");
            }
        } while (choice != 4);

        scanner.close();
    }

    public static void clearConsole() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static void displayMenu() {
        System.out.println("[1] Input Data");
        System.out.println("[2] Show Data");
        System.out.println("[3] Delete Data");
        System.out.println("[4] Exit");
    }

    public static void inputData(Scanner scanner, ArrayList<String> names, ArrayList<String> passs, ArrayList<Long> phones) {
        System.out.print("Name: ");
        String name = scanner.nextLine();
        System.out.print("Pass: ");
        String pass = scanner.nextLine();
        System.out.print("Phone: ");
        long phone = scanner.nextLong();
        scanner.nextLine();

        names.add(name);
        passs.add(pass);
        phones.add(phone);
		System.out.println("\nNew data is added\n\n");

    }

    public static void showData(ArrayList<String> names, ArrayList<String> passs, ArrayList<Long> phones) {
        System.out.println("==========================================================");
        System.out.println("  No            Name             Pass             Phone");
        System.out.println("==========================================================");
        System.out.println(" ");

        if (names.isEmpty()) {
            System.out.println("                        NO DATA EXIST.           ");
        } else {
            for (int i = 0; i < names.size(); i++) {
                String space = String.format("%3d %16s %16s %16d", (i + 1), names.get(i), passs.get(i), phones.get(i));
                System.out.println(space);
            }
        }

        System.out.println(" ");
        System.out.println("==========================================================");
        System.out.println(" ");
        System.out.println("==========================================================\n");
    }

    public static void deleteData(Scanner scanner, ArrayList<String> names, ArrayList<String> passs, ArrayList<Long> phones) {
        if (names.isEmpty()) {
            System.out.println("==========================================================");
            System.out.println("               THERE IS NO DATA TO DELETE.                ");
            System.out.println("==========================================================\n");
        } else {
            showData(names, passs, phones);
            System.out.print("\nInput data number to be deleted: ");
            int delete = scanner.nextInt();
            scanner.nextLine();

            if (delete >= 1 && delete <= names.size()) {
                names.remove(delete - 1);
                passs.remove(delete - 1);
                phones.remove(delete - 1);
                System.out.println("Data is removed.");
            } else {
                System.out.println("Invalid number to delete.");
            }

            System.out.println(" ");
        }
    }
}
