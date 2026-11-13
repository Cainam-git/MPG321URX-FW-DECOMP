/* ipc_8051_find_free_tx_slot  (FUN_a013453c)
 *
 * Find a free slot among the four outgoing slots of the 8051 mailbox.
 * Returns: slot or 0xFF
 * Name basis: derived - slots at offset 0x10 + 20 * n of portal 0; starts at the last used index; unused
 *
 * Matching notes
 * --------------
 * FUN_a013453c, flags -mcpu=v8 -O3 -g. Source form: the scan of ipc_8051_poll_messages (the receive poll over the
 * slots at 0x60), written twice, with '(status & 0xf) == 0' as the stop test.
 */
extern unsigned char ipc_8051_tx_slot;
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

#define IPC_PORTAL_8051          0      /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOTS        0x10   /* first slot for messages to the 8051 (docs/MAILBOX.md) */
#define IPC_SLOT_BYTES           20     /* one slot: header word and four data words */
#define IPC_SLOT_COUNT           4
#define IPC_MSG_TYPE_MASK        0x0f   /* message type, bits 0..3 of the header word; 0 = slot free */
#define IPC_NO_FREE_TX_SLOT      0xff

/*
 * Find a free slot for a message to the 8051. The four slots are tried in turn, starting at the round-robin index
 * ipc_8051_tx_slot, which moves on past every slot found busy; a slot is free when the type in its header word is 0.
 * Returns the free slot, or IPC_NO_FREE_TX_SLOT when all four are busy. The index is not moved past the slot
 * found (ipc_8051_advance_tx_slot does that). No call to this routine is found in the code.
 * When the scan stops on slot 1..3 of the pass, the index is restored and the same scan is run once more.
 */
unsigned char ipc_8051_find_free_tx_slot(void)
{
    unsigned char saved, i, slot;
    unsigned int header = 0;

    saved = ipc_8051_tx_slot;
    for (i = 0; i < IPC_SLOT_COUNT; i++) {
        ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_tx_slot * IPC_SLOT_BYTES + IPC_8051_TX_SLOTS, &header, 1);
        if ((header & IPC_MSG_TYPE_MASK) == 0) break;
        if (++ipc_8051_tx_slot > IPC_SLOT_COUNT - 1) ipc_8051_tx_slot = 0;
    }
    if (i != 0 && i != IPC_SLOT_COUNT) {
        ipc_8051_tx_slot = saved;
        for (i = 0; i < IPC_SLOT_COUNT; i++) {
            ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_tx_slot * IPC_SLOT_BYTES + IPC_8051_TX_SLOTS, &header, 1);
            if ((header & IPC_MSG_TYPE_MASK) == 0) break;
            if (++ipc_8051_tx_slot > IPC_SLOT_COUNT - 1) ipc_8051_tx_slot = 0;
        }
    }
    if (i == IPC_SLOT_COUNT) slot = IPC_NO_FREE_TX_SLOT;
    else
        slot = ipc_8051_tx_slot;
    return slot;
}
