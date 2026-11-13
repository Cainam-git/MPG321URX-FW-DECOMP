/* ipc_8051_poll_messages  (FUN_a0134de0)
 *
 * Check the incoming slots of the 8051 mailbox and decode a message that has arrived.
 * Name basis: proven - portal 0 slot poll, then ipc_8051_decode_message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0134de0 @ 0xa0134de0-0xa0135004 (548 bytes, 137 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the slot advance is written 'if (++ipc_8051_rx_slot > 3)
 * ipc_8051_rx_slot = 0;' at all three places (the form (slot + 1 > 3 ? 0 : slot + 1) gives separate %hi registers
 * for the stores); the second scan is a full copy of the first; the two strings are referenced by symbol.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();
extern void ipc_8051_decode_message(unsigned int *msg);
extern unsigned char ipc_8051_rx_slot;

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_TX_SLOT_FIRST  0x60    /* the 8051's sending slots: 0x60 + 20 * slot */
#define IPC_8051_TX_SLOT_SIZE   20      /* header word + four data words */
#define IPC_8051_SLOT_LAST      3       /* four slots, 0..3 */
#define IPC_SLOT_WORDS          5
#define IPC_MSG_TYPE_MASK       0x0f    /* header bits 0..3: message type; 0 = slot empty */
#define IPC_NO_RX_MESSAGE       0xfe    /* no slot holds a message */
#define IPC_POLL_ROUNDS         100     /* messages taken at most in one call */
#define DBG_MAILBOX             0x20    /* debug class of the 8051 mailbox prints */

/*
 * Take the messages the 8051 has left in its four sending slots of mailbox portal 0 (docs/MAILBOX.md, messages
 * from the 8051) and hand each one to ipc_8051_decode_message, at most 100 per call.
 *
 * Each round: from slot ipc_8051_rx_slot on, read the header word of up to four slots; a slot whose type (bits
 * 0..3) is not 0 holds a message. ipc_8051_rx_slot moves on past each empty slot (3 wraps to 0). When the slot
 * found is not the first one looked at, the scan is done once more from the slot the round started at. With no
 * message the routine returns. Otherwise ipc_8051_rx_slot moves past the slot, the five words are read and
 * decoded, and the header word is set to 0 to give the slot back to the 8051.
 *
 * Callers: ipc_8051_request_and_wait, ipc_8051_read_port_memory, ipc_8051_service and ipc_ack_port_change_bits.
 */
void ipc_8051_poll_messages(void)
{
    unsigned char rounds = IPC_POLL_ROUNDS;
    unsigned char start_slot, i, slot, offset;
    unsigned int header;
    unsigned int message[IPC_SLOT_WORDS];
    unsigned int zero;

    do {
        header = 0;
        start_slot = ipc_8051_rx_slot;
        for (i = 0; i < 4; i++) {
            ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_rx_slot * IPC_8051_TX_SLOT_SIZE + IPC_8051_TX_SLOT_FIRST, &header, 1);
            if (header & IPC_MSG_TYPE_MASK) break;
            if (++ipc_8051_rx_slot > IPC_8051_SLOT_LAST) ipc_8051_rx_slot = 0;
        }
        /* Found after skipping empty slots: look again from the start slot. */
        if (i != 0 && i != 4) {
            ipc_8051_rx_slot = start_slot;
            for (i = 0; i < 4; i++) {
                ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_rx_slot * IPC_8051_TX_SLOT_SIZE + IPC_8051_TX_SLOT_FIRST, &header, 1);
                if (header & IPC_MSG_TYPE_MASK) break;
                if (++ipc_8051_rx_slot > IPC_8051_SLOT_LAST) ipc_8051_rx_slot = 0;
            }
        }
        if (i == 4) slot = IPC_NO_RX_MESSAGE;
        else {
            slot = ipc_8051_rx_slot;
            if (++ipc_8051_rx_slot > IPC_8051_SLOT_LAST) ipc_8051_rx_slot = 0;
        }
        if (slot == IPC_NO_RX_MESSAGE) return;
        if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("\r\nS2L validslot %x\r\n", slot);
        offset = slot * IPC_8051_TX_SLOT_SIZE + IPC_8051_TX_SLOT_FIRST;
        ipc_mailbox_read(IPC_PORTAL_8051, offset, message, IPC_SLOT_WORDS);
        if (dbg_is_print_enabled(DBG_MAILBOX)) dbg_printf("S2L data_buf h %08lx d %08lx %08lx %08lx\r\n", message[0], message[1], message[2], message[3]);
        ipc_8051_decode_message(message);
        /* Release the slot. */
        zero = 0;
        ipc_mailbox_write(IPC_PORTAL_8051, offset, &zero, 1);
    } while (--rounds);
}
