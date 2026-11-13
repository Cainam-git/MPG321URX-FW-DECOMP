/* sys_api_get_channel_port_flag_alt  (FUN_a01485e0)
 *
 * Return the bit of the port mask at 0xA802CBD3 for the port of a channel.
 * Returns: 0 or 1
 * Name basis: descriptive - twin of sys_api_get_channel_port_flag
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01485e0 @ 0xa01485e0 (-mcpu=v8 -O3 -g)
 * Called from APPGetFRCMode. Source form: remap is an inlined static helper returning int.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };
extern struct channel_record channel_records[4];
extern int dbg_printf();                     /* formatted output (vsnprintf) */
extern unsigned char input_get_port_mask_bit_alt(unsigned char);   /* bit n of byte 0xA802CBD3 */

/* Return ch for 0..3, else -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Return the bit of the byte at 0xA802CBD3 that belongs to the port of channel ch. input_match_port_mode
 * sets that bit from bit 7 of the port's status halfword. A channel above 3 prints
 * "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_get_channel_port_flag_alt(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return input_get_port_mask_bit_alt((channel_records[i].status_word >> 12) & 0xf);
}
