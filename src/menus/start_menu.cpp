#include "../account_management/account_management.hpp"
#include "../globals.hpp"
#include "menus.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

void start_menu_loop() {
    int input;
    while (true) {
        printf("\n");
        printf("=====================\n");
        printf("|     Start Menu    |\n");
        printf("=====================\n");
        printf("Actions:\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");

        printf("\nAnswer: ");
        cin >> input;

        switch (input) {
            case 1: {
                printf("FIXME: Implement login function");
                break;
            }
            case 2: {
                register_account();
                printf("first acc name: %s\n", accounts.at(0).name.c_str());
                break;
            }
            case 3: {
                printf("Exitting....\n");
                return;
            }
            default: {
                printf("%d\n", input);
                printf("Not a valid option!\n\n");
            }
        }
    }
}
