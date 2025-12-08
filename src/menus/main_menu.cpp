#include <cstdio>
#include <iostream>
#include <inttypes.h>
#include "menus.hpp"
#include "../transaction/transaction.hpp"
#include "../globals.hpp"
#include "../account_management/account_management.hpp"

using namespace std;

void main_menu_loop() {
    printf("\n");
    printf("======================\n");
    printf("|      Main Menu     |\n");
    printf("======================\n");
    print_actions: {
        printf("Actions:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Delete Account\n");
        printf("6. Logout\n");
    }


    char input;
    printf("Answer: ");
    cin >> input;
    switch (input) {
        case '1': {
            check_balance();
            goto print_actions;
        }
        case '2': {
            deposit();
            goto print_actions;
        }
        case '3': {
            withdraw_money();
            goto print_actions;
        }
        case '4': {
            transfer_money();
            goto print_actions;
        }
        case '5': {
            delete_account();
            return;
        }
        case '6': {
            logged_in_account = NULL;
            printf("Logging out...\n");
            return;
        }
        default: {
            printf("Not a valid answer!\n\n");
            goto print_actions;
        }
    }
}
