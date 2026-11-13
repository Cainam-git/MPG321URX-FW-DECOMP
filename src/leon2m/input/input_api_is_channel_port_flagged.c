/* input_api_is_channel_port_flagged  (FUN_a014505c)
 *
 * Return whether the port entry of a channel has its flag bit 7 set.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 7 of halfword +2 of port entries 0 and 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014505c @ 0xa014505c-0xa014512c (52 words).
 * Source form: keep remap() as a switch over 0..3 returning the same value, with -1 for any other value.
 * Source form: keep the caller storing remap() in an unsigned char and testing > 3.
 * Source form: keep the & 0xff mask as part of the argument to input_port_entry_get_flag_bit7().
 */
struct channel_record {
    unsigned int word0;
    unsigned char rest[0x74];
};
extern struct channel_record channel_records[4];

struct port_record {
    unsigned char bytes[42];
};
extern struct port_record port_records[];

extern int dbg_printf();
extern int input_port_id_to_entry_index(unsigned char);
extern unsigned char input_port_entry_get_flag_bit7(unsigned char);

static int remap(int channel)
{
    switch (channel) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Return 1 when the port entry selected by the channel record has flag bit 7 set, else 0.
 *
 * channel is a channel number. 0..3 select channel_records[channel]; any other value prints
 * "SYS remapping channel OOR\r\n" and uses channel 0.
 *
 * Bits 12..15 of channel_records[channel].word0 select the port record. Byte 0xa of that port
 * record is converted by input_port_id_to_entry_index(); the converted value is masked to one
 * byte and tested by input_port_entry_get_flag_bit7().
 */
unsigned char input_api_is_channel_port_flagged(unsigned char channel)
{
    unsigned char flagged = 0;
    unsigned char channel_index = remap(channel);
    /* remap() returns -1 for an out-of-range channel; stored in unsigned char it is > 3. */
    if (channel_index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); channel_index = 0; }
    if (input_port_entry_get_flag_bit7(input_port_id_to_entry_index(port_records[(channel_records[channel_index].word0 >> 12) & 0xf].bytes[0xa]) & 0xff))
        flagged = 1;
    return flagged & 1;
}
