/* input_apply_8051_port_flags  (FUN_a002fae0)
 *
 * For each of the 4 port records whose mask matches the 8051 port flags, set its channel control bit.
 * Note: Mask = byte +0x76 of the 0x78-byte port records at 0xA802DF30; channel = bits 12..15 of word +0.
 * Name basis: descriptive - code only; no direct caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002fae0 @ 0xa002fae0, flags -mcpu=v8 -O3 -g.
 * Source form: a record pointer for the +0x76 test and the direct channel_records[i].status_word for the word read
 * give the firmware's [base + off] / [off + base] operand orders.
 */

/* One channel record (0x78 bytes; see docs/RECORDS.md). Only the two fields used here are named. */
struct channel_record {
    unsigned int status_word;                   /* +0: bits 12..15 hold the port of the channel */
    unsigned char pad[0x76 - 4];
    unsigned char port_flags_mask;              /* +0x76: tested against the 8051 port flags */
    unsigned char pad2;
};
extern struct channel_record channel_records[4];
extern unsigned char ipc_read_8051_port_flags(void);
extern void reg_set_channel_ctrl_bit(unsigned char, int);

/*
 * Set bit n of the channel control register (reg_set_channel_ctrl_bit) for each channel whose mask
 * (port_flags_mask) has a bit in common with the 8051 port flags; n is the channel's port number.
 * The flags are read again for every channel.
 */
void input_apply_8051_port_flags(void)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        struct channel_record *rec = &channel_records[i];
        if (ipc_read_8051_port_flags() & rec->port_flags_mask)
            reg_set_channel_ctrl_bit((channel_records[i].status_word >> 12) & 0xf, 1);
    }
}
