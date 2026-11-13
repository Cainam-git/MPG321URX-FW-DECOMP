/* ipc_8051_find_filled_rx_slot  (FUN_a01346ac)
 *
 * Find a filled slot among the four incoming slots of the 8051 mailbox.
 * Returns: slot or 0xFE
 * Name basis: derived - slots at offset 0x60 + 20 * n of portal 0; unused
 *
 * Matching notes
 * --------------
 * FUN_a01346ac, flags -mcpu=v8 -O3 -g. Source form: the slot search of ipc_8051_poll_messages, written as in that
 * function.
 */
extern unsigned char ipc_8051_rx_slot;
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_RX_SLOTS        0x60   /* first slot for messages from the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_SLOT_COUNT           4
#define IPC_MSG_TYPE_MASK        0x0f   /* message type, bits 0..3 of the header word; 0 = slot empty */
#define IPC_NO_RX_MESSAGE        0xfe

/*
 * Find a slot that holds a message from the 8051. The four slots are tried in turn, starting at the round-robin
 * index ipc_8051_rx_slot, which moves on past every empty slot; a slot is filled when the type in its header word is
 * not 0. Returns the slot found and moves the index past it, or IPC_NO_RX_MESSAGE when all four are empty.
 * When the scan stops on slot 1..3 of the pass, the index is restored and the same scan is run once more.
 * No call to this routine is found in the code.
 */
unsigned char ipc_8051_find_filled_rx_slot(void)
{
    unsigned char saved, i, slot;
    unsigned int header = 0;

    saved = ipc_8051_rx_slot;
    for (i = 0; i < IPC_SLOT_COUNT; i++) {
        ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_rx_slot * IPC_SLOT_BYTES + IPC_8051_RX_SLOTS, &header, 1);
        if (header & IPC_MSG_TYPE_MASK) break;
        if (++ipc_8051_rx_slot > IPC_SLOT_COUNT - 1) ipc_8051_rx_slot = 0;
    }
    if (i != 0 && i != IPC_SLOT_COUNT) {
        ipc_8051_rx_slot = saved;
        for (i = 0; i < IPC_SLOT_COUNT; i++) {
            ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_rx_slot * IPC_SLOT_BYTES + IPC_8051_RX_SLOTS, &header, 1);
            if (header & IPC_MSG_TYPE_MASK) break;
            if (++ipc_8051_rx_slot > IPC_SLOT_COUNT - 1) ipc_8051_rx_slot = 0;
        }
    }
    if (i == IPC_SLOT_COUNT) slot = IPC_NO_RX_MESSAGE;
    else {
        slot = ipc_8051_rx_slot;
        if (++ipc_8051_rx_slot > IPC_SLOT_COUNT - 1) ipc_8051_rx_slot = 0;
    }
    return slot;
}
