/* ipc_8051_advance_tx_slot  (FUN_a0134684)
 *
 * Move the outgoing slot index on by one, wrapping after 3.
 * Name basis: derived - index byte at 0xA802CB8D; unused
 *
 * Matching notes
 * --------------
 * FUN_a0134684, flags -mcpu=v8 -O2 -g. Source form: the incremented byte in a local, two separate stores in the
 * if/else.
 */
extern unsigned char ipc_8051_tx_slot;

#define IPC_SLOT_COUNT  4

/* Move the round-robin index of the 8051 transmit slots to the next slot, 3 -> 0. Nothing in the firmware calls this
   routine. */
void ipc_8051_advance_tx_slot(void)
{
    unsigned char next = ipc_8051_tx_slot + 1;

    if (next > IPC_SLOT_COUNT - 1)
        ipc_8051_tx_slot = 0;
    else
        ipc_8051_tx_slot = next;
}
