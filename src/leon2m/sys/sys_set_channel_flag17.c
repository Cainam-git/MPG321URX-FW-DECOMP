/* sys_set_channel_flag17  (FUN_a01302a4)
 *
 * Write flag bit 17 of a channel record.
 * Name basis: descriptive - channel record word +0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01302a4 @ 0xa01302a4-0xa01302e0 (15 words), flags -mcpu=v8 -O3 -g.
 * Leaf. The record offset is ch * 15 * 8 (sll 4 / sub / sll 3). ch is an unsigned char parameter. The bit is a
 * 1-bit bit-field.
 */
/* Channel record (0x78 bytes): the flag word at +0x70, of which only bit 17 is named here. */
struct channel_record { unsigned char pad[0x70]; unsigned int bits_18_31 : 14, port_bring_up : 1, bits_0_16 : 17; unsigned int pad74; };
extern struct channel_record channel_records[];

/* Set flag bit 17 (CH_PORT_BRING_UP) of channel ch to the low bit of value. Called by sys_api_set_secondary_channel_enable (twice). */
void sys_set_channel_flag17(unsigned char ch, unsigned int value)
{
    channel_records[ch].port_bring_up = value;
}
