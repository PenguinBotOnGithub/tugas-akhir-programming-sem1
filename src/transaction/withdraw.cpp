#include <cstdint>
#include <iostream>
#include "transaction.hpp"
#include "../globals.hpp"

using namespace std;

void withdraw_money() {
    int64_t amount;

    cout << "\n=== Withdraw Money ===\n";
    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= 0 || amount > logged_in_account->balance) {
        cout << "Invalid or insufficient balance!\n";
        return;
    }

    logged_in_account->balance -= amount;

    TransactionRecord tr;
    tr.id_sender = (int64_t)(logged_in_account - &accounts[0]);
    tr.id_receiver = -1; // bank
    tr.transaction_type = WITHDRAW;
    tr.amount = amount;
    transaction_records.push_back(tr);

    cout << "Withdraw successful!\n\n";
}
