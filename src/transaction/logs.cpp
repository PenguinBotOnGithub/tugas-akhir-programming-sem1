#include <cstdint>
#include <inttypes.h>
#include <cstdio>
#include "transaction.hpp"
#include "../globals.hpp"

void transaction_logs() {
    if ((int64_t)(logged_in_account - &accounts[0]) != 0) {
        printf("Not a valid answer!\n\n");
        return;
    }

    printf("\n");
    printf("========= Transaction Logs =========");
    for (const TransactionRecord &tr : transaction_records) {
        switch (tr.transaction_type) {
            case DEPOSIT: {
                printf("type: deposit\namount: %" PRId64 "\n", tr.amount);
            }
            case WITHDRAW: {
                printf("type: withdraw\namount: %" PRId64 "\n", tr.amount);
            }
            case TRANSFER: {
                printf("type: transfer\nid_sender: %" PRId64 "\nid_receiver: %" PRId64 "\namount: %" PRId64 "\n", tr.id_sender, tr.id_receiver, tr.amount);
            }
        }
        printf("\n");
    }
}
