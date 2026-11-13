/* panel_layer_write_block_word  (FUN_a010b530)
 *
 * Write a word of the register blocks of one layer, or of all three.
 * Name basis: descriptive - block tables at 0x19AED8 / 0x19AECC; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b530, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: one separate if/else statement per table with an unsigned int loop counter.
 */
/* Channel numbers above LAST_CHANNEL (2) mean "all three channels". */
#define LAST_CHANNEL 2

/* Channel layer register blocks: first half 0xD0030100..0xD0030300, second half 0xD0038100..0xD0038300. */
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

/*
 * Store value in word 'word' of the register block of channel 'channel' in both halves. A channel above 2
 * writes the word in all three blocks of both tables.
 */
void panel_layer_write_block_word(unsigned char channel, unsigned int word, unsigned int value)
{
    unsigned int i;

    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_first_half[i][word] = value;
    } else
        panel_channel_blocks_first_half[channel][word] = value;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_second_half[i][word] = value;
    } else
        panel_channel_blocks_second_half[channel][word] = value;
}
