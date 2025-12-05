#include <cstdio>
#include <string>
#include <iostream>
#include "../globals.hpp"
#include "account_management.hpp"

using namespace std;

void confirm_password_loop(string& passwd, string& conf_passwd);

void register_account() {
    string username;
    string password;
    string confirm_password;

    printf("\n");
    printf("====================\n");
    printf("| Register Account |\n");
    printf("====================\n");

    printf("Username: ");
    cin >> username;
    confirm_password_loop(password, confirm_password);

    accounts.push_back({
        username,
        password,
        0,
        false
    });
    printf("\n");
}

void confirm_password_loop(string& passwd, string& conf_passwd) {
    for (;;) {
        printf("Password: ");
        cin >> passwd;
        printf("Confirm Password: ");
        cin >> conf_passwd;

        if (passwd == conf_passwd) {
            break;
        } else {
            printf("Password Confirmation failed!\n\n");
        }
    }
}
