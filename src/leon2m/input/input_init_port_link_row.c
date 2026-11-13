/* input_init_port_link_row  (FUN_a012b458)
 *
 * Fill a port's link row from the saved settings and send it to the input processor.
 * Name basis: derived - row at 0xA802D8AE from the settings block; mailbox commands 0x20 and 0x2E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b458 @ 0xa012b458-0xa012b7b8 (216 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the choice for row byte 0 is written with the two helpers at_most_2 / above_2 (above_2 = !at_most_2) and a
 *    '!= 1' test: the firmware's block order after the 'cmp n, 2; bgu' at 0xa012b498 needs the compiler's guess
 *    'a test for equality with a non-zero value fails' on that jump (any guess of 10 % to 39 % gives the
 *    firmware order, the 50 % of a plain 'selection <= 2' test does not). The '== 1' test of bit 25 uses the
 *    same comparison style;
 *  - the settings record is packed with 16-bit bit-fields for the halfwords at +0x2D and +0x2F;
 *  - the unused array flag_copy and its four stores stay in the source.
 */

/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. Each of the fields +0x2C..+0x33
   holds a nibble or a byte per port; inside it, one bit or a 2-bit field per selection. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    union { unsigned int word; unsigned char bytes[4]; } word_0x00;
    unsigned char unused_04[0x2c - 4];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the selection n of that port */
    unsigned short halfword_0x2d:16;    /* +0x2D: a byte per port, each with a 2-bit field per selection */
    unsigned short halfword_0x2f:16;    /* +0x2F: same layout */
    unsigned char byte_0x31, byte_0x32, byte_0x33;      /* one nibble per port */
    unsigned char unused_34[0x50 - 0x34];
};

