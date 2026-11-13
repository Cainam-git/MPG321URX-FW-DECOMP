/* dp_mst_handle_link_address  (FUN_a00d7e6c)
 *
 * Answer the MST request 0x01 (LINK_ADDRESS).
 * Name basis: proven - case 0x01 = LINK_ADDRESS, request number of the DisplayPort MST sideband message set;
 *   called from dp_mst_dispatch_request; 120-byte reply built from register values and AUX reads
 *
 * Matching notes
 * --------------
 * FUN_a00d7e6c (leon2s, 0xa00d7e6c-0xa00d82c8, 1116 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the message is a union of a 120-byte view and a view of bit-field words: the header word, then 20-byte
 *    slots from byte 16, each starting 2 bytes before the entry it fills (struct link_address_slot);
 *  - dp_mst_message_state_port is read into a local (port) for the first block; later blocks index
 *    dp_mst_ctl_reg_blocks[dp_mst_message_state_port] directly;
 *  - the entry count is an unsigned int compared as unsigned short; slots are indexed with the variable entry;
 *  - 'length += 0x14' is written in each arm of the notify flag test (one add after merging; the extra
 *    references give length its register).
 */

/*
 * The reply as dp_mst_pack_link_address_reply reads it (byte offsets in the message):
 *   0        header: request number in bits 0..6
 *   1..16    16 bytes
 *   17       entry count in bits 0..3
 *   18 + 20e entry e: byte 0, byte 1, byte 2, 16 data bytes, last byte. When bit 7 of byte 0 is set the
 *            packer sends only bits 6..7 of byte 1 for that entry.
 * The bit-field view covers this with 20-byte slots that start at byte 16 + 20e, two bytes before entry e: the
 * first byte of a slot is the byte before (byte 16 or the last data byte of entry e-1), the second is the
 * count (slot 0) or the last byte of entry e-1, then come bytes 0..2 of entry e and its first 15 data bytes.
 */
struct link_address_slot {
    unsigned int prev_byte : 8;
    unsigned int prev_last_high : 4;        /* slot 0: high nibble of the count byte */
    unsigned int prev_last_low : 4;         /* slot 0: the entry count */
    unsigned int byte0_bit7 : 1;            /* entry byte 0 */
    unsigned int byte0_bits4_6 : 3;
    unsigned int byte0_bits0_3 : 4;
    unsigned int byte1_bit7 : 1;            /* entry byte 1 */
    unsigned int byte1_bit6 : 1;
    unsigned int byte1_bit5 : 1;
    unsigned int byte1_rest : 5;
    unsigned char byte2;                    /* entry byte 2 */
    unsigned char data_head[15];            /* first 15 of the 16 data bytes */
};
union link_address_msg {
    unsigned char bytes[120];
    struct {
        unsigned int header_bit7 : 1;
        unsigned int request : 7;           /* header byte, bits 0..6 */
        unsigned int bytes_1_3 : 24;
        unsigned char bytes_4_15[12];
        struct link_address_slot slot[5];
    } s;
};

#define MST_REQUEST_LINK_ADDRESS    0x01
#define MST_REPLY_LINK_ADDRESS      0       /* body format of dp_mst_send_reply */
#define MST_QUEUE_REPLY             2
#define MST_DIRECTION_DOWN          1

#define LINK_ADDRESS_FIXED_BYTES    0x12    /* header, 16 bytes, count byte */
#define SHORT_ENTRY_BYTES           2       /* entry with byte 0 bit 7 set */
#define FULL_ENTRY_BYTES            0x14
#define ENTRY_DATA_OFFSET           21      /* message byte of the first data byte of entry 0 */
#define ENTRY_SIZE                  20

/* Positions in dp_mst_dpcd_addresses (the register number at that position in brackets). */
#define MST_ADDR_INDEX_0x205        5       /* bit 0 follows the notify flag */
#define MST_ADDR_INDEX_0x340        15      /* registers 0x340..0x34F: the 16 bytes */
#define MST_ADDR_INDEX_0x3B0        101     /* register 0x3B0: byte 2 of entry 1 */

