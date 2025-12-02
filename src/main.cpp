#include <cstdio>
#include <iostream>

#include "types.hpp"
#include "globals.hpp"

using namespace std;

int main() {
    // Initialize global variables
    accounts = new Account[50];
    transaction_records = new TransactionRecord[100];

    printf("============================================================\n");
    printf("                   BANK MANAGEMENT SYSTEM                   \n");
    printf("============================================================\n");

    uint8_t input;
    while (true) {
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
                printf("FIXME: Implement register function");
                break;
            }
            case 3: {
                printf("Exitting....\n");
                return 0;
            }
            default: {
                printf("Not a valid option!\n\n");
            }
        }
    }
}
