/* ipc_8051_wait_tx_queue  (FUN_a01356fc)
 *
 * Flush the 8051 send queue until it has room (mode 1), is empty (2) or the mailbox is empty too (3).
 * Note: Mode 1 stops as soon as the 36-entry queue has room for n bytes (16 per entry). No time limit.
 * Name basis: derived - three modes: flush until n bytes fit, flush until the queue is empty, the same and
 *   then wait until the mailbox slots read zero
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01356fc @ 0xa01356fc..0xa013588c (100 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: a switch on the unsigned char mode; the room is an unsigned short and
 * is compared as (unsigned short)(room << 4); the slot loop is written 'for (i = 0; i * 20 + 16 <= 0x50; i++)'.
 */
extern unsigned char ipc_8051_tx_queue_read_index, ipc_8051_tx_queue_write_index;
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_mailbox_read(unsigned char, unsigned char, unsigned int *, unsigned char);

/* Values of mode. */
#define WAIT_FOR_ROOM           1       /* until the queue has room for byte_count bytes */
#define WAIT_UNTIL_EMPTY        2       /* until the queue is empty */
#define WAIT_UNTIL_TAKEN        3       /* as 2, then until the 8051 has taken every message from its slots */

#define IPC_PORTAL_8051         0       /* mailbox portal between the main processor and the 8051 */
#define IPC_8051_RX_SLOT_FIRST  16      /* the 8051's receiving slots: 0x10 + 20 * slot */
#define IPC_8051_RX_SLOT_SIZE   20
#define IPC_8051_RX_SLOT_LAST   0x50    /* a slot offset above this is past the fourth slot */
#define IPC_8051_TX_QUEUE_ROOM  36      /* entries that can wait at once (37 entries, one stays empty) */
#define MSG_PIECE_SHIFT         4       /* one entry carries 16 bytes */

/*
 * Wait for the outgoing 8051 queue (ipc_8051_tx_queue), moving its entries into the mailbox with
 * ipc_8051_tx_queue_flush while it waits. None of the waits has a time limit; WAIT_UNTIL_TAKEN also needs an
 * 8051 that serves its mailbox.
 *
 *   mode        WAIT_FOR_ROOM, WAIT_UNTIL_EMPTY or WAIT_UNTIL_TAKEN; any other value returns at once
 *   byte_count  WAIT_FOR_ROOM only: bytes about to be queued; the wait ends when 16 * free entries >= byte_count
 *
 * WAIT_UNTIL_TAKEN ends when the header words of the 8051's four receiving slots (+0x10, +0x24, +0x38, +0x4C)
 * all read 0.
 *
 * Callers: startup_load_port_edids and edid_write_port_edid (WAIT_FOR_ROOM, with the bytes they queue next),
 * input_api_select_ports (WAIT_UNTIL_TAKEN) and startup_bring_up_system (WAIT_UNTIL_EMPTY).
 */
void ipc_8051_wait_tx_queue(unsigned char mode, unsigned short byte_count)
{
    unsigned int header = 0;
    unsigned int any_header;
    unsigned char i;
    unsigned short room;

    switch (mode) {
    case WAIT_FOR_ROOM:
        for (;;) {
            /* Free entries of the queue. */
            if (ipc_8051_tx_queue_write_index > ipc_8051_tx_queue_read_index)
                room = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index + IPC_8051_TX_QUEUE_ROOM;
            else if (ipc_8051_tx_queue_write_index >= ipc_8051_tx_queue_read_index)
                room = IPC_8051_TX_QUEUE_ROOM;
            else
                room = ipc_8051_tx_queue_read_index - ipc_8051_tx_queue_write_index - 1;
            if (byte_count <= (unsigned short)(room << MSG_PIECE_SHIFT))
                break;
            ipc_8051_tx_queue_flush();
        }
        break;
    case WAIT_UNTIL_EMPTY:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        break;
    case WAIT_UNTIL_TAKEN:
        while (ipc_8051_tx_queue_write_index != ipc_8051_tx_queue_read_index)
            ipc_8051_tx_queue_flush();
        do {
            any_header = 0;
            for (i = 0; i * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST <= IPC_8051_RX_SLOT_LAST; i++) {
                ipc_mailbox_read(IPC_PORTAL_8051, i * IPC_8051_RX_SLOT_SIZE + IPC_8051_RX_SLOT_FIRST, &header, 1);
                any_header |= header;
            }
        } while (any_header != 0);
        break;
    }
}
