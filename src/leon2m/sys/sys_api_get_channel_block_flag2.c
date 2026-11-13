/* sys_api_get_channel_block_flag2  (FUN_a0148c94)
 *
 * Return flag bit 2 of the register block that a channel is mapped to.
 * Returns: 0 or 1
 * Name basis: descriptive - prints 'SYS remapping channel OOR' for channels above 3; used by the input window
 *   update
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148c94 @ 0xa0148c94 (-mcpu=v8 -O3 -g)
 * Same code shape as sys_api_get_channel_port_flag.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };
extern struct channel_record channel_records[4];
extern int dbg_printf();                     /* formatted output (vsnprintf) */
extern unsigned char input_block_get_status_bit2(unsigned char);

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

/* Return input_block_get_status_bit2 for the port of channel ch (status word bits 12..15). A channel
 * above 3 prints "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_get_channel_block_flag2(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return input_block_get_status_bit2((channel_records[i].status_word >> 12) & 0xf);
}