/* AUX reads from the sink of DP output 0 (dp_tx_aux_request_copy). */
#define DP_TX_OUTPUT_0              0
#define AUX_CMD_READ                0x90
#define SINK_ADDR_0x000             0x00    /* byte 2 of entry 2; below 0x12 gives byte 0 bits 4..6 = 3, else 2 */
#define SINK_ADDR_0x021             0x21    /* bit 0 gives byte 1 bit 7 of entry 2 */
#define SINK_ADDR_0x030             0x30    /* 16 bytes: the data of entry 2 */
#define SINK_REVISION_LIMIT         0x12

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_notify_flag;
extern unsigned char dp_mst_message_state_addressed_flag;
extern unsigned char dp_mst_message_state_byte_0x4b;
extern unsigned char dp_mst_message_state_byte_0x4e;
extern unsigned char dp_mst_option_word;
extern unsigned short dp_mst_message_state;                 /* first halfword of the message state record */
extern const unsigned short dp_mst_dpcd_addresses[];        /* register numbers, used as word indexes */
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];      /* per port: register block, one word per register */
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);
extern void dp_mst_send_reply(void *, int, int, int, unsigned short);

/*
 * Answer an MST LINK_ADDRESS request on the current port (dp_mst_message_state_port). Called by
 * dp_mst_dispatch_request for request number 0x01.
 *
 * Phases, in order:
 *   1. Header: request number 1; bytes 1..16 = registers 0x340..0x34F of the port.
 *   2. Entry count: 2, or dp_mst_option_word + 2 on port 0. Only entries 0..2 are filled below.
 *   3. Entry 0: short entry (byte 0 = 0x90: bit 7 set, bits 4..6 = 1, bits 0..3 = 0; byte 1 bits 7 and 6 set).
 *   4. Entry 1: byte 0 bits 4..6 = 3, bits 0..3 = 8; byte 1 bit 6 set; byte 2 = register 0x3B0; data =
 *      registers 0x340..0x34F of the port again; last byte 0x12.
 *   5. Entry 2, while dp_mst_message_state_notify_flag is set: read sink bytes 0x000 and 0x021 of DP output 0
 *      into the message state (bytes +0x4E and +0x4B); byte 0 bits 4..6 = 3 when sink byte 0x000 is below
 *      0x12, else 2, bits 0..3 = 1; byte 1 bit 7 = bit 0 of sink byte 0x021, bit 6 set; byte 2 = sink byte
 *      0x000; data = sink bytes 0x030..0x03F; last byte 0; set bit 0 of register 0x205 of the port.
 *      Without the flag: byte 0 bits 0..3 = 1 and everything else 0, data cleared, register 0x205 bit 0
 *      cleared.
 *   6. Queue the reply (dp_mst_send_reply, body format 0), then set dp_mst_message_state_addressed_flag and
 *      clear the first halfword of the message state.
 */
