#include <cstdint>
#include <iostream>
#include "transaction.hpp"
#include "../globals.hpp"

void deposit() {
    int64_t amount;

    cout << "\n=== Deposit Money ===\n";
    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    logged_in_account->balance += amount;

    TransactionRecord tr;
    tr.id_sender = -1; // bank
    tr.id_receiver = (int64_t)(logged_in_account - &accounts[0]);
    tr.transaction_type = DEPOSIT;
    tr.amount = amount;
    transaction_records.push_back(tr);

    cout << "Deposit successful!\n\n";
}
