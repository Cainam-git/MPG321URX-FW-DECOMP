/* panel_layer4_write_half_block_word  (FUN_a010db2c)
 *
 * Write a word of the fourth layer's register block in one output half.
 * Name basis: descriptive - block table 0x19AEC4 or 0x19AEBC by selector; unused
 *
 * Matching notes
 * --------------
 * FUN_a010db2c (leon2m 0xa010db2c-0xa010db74, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Both tables hold volatile word pointers.
 */
extern volatile unsigned int *const panel_layer4_blocks_first_half[];
extern volatile unsigned int *const panel_layer4_blocks_second_half[];

/*
 * Store value in word word_index of the register block of the channel. half 0 picks the block from the first
 * half's table, any other half the block from the second half's table. The channel is not range-checked here
 * (the read routines clamp it). No routine in the image calls it.
 */
void panel_layer4_write_half_block_word(unsigned char channel, unsigned char half, unsigned int word_index, unsigned int value)
{
    if (half == 0)
        panel_layer4_blocks_first_half[channel][word_index] = value;
    else
        panel_layer4_blocks_second_half[channel][word_index] = value;
}
