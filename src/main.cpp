#include <cstdio>

#include "types.hpp"
#include "globals.hpp"
#include "menus/menus.hpp"

using namespace std;

vector<Account> accounts = {};
vector<Account> transaction_records = {};

int main() {
    printf("============================================================\n");
    printf("|                  BANK MANAGEMENT SYSTEM                  |\n");
    printf("============================================================\n");

    start_menu_loop();
}
