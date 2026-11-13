/* panel_layer_clear_word0_bit0_or_bit4  (FUN_a010f50c)
 *
 * Clear bit 0 (argument 0) or bit 4 (otherwise) of block word 0 of a channel layer, or of all three.
 * Note: The word is read from the first half's block and written to both halves. Nothing calls it.
 * Name basis: descriptive - bit 0 or bit 4 of block word 0 through the two block tables
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010f50c @ 0xa010f50c-0xa010f65c (336 bytes). Flags -mcpu=v8 -O3 -g.
 * Source form: both writes are in a static helper clear_in_both(first_half_channel, second_half_channel, value)
 * with unsigned char channel parameters, called once per arm with (channel, channel_arg, word & mask); the second
 * half's channel is the narrowed parameter channel_arg, which the firmware masks again ('and %o0, 0xff') for the
 * second table's test.
 */
/* Register block reached through the two tables; only the first word is written here. */
struct layer_block { unsigned int w0, w4, w8, wc, w10, w14, w18; };
extern volatile struct layer_block *const panel_layer_alt_blocks_first_half[3];
extern volatile struct layer_block *const panel_layer_alt_blocks_second_half[3];

#define BLOCK_WORD0_BIT0  0x01          /* cleared when 'on' is 0 */
#define BLOCK_WORD0_BIT4  0x10          /* cleared when 'on' is not 0 */

/* Field f of block n of table tab, or of blocks 0..2 when n > 2. */
#define SET(tab, n, f, val) if ((n) > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } \
                            else tab[n]->f = val

static void write_both_halves(unsigned char first_half_channel, unsigned char second_half_channel, unsigned int value)
{
    SET(panel_layer_alt_blocks_first_half, first_half_channel, w0, value);
    SET(panel_layer_alt_blocks_second_half, second_half_channel, w0, value);
}

/*
 * Clear one bit of word 0 in the register blocks of the channel, in both halves: bit 0 when on is 0, bit 4 when
 * on is not 0. The word is read once from the first half's block (channel above 2 reads block 0) and the result
 * is written to both halves; a channel above 2 writes the blocks of channels 0 to 2.
 */
void panel_layer_clear_word0_bit0_or_bit4(unsigned short channel_arg, unsigned char on)
{
    unsigned char channel = channel_arg;
    unsigned int word0;

    {
        unsigned char index = channel > 2 ? 0 : channel_arg;
        word0 = panel_layer_alt_blocks_first_half[index]->w0;
    }
    if (on == 0)
        write_both_halves(channel, channel_arg, word0 & ~BLOCK_WORD0_BIT0);
    else
        write_both_halves(channel, channel_arg, word0 & ~BLOCK_WORD0_BIT4);
}