/* A port link row (0x16 bytes at port_link_rows), the settings of one port as sent to the input processor. */
struct port_link_row {
    unsigned char byte_0x00, byte_0x01, byte_0x02;
    unsigned char byte_0x03;            /* the multi-stream value (input_set_port_link_byte3) */
    unsigned char byte_0x04, byte_0x05;
    unsigned char byte_0x06;            /* the DSC flag (dp_set_port_dsc_support) */
    unsigned char byte_0x07;
    unsigned char byte_0x08, byte_0x09, byte_0x0a, byte_0x0b;   /* 8, 0x0A, 0x0B: input_set_port_link_tail_bytes */
    unsigned char byte_0x0c, byte_0x0d, byte_0x0e, byte_0x0f, byte_0x10, byte_0x11;
    unsigned short halfword_0x12;
    unsigned char byte_0x14, byte_0x15;
};
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern unsigned char port_entry2_bus_id, port_entry3_bus_id;
extern int dbg_printf();
extern void ipc_set_dp_rx_config(unsigned char port, unsigned char *row);
extern unsigned char input_port_table_get_type(unsigned int index);
extern void input_port_table_get_link_bytes(unsigned char index, unsigned int *out);
extern unsigned char input_port_table_find_flagged_type2(void);
extern void ipc_set_dp_rx_lane_options(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

#define PORT_TYPE_2 2           /* the only port table type this routine accepts */

/* Four 2-bit values into one byte, the first in the top bits. */
static inline unsigned int pack_order(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return ((a & 3) << 6) | ((b & 3) << 4) | ((c & 3) << 2) | (d & 3);
}
/* Four bits into one nibble, the first in bit 3. */
static inline unsigned char pack_mask(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (a << 3) | (b << 2) | (c << 1) | d;
}
/* Store row bytes 8, 0x0A and 0x0B and send them, with the fifth value, by mailbox command 0x2E (as
   input_set_port_link_tail_bytes does). */
static inline void store_lane_options(unsigned char port, unsigned char order, unsigned char mask,
                                      unsigned char flag11, unsigned char last)
{
    port_link_rows[port].byte_0x08 = order;
    port_link_rows[port].byte_0x0a = mask;
    port_link_rows[port].byte_0x0b = flag11;
    ipc_set_dp_rx_lane_options(port, order, mask, flag11, last);
}


static unsigned char at_most_2(unsigned char selection)
{
    return selection <= 2;
}

static unsigned char above_2(unsigned char selection)
{
    return !at_most_2(selection);
}

/*
 * Build the link row of input port 0 or 1 from the device settings and the port table, and send it to the
 * input processor.
 *
 *   port  0 or 1; startup_init_input_ports calls this once for each, in the order given by bit 25 of
 *         settings word +0
 *
 * Phases:
 *   1. Row from the settings. With n = nibble `port` of settings byte +0x2C (the selection), the row gets the
 *      same bytes 0, 1, 2, 6 and 7 that input_set_port_link_field_first loads: byte 2 = n; byte 0 = 2-bit field
 *      n of the port's byte in halfword +0x2F, or for n above 2 nibble `port` of byte +0x31; byte 1 = 2-bit
 *      field n of the port's byte in halfword +0x2D; bytes 7 and 6 = bit n of nibble `port` of bytes +0x32 and
 *      +0x33. Port 0 also takes byte 3 from bit 0 of settings byte +0 (bit 24 of the word). Byte 9 = bit 25 and
 *      byte 0x0F = bit 27 of settings word +0. Fixed values: byte 8 = 0x1B, bytes 4, 5, 0x0B..0x0D = 0,
 *      bytes 0x0E, 0x10, 0x14 = 1, halfword 0x12 = 600. Bytes 0x0A, 0x11 and 0x15 keep their old values.
 *      A copy of the row goes out with ipc_set_dp_rx_config (mailbox command 0x20).
 *   2. The port's entry in the port table: the bus id of port entry 2 (port 0) or 3 (port 1). An entry that is
 *      not of type 2 prints "The relationship between interfaceport and link is error!!!!" and stays in an
 *      endless loop.
 *   3. Bytes 8, 0x0A and 0x0B from bytes +0x12..+0x15 of that entry, read as one word:
 *      byte 8 = four 2-bit values pos0..pos3 from bits 23..16 (port table byte +0x13, in the same order);
 *      byte 0x0A = a nibble with bit (3 - pos k) = bit (15 - k) of the word, k = 0..3;
 *      byte 0x0B = bit 11 of the word.
 *      They are stored and sent with ipc_set_dp_rx_lane_options (mailbox command 0x2E); the fifth value is 1
 *      minus bit `index` of the number input_port_table_find_flagged_type2 returns.
 */
void input_init_port_link_row(unsigned char port)
{
    unsigned int order_bytes[2];
    unsigned char flag_copy[4] = {0};
    unsigned char mask_bits[4] = {0};
    struct port_link_row row;
    unsigned int order_word;
    unsigned char selection, index, order, flag11, flagged_bit, bit25;
    unsigned int pos0, pos1, pos2, pos3;
    unsigned char mask;
    unsigned char flag0, flag1, flag2, flag3;

    /* 1. The row from the settings of the port's selection. */
    selection = (device_settings.selection_nibbles >> (port * 4)) & 0xf;
    port_link_rows[port].byte_0x02 = selection;
    port_link_rows[port].byte_0x00 = (above_2(selection) != 1) ? ((unsigned char)(device_settings.halfword_0x2f >> (port * 8)) >> (selection * 2)) & 3
                                        : (device_settings.byte_0x31 >> (port * 4)) & 0xf;
    port_link_rows[port].byte_0x01 = ((unsigned char)(device_settings.halfword_0x2d >> (port * 8)) >> (selection * 2)) & 3;
    port_link_rows[port].byte_0x07 = ((device_settings.byte_0x32 >> (port * 4)) & 0xf) >> selection & 1;
    port_link_rows[port].byte_0x06 = ((device_settings.byte_0x33 >> (port * 4)) & 0xf) >> selection & 1;
    port_link_rows[port].byte_0x03 = port == 0 ? device_settings.word_0x00.bytes[0] & 1 : 0;
    port_link_rows[port].byte_0x08 = 0x1b;
    port_link_rows[port].byte_0x04 = 0;
    port_link_rows[port].byte_0x05 = 0;
    bit25 = (device_settings.word_0x00.word >> 25) & 1;
    if (bit25 == 1)
        port_link_rows[port].byte_0x09 = 1;
    else
        port_link_rows[port].byte_0x09 = 0;
    port_link_rows[port].byte_0x0e = 1;
    port_link_rows[port].byte_0x0f = (device_settings.word_0x00.word >> 27) & 1;
    port_link_rows[port].byte_0x0b = 0;
    port_link_rows[port].byte_0x0c = 0;
    port_link_rows[port].byte_0x0d = 0;
    port_link_rows[port].byte_0x10 = 1;
    port_link_rows[port].halfword_0x12 = 600;
    port_link_rows[port].byte_0x14 = 1;
    row = port_link_rows[port];
    ipc_set_dp_rx_config(port, (unsigned char *)&row);

    /* 2. The port table entry of the port; it must be of type 2. */
    index = 0;
    if (port == 0)
        index = port_entry2_bus_id;
    else if (port == 1)
        index = port_entry3_bus_id;
    if (input_port_table_get_type(index) != PORT_TYPE_2) {
        dbg_printf("\033[1;31mThe relationship between interfaceport and link is error!!!!\r\n\033[m");
        for (;;) {
            __asm__ volatile ("nop");
            __asm__ volatile ("nop");
        }
    }

    /* 3. Row bytes 8, 0x0A and 0x0B from the entry's bytes +0x12..+0x15. */
    input_port_table_get_link_bytes(index, order_bytes);
    order_word = order_bytes[0];
    pos0 = (order_word >> 22) & 3;
    pos1 = (order_word >> 20) & 3;
    pos2 = (order_word >> 18) & 3;
    pos3 = (order_word >> 16) & 3;
    flag0 = (order_word >> 15) & 1;
    flag1 = (order_word >> 14) & 1;
    flag2 = (order_word >> 13) & 1;
    flag3 = (order_word >> 12) & 1;
    flag_copy[0] = flag0;           /* never read */
    flag_copy[1] = flag1;
    flag_copy[2] = flag2;
    flag_copy[3] = flag3;
    /* Each flag moves to the place its 2-bit value names. */
    mask_bits[pos0] = flag0;
    mask_bits[pos1] = flag1;
    mask_bits[pos2] = flag2;
    mask_bits[pos3] = flag3;
    order = pack_order(pos0, pos1, pos2, pos3);
    flag11 = (order_word >> 11) & 1;
    mask = pack_mask(mask_bits[0], mask_bits[1], mask_bits[2], mask_bits[3]);
    flagged_bit = (input_port_table_find_flagged_type2() >> index) & 1;
    store_lane_options(port, order, mask, flag11, flagged_bit ^ 1);
}
