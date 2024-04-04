class SocialMediaAccount:
    def __init__(self, platform, username, password):
        self.platform = platform
        self.username = username
        self.password = password

MAX_ACCOUNTS = 10
accounts = []
numAccounts = 0

def addAccount():
    global numAccounts
    if numAccounts < MAX_ACCOUNTS:
        platform = input("Enter platform: ")
        username = input("Enter username: ")
        password = input("Enter password: ")

        newAccount = SocialMediaAccount(platform, username, password)
        accounts.append(newAccount)
        numAccounts += 1
        print("Account added successfully!")
    else:
        print("Cannot add more accounts. Maximum limit reached.")

def displayAllAccounts():
    print("List of saved accounts:")
    for account in accounts:
        print(f"Platform: {account.platform}, Username: {account.username}, Password: {account.password}")

def findAccount():
    searchUsername = input("Enter username to find: ")
    found = False

    for account in accounts:
        if account.username == searchUsername:
            print("Account found!")
            print(f"Platform: {account.platform}, Username: {account.username}, Password: {account.password}")
            found = True
            break

    if not found:
        print("Account not found.")

def deleteAccount():
    deleteUsername = input("Enter username to delete: ")
    found = False

    for i, account in enumerate(accounts):
        if account.username == deleteUsername:
            found = True
            del accounts[i]
            global numAccounts
            numAccounts -= 1
            print("Account deleted successfully!")
            break

    if not found:
        print("Account not found. Deletion failed.")

def main():
    while True:
        print("\n1. Add an account")
        print("2. Display all accounts")
        print("3. Find an account by username")
        print("4. Delete an account by username")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            addAccount()
        elif choice == 2:
            displayAllAccounts()
        elif choice == 3:
            findAccount()
        elif choice == 4:
            deleteAccount()
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
