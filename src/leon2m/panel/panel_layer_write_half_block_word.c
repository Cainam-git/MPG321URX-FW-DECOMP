/* panel_layer_write_half_block_word  (FUN_a010baac)
 *
 * Write a word of a layer's register block in one output half.
 * Name basis: descriptive - block table 0x19AED8 or 0x19AECC by selector; unused
 *
 * Matching notes
 * --------------
 * FUN_a010baac, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
/* Channel layer register blocks: first half 0xD0030100..0xD0030300, second half 0xD0038100..0xD0038300. */
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

/*
 * Store value in word 'word' of the register block of channel 'channel' in one half only:
 * half 0 is the first table, any other half the second. The channel is not range checked.
 */
void panel_layer_write_half_block_word(unsigned char channel, unsigned char half, unsigned int word, unsigned int value)
{
    if (half == 0)
        panel_channel_blocks_first_half[channel][word] = value;
    else
        panel_channel_blocks_second_half[channel][word] = value;
}
