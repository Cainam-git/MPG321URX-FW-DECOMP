/* ipc_8051_tx_queue_flush  (FUN_a01350dc)
 *
 * Move queued messages into free outgoing slots of the 8051 mailbox.
 * Name basis: proven - ring at 0xA802DA6C to the slots of mailbox portal 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01350dc @ 0xa01350dc-0xa0135344 (616 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the message is a 5-word local structure initialised to zero at its
 * declaration (std pairs); the empty-queue branch clears words 3, 2, 1, 0 in that order; the slot advance is
 * written 'if (++ipc_8051_tx_slot > 3) ipc_8051_tx_slot = 0;'; the second scan is a full copy of the first.
 */
/* One queued message: header word + four data words, as it goes into a mailbox slot. */
struct ipc_8051_tx_entry { unsigned int word[5]; };
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char ipc_8051_tx_slot, ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;
extern struct ipc_8051_tx_entry ipc_8051_tx_queue[];

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_RX_SLOT_FIRST  0x10    /* the 8051's receiving slots: 0x10 + 20 * slot */
#define IPC_8051_RX_SLOT_SIZE   20      /* header word + four data words */
#define IPC_8051_SLOT_LAST      3       /* four slots, 0..3 */
#define IPC_MSG_TYPE_MASK       0x0f    /* header bits 0..3: message type; 0 = slot free */
#define IPC_NO_FREE_SLOT        0xff
#define IPC_TX_QUEUE_LAST_INDEX 0x24    /* queue indices run 0..0x24 */
#define IPC_FLUSH_ROUNDS        100     /* messages moved at most in one call */

/*
 * Move messages from ipc_8051_tx_queue into the free receiving slots of the 8051 in mailbox portal 0, at most 100
 * per call. The 8051 carries a slot out and clears its header (ipc_find_rx_message, ipc_run_message).
 *
 * Each round: from slot ipc_8051_tx_slot on, read the header word of up to four slots; a slot whose type (bits
 * 0..3) is 0 is free. ipc_8051_tx_slot moves on past each busy slot (3 wraps to 0). When the free slot found is
 * not the first one looked at, the scan is done once more from the slot the round started at. With no free slot,
 * or an empty queue, the routine returns. Otherwise the oldest queue entry is taken; its four data words are
 * written first and the header word last (the 8051 takes a slot with a non-zero type as filled). Then
 * ipc_8051_tx_slot moves past the slot.
 *
 * Callers: ipc_8051_send_storage_block, ipc_8051_send_buffer_chunks, ipc_8051_send_wake_port_table,
 * ipc_8051_send_usb_c_info, ipc_8051_send_power_cut_table, ipc_8051_send_wake_key_table,
 * ipc_8051_write_port_memory, ipc_8051_read_port_memory, ipc_8051_request_and_wait, ipc_8051_wait_tx_queue,
 * ipc_8051_service, ipc_ack_port_change_bits, UserSetAuroraLEDBarBrightness and sys_user_factory_reset.
 */
void ipc_8051_tx_queue_flush(void)
{
    unsigned char rounds = IPC_FLUSH_ROUNDS;
    unsigned char start_slot, i, slot;
    unsigned int header;
    struct ipc_8051_tx_entry msg = { { 0 } };

    do {
        header = 0;
        start_slot = ipc_8051_tx_slot;
        for (i = 0; i < 4; i++) {
            ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_tx_slot * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST, &header, 1);
            if (!(header & IPC_MSG_TYPE_MASK)) break;
            if (++ipc_8051_tx_slot > IPC_8051_SLOT_LAST) ipc_8051_tx_slot = 0;
        }
        /* Found after skipping busy slots: look again from the start slot. */
        if (i != 0 && i != 4) {
            ipc_8051_tx_slot = start_slot;
            for (i = 0; i < 4; i++) {
                ipc_mailbox_read(IPC_PORTAL_8051, ipc_8051_tx_slot * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST, &header, 1);
                if (!(header & IPC_MSG_TYPE_MASK)) break;
                if (++ipc_8051_tx_slot > IPC_8051_SLOT_LAST) ipc_8051_tx_slot = 0;
            }
        }
        if (i == 4) slot = IPC_NO_FREE_SLOT;
        else slot = ipc_8051_tx_slot;
        if (slot == IPC_NO_FREE_SLOT) return;
        if (ipc_8051_tx_queue_write_index == ipc_8051_tx_queue_read_index) {
            /* Queue empty: a zero header ends the call below. */
            msg.word[3] = 0;
            msg.word[2] = 0;
            msg.word[1] = 0;
            msg.word[0] = 0;
        } else {
            msg = ipc_8051_tx_queue[ipc_8051_tx_queue_read_index];
            if (++ipc_8051_tx_queue_read_index > IPC_TX_QUEUE_LAST_INDEX) ipc_8051_tx_queue_read_index = 0;
        }
        if (msg.word[0] == 0) return;
        ipc_mailbox_write(IPC_PORTAL_8051, slot * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST + 4, &msg.word[1], 4);
        ipc_mailbox_write(IPC_PORTAL_8051, slot * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST, &msg.word[0], 1);
        if (++ipc_8051_tx_slot > IPC_8051_SLOT_LAST) ipc_8051_tx_slot = 0;
    } while (--rounds);
}
