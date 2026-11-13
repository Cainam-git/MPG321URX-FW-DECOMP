/* panel_layer4_write_block_word  (FUN_a010c4a0)
 *
 * Write a word of the fourth layer's register blocks.
 * Name basis: descriptive - block tables at 0x19AEC4 / 0x19AEBC; unused
 *
 * Matching notes
 * --------------
 * FUN_a010c4a0, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: one separate if/else statement per table with an unsigned int loop counter.
 */
/* Channel numbers above LAST_LAYER4_CHANNEL (1) mean "both channels". */
#define LAST_LAYER4_CHANNEL 1

/* Fourth-layer register blocks: first half 0xD0032028 / 0xD0032098, second half 0xD003A028 / 0xD003A098. */
extern volatile unsigned int *const panel_layer4_blocks_first_half[];
extern volatile unsigned int *const panel_layer4_blocks_second_half[];

/*
 * Store value in word 'word' of the fourth-layer register block of channel 'channel' in both halves.
 * A channel above 1 writes the word in both blocks of both tables.
 */
void panel_layer4_write_block_word(unsigned char channel, unsigned int word, unsigned int value)
{
    unsigned int i;

    if (channel > LAST_LAYER4_CHANNEL) {
        for (i = 0; i <= LAST_LAYER4_CHANNEL; i++)
            panel_layer4_blocks_first_half[i][word] = value;
    } else
        panel_layer4_blocks_first_half[channel][word] = value;
    if (channel > LAST_LAYER4_CHANNEL) {
        for (i = 0; i <= LAST_LAYER4_CHANNEL; i++)
            panel_layer4_blocks_second_half[i][word] = value;
    } else
        panel_layer4_blocks_second_half[channel][word] = value;
}
