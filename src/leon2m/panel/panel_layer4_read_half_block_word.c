/* panel_layer4_read_half_block_word  (FUN_a010db74)
 *
 * Read a word of the fourth layer's register block in one output half.
 * Returns: word
 * Name basis: descriptive - block table 0x19AEC4 or 0x19AEBC by selector; unused
 *
 * Matching notes
 * --------------
 * FUN_a010db74 (leon2m 0xa010db74-0xa010dbc4, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Both tables hold volatile word pointers.
 */
extern volatile unsigned int *const panel_layer4_blocks_first_half[];
extern volatile unsigned int *const panel_layer4_blocks_second_half[];

/*
 * Return word word_index of the register block of the channel. half 0 picks the block from the first half's
 * table, any other half the block from the second half's table. A channel above 1 reads the block of channel 0.
 * No routine in the image calls it.
 */
unsigned int panel_layer4_read_half_block_word(unsigned char channel, unsigned char half, unsigned int word_index)
{
    volatile unsigned int *block;

    if (channel > 1)
        channel = 0;
    if (half == 0)
        block = panel_layer4_blocks_first_half[channel];
    else
        block = panel_layer4_blocks_second_half[channel];
    return block[word_index];
}
