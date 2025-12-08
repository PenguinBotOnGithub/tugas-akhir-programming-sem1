#include <iostream>
#include "account_management.hpp"
#include "../globals.hpp"

using namespace std;

void check_balance() {
    cout << endl;
    cout << "Your account's balance is: Rp " << logged_in_account->balance<< endl;
    cout << endl;
}
