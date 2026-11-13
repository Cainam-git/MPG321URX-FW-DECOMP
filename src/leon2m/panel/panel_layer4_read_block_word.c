/* panel_layer4_read_block_word  (FUN_a010daf8)
 *
 * Read a word of the fourth layer's register block.
 * Returns: word
 * Name basis: descriptive - block table at 0x19AEC4; unused
 *
 * Matching notes
 * --------------
 * FUN_a010daf8 (leon2m 0xa010daf8-0xa010db2c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the table holds volatile word pointers; the clamp is 'if (channel > 1) channel = 0;'.
 */
extern volatile unsigned int *const panel_layer4_blocks_first_half[];

/*
 * Return word word_index of the register block of the given channel (first half's table). The table has two
 * entries; any channel above 1 reads the block of channel 0. No routine in the image calls it.
 */
unsigned int panel_layer4_read_block_word(unsigned char channel, unsigned int word_index)
{
    if (channel > 1)
        channel = 0;
    return panel_layer4_blocks_first_half[channel][word_index];
}