void dp_mst_handle_link_address(void)
{
    unsigned char sink_bytes[16];
    union link_address_msg msg;
    unsigned char port;
    volatile unsigned int *regs;
    unsigned char i;
    unsigned char entry;
    unsigned int entry_count;
    unsigned int length;

    /* Phase 1. */
    msg.s.request = MST_REQUEST_LINK_ADDRESS;
    port = dp_mst_message_state_port;
    regs = dp_mst_ctl_reg_blocks[port];
    for (i = 0; i < 16; i++)
        msg.bytes[1 + i] = regs[dp_mst_dpcd_addresses[i + MST_ADDR_INDEX_0x340]];

    /* Phase 2. */
    if (port == 0) {
        entry_count = dp_mst_option_word + 2;
        msg.s.slot[0].prev_last_low = entry_count;
    } else {
        msg.s.slot[0].prev_last_low = 2;
        entry_count = 2;
    }
    length = LINK_ADDRESS_FIXED_BYTES;
    for (entry = 0; entry < (unsigned short)entry_count; entry++) {
        if (entry == 0) {
            /* Phase 3. */
            msg.s.slot[entry].byte0_bit7 = 1;
            msg.s.slot[entry].byte0_bits4_6 = 1;
            msg.s.slot[entry].byte0_bits0_3 = 0;
            msg.s.slot[entry].byte1_bit7 = 1;
            msg.s.slot[entry].byte1_bit6 = 1;
            length += SHORT_ENTRY_BYTES;
        } else if (entry == 1) {
            /* Phase 4. */
            msg.s.slot[entry].byte0_bit7 = 0;
            msg.s.slot[entry].byte0_bits4_6 = 3;
            msg.s.slot[entry].byte0_bits0_3 = 8;
            msg.s.slot[entry].byte1_bit7 = 0;
            msg.s.slot[entry].byte1_bit6 = 1;
            msg.s.slot[entry].byte2 = dp_mst_ctl_reg_blocks[dp_mst_message_state_port][dp_mst_dpcd_addresses[MST_ADDR_INDEX_0x3B0]];
            for (i = 0; i < 16; i++)
                msg.bytes[entry * ENTRY_SIZE + ENTRY_DATA_OFFSET + i] = dp_mst_ctl_reg_blocks[dp_mst_message_state_port][dp_mst_dpcd_addresses[i + MST_ADDR_INDEX_0x340]];
            msg.s.slot[entry + 1].prev_last_high = 1;   /* last byte of entry 1 = 0x12 */
            msg.s.slot[entry + 1].prev_last_low = 2;
            length += FULL_ENTRY_BYTES;
        } else if (entry == 2) {
            /* Phase 5. */
            if (dp_mst_message_state_notify_flag) {
                dp_tx_aux_request_copy(DP_TX_OUTPUT_0, AUX_CMD_READ, SINK_ADDR_0x000, 0, sink_bytes);
                dp_mst_message_state_byte_0x4e = sink_bytes[0];
                dp_tx_aux_request_copy(DP_TX_OUTPUT_0, AUX_CMD_READ, SINK_ADDR_0x021, 0, sink_bytes);
                dp_mst_message_state_byte_0x4b = sink_bytes[0];
                msg.s.slot[entry].byte0_bit7 = 0;
                msg.s.slot[entry].byte0_bits0_3 = 1;
                if (dp_mst_message_state_byte_0x4e < SINK_REVISION_LIMIT)
                    msg.s.slot[entry].byte0_bits4_6 = 3;
                else
                    msg.s.slot[entry].byte0_bits4_6 = 2;
                if (dp_mst_message_state_byte_0x4b & 1)
                    msg.s.slot[entry].byte1_bit7 = 1;
                else
                    msg.s.slot[entry].byte1_bit7 = 0;
                msg.s.slot[entry].byte1_bit6 = 1;
                msg.s.slot[entry].byte1_bit5 = 0;
                msg.s.slot[entry].byte2 = dp_mst_message_state_byte_0x4e;
                dp_tx_aux_request_copy(DP_TX_OUTPUT_0, AUX_CMD_READ, SINK_ADDR_0x030, 0xf, sink_bytes);
                for (i = 0; i < 16; i++)
                    msg.bytes[entry * ENTRY_SIZE + ENTRY_DATA_OFFSET + i] = sink_bytes[i];
                msg.s.slot[entry + 1].prev_last_high = 0;
                msg.s.slot[entry + 1].prev_last_low = 0;
                dp_mst_ctl_reg_blocks[dp_mst_message_state_port][dp_mst_dpcd_addresses[MST_ADDR_INDEX_0x205]] |= 1;
                length += FULL_ENTRY_BYTES;
            } else {
                msg.s.slot[entry].byte0_bit7 = 0;
                msg.s.slot[entry].byte0_bits4_6 = 0;
                msg.s.slot[entry].byte0_bits0_3 = 1;
                msg.s.slot[entry].byte1_bit7 = 0;
                msg.s.slot[entry].byte1_bit6 = 0;
                msg.s.slot[entry].byte1_bit5 = 0;
                msg.s.slot[entry].byte2 = 0;
                for (i = 0; i < 16; i++)
                    msg.bytes[entry * ENTRY_SIZE + ENTRY_DATA_OFFSET + i] = 0;
                msg.s.slot[entry + 1].prev_last_high = 0;
                msg.s.slot[entry + 1].prev_last_low = 0;
                dp_mst_ctl_reg_blocks[dp_mst_message_state_port][dp_mst_dpcd_addresses[MST_ADDR_INDEX_0x205]] &= ~1;
                length += FULL_ENTRY_BYTES;
            }
        }
    }

    /* Phase 6. */
    dp_mst_send_reply(&msg, MST_QUEUE_REPLY, MST_DIRECTION_DOWN, MST_REPLY_LINK_ADDRESS, length);
    dp_mst_message_state_addressed_flag = 1;
    dp_mst_message_state = 0;
}
