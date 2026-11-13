/* panel_layer_set_word3d_bit24  (FUN_a010d068)
 *
 * Set or clear bit 24 of word 0x3D of a channel layer's register blocks.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010d068, flags -mcpu=v8 -O3 -g. Same SET form as panel_layer_clear_word0_bit0_or_bit4 and panel_channel_layer_set_gains.
 * Source form: ch is an unsigned int holding (unsigned char)c, computed once before the 'on' test; the first
 * channel parameter of the static helper is unsigned int, the second stays unsigned char and is masked again
 * from the parameter c.
 */
/* Channel layer register blocks: first half 0xD0030100..0xD0030300, second half 0xD0038100..0xD0038300. */
struct channel_block { unsigned int words[0x40]; };
extern volatile struct channel_block *const panel_channel_blocks_first_half[3];
extern volatile struct channel_block *const panel_channel_blocks_second_half[3];

#define LAST_CHANNEL 2          /* channel numbers above this mean "all three channels" */
#define BLOCK_WORD_3D 0x3d      /* offset 0xF4 */
#define BLOCK_WORD_3D_BIT24 0x1000000

/* Store val in field f of the block of channel n; a channel above 2 stores it in all three blocks of table tab. */
#define SET(tab, n, f, val) do { if ((n) > LAST_CHANNEL) { unsigned int i; for (i = 0; i <= LAST_CHANNEL; i++) tab[i]->f = val; } \
                                 else tab[n]->f = val; } while (0)

static void set_both_halves(unsigned int channel_wide, unsigned char channel, unsigned int value)
{
    SET(panel_channel_blocks_first_half, channel_wide, words[BLOCK_WORD_3D], value);
    SET(panel_channel_blocks_second_half, channel, words[BLOCK_WORD_3D], value);
}

/*
 * Set (on != 0) or clear (on == 0) bit 24 of word 0x3D (offset 0xF4) of the register block of the channel,
 * in both halves. The old value comes from the first-half block (channel 0 when the channel is above 2).
 * A channel above 2 writes all three blocks. Nothing calls this routine.
 */
void panel_layer_set_word3d_bit24(unsigned short channel_in, unsigned char on)
{
    unsigned int channel = (unsigned char)channel_in;
    unsigned int word;

    if (on == 0) {
        {
            unsigned char block_index = channel > LAST_CHANNEL ? 0 : channel_in;
            word = panel_channel_blocks_first_half[block_index]->words[BLOCK_WORD_3D];
        }
        set_both_halves(channel, channel_in, word & ~BLOCK_WORD_3D_BIT24);
    } else {
        {
            unsigned char block_index = channel > LAST_CHANNEL ? 0 : channel_in;
            word = panel_channel_blocks_first_half[block_index]->words[BLOCK_WORD_3D];
        }
        set_both_halves(channel, channel_in, word | BLOCK_WORD_3D_BIT24);
    }
}
