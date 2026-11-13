/* panel_layer_read_alt_block_word  (FUN_a010b4fc)
 *
 * Read a word of the second register block set of a layer.
 * Returns: word
 * Name basis: descriptive - block table at 0x19AEF0; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b4fc, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the table holds volatile word pointers; the clamp is 'if (c > 2) c = 0;'.
 */
/* Channel numbers above LAST_CHANNEL (2) mean "all three channels". */
#define LAST_CHANNEL 2

/* Register blocks of the three channels' second set, first half (0xD0030030..0xD0030070). */
extern volatile unsigned int *const panel_layer_alt_blocks_first_half[];

/* Return word 'word' of the first-half register block of channel 'channel'; a channel above 2 reads channel 0. */
unsigned int panel_layer_read_alt_block_word(unsigned char channel, unsigned int word)
{
    if (channel > LAST_CHANNEL)
        channel = 0;
    return panel_layer_alt_blocks_first_half[channel][word];
}
