/* panel_layer_read_block_word  (FUN_a010b5dc)
 *
 * Read a word of the register block of a layer.
 * Returns: word
 * Name basis: descriptive - block table at 0x19AED8; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b5dc, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the table holds volatile word pointers; the clamp is 'if (c > 2) c = 0;'.
 */
/* Channel numbers above LAST_CHANNEL (2) mean "all three channels". */
#define LAST_CHANNEL 2

/* Channel layer register blocks, first half (0xD0030100..0xD0030300). */
extern volatile unsigned int *const panel_channel_blocks_first_half[];

/* Return word 'word' of the first-half register block of channel 'channel'; a channel above 2 reads channel 0. */
unsigned int panel_layer_read_block_word(unsigned char channel, unsigned int word)
{
    if (channel > LAST_CHANNEL)
        channel = 0;
    return panel_channel_blocks_first_half[channel][word];
}
