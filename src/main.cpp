#include <cstdint>
#include <cstdio>

#include "types.hpp"
#include "globals.hpp"
#include "menus/menus.hpp"

using namespace std;

vector<Account> accounts = {};
vector<TransactionRecord> transaction_records = {};
Account* logged_in_account = NULL;

int main() {
   // setup admin account
    accounts.push_back({
        .name = "admin",
        .password = "admin",
        .balance = INT64_MAX,
        .deleted = false
    });

    printf("============================================================\n");
    printf("|                  BANK MANAGEMENT SYSTEM                  |\n");
    printf("============================================================\n");

    start_menu_loop();
}
