/* ipc_publish_port_status  (FUN_a00700cc)
 *
 * Send the changed input port records and the HPD status to the main processor.
 * Name basis: proven - prints 'InputPortidx %d' and 'RxHPDStatus : %02X'; ipc_build_port_descriptor +
 *   ipc_write_mailbox_slot; main loop
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00700cc @ 0xa00700cc-0xa00703b8 (187 words), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the port id test is 'switch (port_id) { case 1: ... case 9: }' on the unsigned char port_id (fw a0070120
 *    'and %o4, 0xff' + 'add -1' + 'cmp 8', separate from record's 'add %o4, -1' at a0070100); record and rec
 *    are computed inside the case arm (fw record address a0070100-a007011c, ahead of the test at a0070120);
 *  - the slot loop has its own counter k (bound 7, fw 'cmp 6; bleu'); the nibble loop uses i with the bound in
 *    the local record_count = 7 (fw a0070378 'cmp 7; bcs'), as in ipc_read_port_id_list;
 *  - the RxHPDStatus print takes input_port_event_flags as its %02X argument;
 *  - the word-3 block reads input_port_event_flags once into events (fw a0070260);
 *  - memcpy (the block copy of the slot_of_entry initializer) is the firmware memcpy lib_memcpy.
 */

/* Port record (20 bytes, input_port_records): one per input stream. Fields +2..+0xE and +0x12 are what
   ipc_build_port_descriptor sends to the main processor; +0xF and +0x10 ask this routine to send them. */
