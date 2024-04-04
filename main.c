#include <stdio.h>
#include <string.h>

struct SocialMediaAccount {
    char platform[50];
    char username[50];
    char password[50];
};

#define MAX_ACCOUNTS 10
struct SocialMediaAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void addAccount() {
    if (numAccounts < MAX_ACCOUNTS) {
        struct SocialMediaAccount newAccount;

        printf("Enter platform: ");
        scanf("%s", newAccount.platform);

        printf("Enter username: ");
        scanf("%s", newAccount.username);

        printf("Enter password: ");
        scanf("%s", newAccount.password);

        accounts[numAccounts++] = newAccount;
        printf("Account added successfully!\n");
    } else {
        printf("Cannot add more accounts. Maximum limit reached.\n");
    }
}

void displayAllAccounts() {
    printf("List of saved accounts:\n");
    for (int i = 0; i < numAccounts; ++i) {
        printf("Platform: %s, Username: %s, Password: %s\n",
               accounts[i].platform, accounts[i].username, accounts[i].password);
    }
}

void findAccount() {
    char searchUsername[50];
    int found = 0;

    printf("Enter username to find: ");
    scanf("%s", searchUsername);

    for (int i = 0; i < numAccounts; ++i) {
        if (strcmp(accounts[i].username, searchUsername) == 0) {
            printf("Account found!\n");
            printf("Platform: %s, Username: %s, Password: %s\n",
                   accounts[i].platform, accounts[i].username, accounts[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void deleteAccount() {
    char deleteUsername[50];
    int found = 0;

    printf("Enter username to delete: ");
    scanf("%s", deleteUsername);

    for (int i = 0; i < numAccounts; ++i) {
        if (strcmp(accounts[i].username, deleteUsername) == 0) {
            found = 1;
            for (int j = i; j < numAccounts - 1; ++j) {
                strcpy(accounts[j].platform, accounts[j + 1].platform);
                strcpy(accounts[j].username, accounts[j + 1].username);
                strcpy(accounts[j].password, accounts[j + 1].password);
            }
            numAccounts--;
            printf("Account deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Account not found. Deletion failed.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add an account\n");
        printf("2. Display all accounts\n");
        printf("3. Find an account by username\n");
        printf("4. Delete an account by username\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
