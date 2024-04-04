import java.util.Scanner;

class SocialMediaAccount {
    String platform;
    String username;
    String password;
}

public class SocialMediaManager {
    private static final int MAX_ACCOUNTS = 10;
    private static SocialMediaAccount[] accounts = new SocialMediaAccount[MAX_ACCOUNTS];
    private static int numAccounts = 0;

    private static void addAccount() {
        if (numAccounts < MAX_ACCOUNTS) {
            Scanner scanner = new Scanner(System.in);
            SocialMediaAccount newAccount = new SocialMediaAccount();

            System.out.print("Enter platform: ");
            newAccount.platform = scanner.next();

            System.out.print("Enter username: ");
            newAccount.username = scanner.next();

            System.out.print("Enter password: ");
            newAccount.password = scanner.next();

            accounts[numAccounts++] = newAccount;
            System.out.println("Account added successfully!");
        } else {
            System.out.println("Cannot add more accounts. Maximum limit reached.");
        }
    }

    private static void displayAllAccounts() {
        System.out.println("List of saved accounts:");
        for (int i = 0; i < numAccounts; ++i) {
            System.out.println("Platform: " + accounts[i].platform + ", Username: " + accounts[i].username
                    + ", Password: " + accounts[i].password);
        }
    }

    private static void findAccount() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username to find: ");
        String searchUsername = scanner.next();
        boolean found = false;

        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].username.equals(searchUsername)) {
                System.out.println("Account found!");
                System.out.println("Platform: " + accounts[i].platform + ", Username: " + accounts[i].username
                        + ", Password: " + accounts[i].password);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Account not found.");
        }
    }

    private static void deleteAccount() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username to delete: ");
        String deleteUsername = scanner.next();
        boolean found = false;

        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i].username.equals(deleteUsername)) {
                found = true;
                for (int j = i; j < numAccounts - 1; ++j) {
                    accounts[j] = accounts[j + 1];
                }
                numAccounts--;
                System.out.println("Account deleted successfully!");
                break;
            }
        }

        if (!found) {
            System.out.println("Account not found. Deletion failed.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Add an account");
            System.out.println("2. Display all accounts");
            System.out.println("3. Find an account by username");
            System.out.println("4. Delete an account by username");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addAccount();
                    break;
                case 2:
                    displayAllAccounts();
                    break;
                case 3:
                    findAccount();
                    break;
                case 4:
                    deleteAccount();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);
    }
}
