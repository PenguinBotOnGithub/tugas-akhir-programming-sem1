#include <cstdio>
#include <iostream>
#include "account_management.hpp"
#include "../globals.hpp"
#include "../menus/menus.hpp"

using namespace std;

Account* check_user_existence(string& username);

void login() {
    printf("\n");
    printf("=====================\n");
    printf("|    Login System   |\n");
    printf("=====================\n");

    Account* acc = NULL;
    while (true) {
        string username;
        string password;
        printf("Username: ");
        cin >> username;
        printf("Password: ");
        cin >> password;

        acc = check_user_existence(username);
        if (acc == NULL) {
            printf("Account not found!\n\n");
            goto try_again;
        }
        if (acc->password != password) {
            printf("Incorrect password!\n\n");
            goto try_again;
        }
        break;

        try_again: {
            char yn;
            printf("Try again? (y/n): ");
            cin >> yn;
            switch (yn) {
                case 'y': {
                    printf("\n");
                    continue;
                }
                case 'n': {
                    return;
                }
                default: {
                    printf("Not a valid answer!\n\n");
                    goto try_again;
                }
            }
        }
    }

    logged_in_account = acc;
    main_menu_loop();
}

Account* check_user_existence(string& username) {
    for (Account& account : accounts) {
        if (account.name == username) {
            return &account;
        }
    }

    return NULL;
}
