#include <iostream>
#include <string>
using namespace std;

struct SocialMediaAccount {
    string platform;
    string username;
    string password;
};

#define MAX_ACCOUNTS 10
SocialMediaAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void addAccount() {
    if (numAccounts < MAX_ACCOUNTS) {
        SocialMediaAccount newAccount;

        cout << "Enter platform: ";
        cin >> newAccount.platform;

        cout << "Enter username: ";
        cin >> newAccount.username;

        cout << "Enter password: ";
        cin >> newAccount.password;

        accounts[numAccounts++] = newAccount;
        cout << "Account added successfully!\n";
    } else {
        cout << "Cannot add more accounts. Maximum limit reached.\n";
    }
}

void displayAllAccounts() {
    cout << "List of saved accounts:\n";
    for (int i = 0; i < numAccounts; ++i) {
        cout << "Platform: " << accounts[i].platform << ", Username: " << accounts[i].username
                  << ", Password: " << accounts[i].password << "\n";
    }
}

void findAccount() {
    string searchUsername;
    int found = 0;

    cout << "Enter username to find: ";
    cin >> searchUsername;

    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].username == searchUsername) {
            cout << "Account found!\n";
            cout << "Platform: " << accounts[i].platform << ", Username: " << accounts[i].username
                      << ", Password: " << accounts[i].password << "\n";
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "Account not found.\n";
    }
}

void deleteAccount() {
    string deleteUsername;
    int found = 0;

    cout << "Enter username to delete: ";
    cin >> deleteUsername;

    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].username == deleteUsername) {
            found = 1;
            for (int j = i; j < numAccounts - 1; ++j) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            cout << "Account deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Account not found. Deletion failed.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Add an account\n";
        cout << "2. Display all accounts\n";
        cout << "3. Find an account by username\n";
        cout << "4. Delete an account by username\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