struct port_record {
    unsigned char state, byte_0x1;                  /* state: link state; its low nibble is published below */
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;
    unsigned char colour_space;                     /* +0xC */
    unsigned char published_flags;                  /* +0xD */
    unsigned char byte_0xe;
    unsigned char publish;                          /* +0xF: 1 = send the record to the main processor */
    unsigned char changed;                          /* +0x10: 1 = send it and mark the port as changed */
    unsigned char step;                             /* +0x11 */
    unsigned short flags;                           /* +0x12 */
};
extern struct port_record input_port_records[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned char input_port_event_flags, input_port_flag_bits, input_event_clear_mask;
extern unsigned int ipc_slot0_status_word;
extern int dbg_printf();
extern void ipc_read_port_id_list(unsigned char *ids);
extern void ipc_build_port_descriptor(unsigned char id, unsigned char n, unsigned int *buf);
extern void ipc_write_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void ipc_read_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void ipc_set_port_changed_bit(unsigned char i);
extern void ipc_publish_status_flags(void);
extern unsigned char dp_tx_get_hpd_status(void);
extern unsigned char dp_tx_get_status_byte(void);
extern void dp_mst_select_port(int);
extern void dp_mst_reset_port(void);
extern int hdr_get_status_code(void);

/* Slot 0 of the input-processor mailbox: the state words this processor publishes. */
#define IPC_SLOT_STATE          0
#define IPC_PORT_STATE_WORD     0       /* bit 0 ready (ipc_post_ready_flag), bits 1..2 HDR status code,
                                           bits 4..31 the state nibbles of port records 0..6 */
#define IPC_FLAG_BITS_WORD      2       /* top byte: kept in input_port_flag_bits */
#define IPC_STATUS_WORD         3       /* bits 0..5 event bits, 6..7 DP TX status, 8..15 HPD status,
                                           16..23 port change bits, 24..31 status flags */

#define PORT_SLOT_COUNT         7       /* mailbox slots 1..7, one port descriptor each */
#define PORT_DESCRIPTOR_WORDS   4
#define PORT_RECORD_CHANGED     1       /* value of publish / changed that asks for a send */

#define EVENT_BITS_PUBLISHED    0x3f    /* event bits 0..5 go into word 3 */
#define EVENT_DP_0              0x10    /* event bit 4 (input 4 in input_port_raise_event): MST port 0 */
#define EVENT_DP_1              0x20    /* event bit 5 (inputs above 4 there): MST port 1 */
#define HPD_STATUS_SHIFT        8
#define DP_TX_STATUS_SHIFT      6
#define HDR_STATUS_BITS         6       /* bits 1..2 of word 0 */
#define PORT_STATE_NIBBLE       0xf
#define PORT_STATE_FIRST_BIT    4

/*
 * Publish the state of the input ports to the main processor through slot 0..7 of the input-processor mailbox.
 * Called once per pass of the main loop (sys_main_part7), before osd_run_pending_unzip. No parameters, no
 * return value. The main program takes the words in ipc_ack_port_change_bits.
 *
 * In this order:
 *   1. Port descriptors. Word 1 of slot 0 holds a port id for each of the slots 1..7 (ipc_read_port_id_list);
 *      ids 1..9 stand for port record id - 1, other ids are skipped. Every port whose record asks for it
 *      (publish or changed = 1) gets its 4-word descriptor written into its slot. For changed, the slot's
 *      change bit in word 3 is set too. Both requests are then cleared.
 *   2. Word 2: its top byte is stored in input_port_flag_bits.
 *   3. Word 3: byte 1 = dp_tx_get_hpd_status(), byte 3 = ipc_publish_status_flags(), byte 0 = event bits
 *      0..5 of input_port_event_flags and bits 0..1 of dp_tx_get_status_byte(). The event bits set in
 *      input_event_clear_mask are cleared after they are taken. When event bits are still set after that, they
 *      are printed, and the MST service is reset for DisplayPort port 0 / 1 (dp_mst_select_port,
 *      dp_mst_reset_port) when the published word has bit 4 / bit 5 set.
 *   4. Word 0: bits 1..2 = HDR status code (written once), then bits 4..31 = the low nibble of the state of
 *      port records 0..6 (written again).
 */
void ipc_publish_port_status(void)
{
    /* Pairs per entry of the port id list; the second byte of pair k is its mailbox slot (k + 1). */
    unsigned char slot_of_entry[14] = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7 };
    unsigned int descriptor[PORT_DESCRIPTOR_WORDS];
    unsigned char port_ids[8];
    unsigned int flag_word, hpd_word, event_word, state_nibbles;
    unsigned char i, k;
    unsigned char record_count = PORT_SLOT_COUNT;

    /* 1. One descriptor per slot whose port asks to be sent. */
    ipc_read_port_id_list(port_ids);
    for (k = 0; k < PORT_SLOT_COUNT; k++) {
        unsigned char port_id;
        unsigned char record;
        struct port_record *rec;
        port_id = port_ids[k];
        switch (port_id) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            record = port_id - 1;
            rec = &input_port_records[record];
            if (rec->publish == PORT_RECORD_CHANGED || rec->changed == PORT_RECORD_CHANGED) {
                dbg_printf("InputPortidx  %d \r\n ", record);
                ipc_build_port_descriptor(port_id, record, descriptor);
                ipc_write_mailbox_slot(slot_of_entry[k * 2 + 1], 0, descriptor, PORT_DESCRIPTOR_WORDS);
                if (rec->changed == PORT_RECORD_CHANGED) {
                    /* Bit 16 + k of word 3; the main processor clears it with command 0x81. */
                    ipc_set_port_changed_bit(k);
                    rec->changed = 0;
                }
                rec->publish = 0;
            }
            break;
        }
    }

    /* 2. The flag bits in the top byte of word 2. */
    ipc_read_mailbox_slot(IPC_SLOT_STATE, IPC_FLAG_BITS_WORD, &flag_word, 1);
    input_port_flag_bits = flag_word >> 24;

    /* 3. Word 3, byte 1: hot-plug status. Byte 3 follows in ipc_publish_status_flags. */
    hpd_word = 0;
    ipc_read_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &hpd_word, 1);
    hpd_word &= 0xffff00ff;
    hpd_word |= dp_tx_get_hpd_status() << HPD_STATUS_SHIFT;
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &hpd_word, 1);
    ipc_publish_status_flags();

    /* Byte 0: the event bits as they were, then the ones in the clear mask are dropped. */
    event_word = 0;
    ipc_read_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &event_word, 1);
    {
        unsigned char events = input_port_event_flags;
        unsigned int word = event_word;
        unsigned char remaining = events & ~input_event_clear_mask;
        unsigned int published = events & EVENT_BITS_PUBLISHED;
        word &= ~0xff;
        input_port_event_flags = remaining;
        event_word = word | published;
    }
    event_word |= (dp_tx_get_status_byte() & 3) << DP_TX_STATUS_SHIFT;
    if (input_port_event_flags != 0) {
        dbg_printf("\033[1;33mRxHPDStatus : %02X\r\n\033[m", input_port_event_flags);
        if (event_word & EVENT_DP_0) { dp_mst_select_port(0); dp_mst_reset_port(); }
        if (event_word & EVENT_DP_1) { dp_mst_select_port(1); dp_mst_reset_port(); }
    }
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &event_word, 1);

    /* 4. Word 0: HDR status code, then the state nibbles of the first seven port records. */
    ipc_slot0_status_word &= ~HDR_STATUS_BITS;
    ipc_slot0_status_word |= (hdr_get_status_code() & 3) * 2;
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_PORT_STATE_WORD, &ipc_slot0_status_word, 1);
    state_nibbles = 0;
    for (i = 0; i < record_count; i++)
        state_nibbles |= (input_port_records[i].state & PORT_STATE_NIBBLE) << (i * 4);
    ipc_slot0_status_word = (ipc_slot0_status_word & 0xf) | state_nibbles << PORT_STATE_FIRST_BIT;
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_PORT_STATE_WORD, &ipc_slot0_status_word, 1);
}
