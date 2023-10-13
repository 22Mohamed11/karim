#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

void signup() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    userCount++;
    printf("User signed up successfully!\n");
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1;  // Successful login
        }
    }

    printf("Login failed. Invalid username or password.\n");
    return 0;  // Login failed
}

int main() {
    int choice;
    int loggedIn = 0;

    do {
        printf("Menu:\n");
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                if (!loggedIn)
                    loggedIn = login();
                else
                    printf("You are already logged in.\n");
                break;
            case 3:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}