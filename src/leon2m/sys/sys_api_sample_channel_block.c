/* sys_api_sample_channel_block  (FUN_a0148bc4)
 *
 * Run the sample accumulation for the block that a channel is mapped to.
 * Name basis: descriptive - forwards to the routine that sums weighted register samples; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148bc4 @ 0xa0148bc4-0xa0148c84 (48 words).
 * Source form: remap is an inlined static helper returning int.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };
extern struct channel_record channel_records[4];
extern int dbg_printf();                     /* formatted output (vsnprintf) */

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

extern void input_block_accumulate_samples(unsigned char, unsigned char);

/* Call input_block_accumulate_samples(port, value), with port = the port of channel ch (status word
 * bits 12..15). A channel above 3 prints "SYS remapping channel OOR" and is treated as channel 0. */
void sys_api_sample_channel_block(unsigned char ch, unsigned char value)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    input_block_accumulate_samples((channel_records[i].status_word >> 12) & 0xf, value);
}
