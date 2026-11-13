/* panel_layer_write_alt_block_word  (FUN_a010b450)
 *
 * Write a word of the second register block set of one layer, or of all three.
 * Name basis: descriptive - block tables at 0x19AEF0 / 0x19AEE4; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b450, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: one separate if/else statement per table with an unsigned int loop counter.
 */
/* Channel numbers above LAST_CHANNEL (2) mean "all three channels". */
#define LAST_CHANNEL 2

/* Register blocks of the three channels' second set: first half 0xD0030030..0xD0030070, second half 0xD0038030..0xD0038070. */
extern volatile unsigned int *const panel_layer_alt_blocks_first_half[];
extern volatile unsigned int *const panel_layer_alt_blocks_second_half[];

/*
 * Store value in word 'word' of the register block of channel 'channel' in both halves (first and second
 * table). A channel above 2 writes the word in all three blocks of both tables.
 */
void panel_layer_write_alt_block_word(unsigned char channel, unsigned int word, unsigned int value)
{
    unsigned int i;

    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_layer_alt_blocks_first_half[i][word] = value;
    } else
        panel_layer_alt_blocks_first_half[channel][word] = value;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_layer_alt_blocks_second_half[i][word] = value;
    } else
        panel_layer_alt_blocks_second_half[channel][word] = value;
}
