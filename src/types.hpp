#ifndef _TYPES_
#define _TYPES_

#include <cstdint>
#include <string>

using namespace std;

struct {
    string name;
    string password;
    int64_t balance;
    bool deleted;
} typedef Account;

enum TransactionType {
    DEPOSIT,
    WITHDRAW,
    TRANSFER
};

struct {
    int64_t id_sender;
    int64_t id_receiver;
    TransactionType transaction_type;
    int64_t amount;
} typedef TransactionRecord;

#endif
