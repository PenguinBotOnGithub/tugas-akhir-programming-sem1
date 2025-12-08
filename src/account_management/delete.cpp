#include <iostream>
#include "account_management.hpp"
#include "../globals.hpp"

using namespace std;
void delete_account() {
    cout << endl;
    logged_in_account->deleted = true;
    cout << "Account deleted!" << endl;
}
