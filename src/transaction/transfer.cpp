#include <iostream>
#include <vector>
#include <inttypes.h>
#include "transaction.hpp"
#include "../types.hpp"
#include "../globals.hpp"

using namespace std;

void transfer_money() {
    if (logged_in_account == NULL) {
        cout << "You must be logged in to transfer.\n";
        return;
    }

    string receiver_name;
    int64_t amount;

    cout << "\n=== Transfer Money ===\n";
    cout << "Enter receiver name: ";
    cin >> receiver_name;

    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Amount must be greater than 0!\n";
        return;
    }

    // Cari akun tujuan
    Account* receiver = NULL;
    for (auto &acc : accounts) {
        if (!acc.deleted && acc.name == receiver_name) {
            receiver = &acc;
            break;
        }
    }

    if (receiver == NULL) {
        cout << "Receiver not found!\n";
        return;
    }

    if (receiver == logged_in_account) {
        cout << "You cannot transfer to yourself!\n";
        return;
    }

    // Cek saldo cukup
    if (logged_in_account->balance < amount) {
        cout << "Insufficient balance!\n";
        return;
    }

    // Lakukan transfer
    logged_in_account->balance -= amount;
    receiver->balance += amount;

    // Simpan catatan transaksi
    TransactionRecord tr;
    tr.id_sender = (int64_t)(logged_in_account - &accounts[0]);
    tr.id_receiver = (int64_t)(receiver - &accounts[0]);
    tr.amount = amount;
    tr.transaction_type = TRANSFER;
    transaction_records.push_back(tr);

    cout << "Transfer successful!\n";
    cout << "You sent " << amount << " to " << receiver->name << ".\n";
}
