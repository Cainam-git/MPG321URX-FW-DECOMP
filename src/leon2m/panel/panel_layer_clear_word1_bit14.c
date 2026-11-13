/* panel_layer_clear_word1_bit14  (FUN_a010ef64)
 *
 * Clear bit 14 of word 1 in the register blocks of one layer, or of all three.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a010ef64 (leon2m 0xa010ef64-0xa010f064, 256 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch selecting the context pointer; separate if (channel > 2) loop/else statements per table.
 */
struct layer_context { unsigned char pad0[0x3e]; unsigned char flags; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

#define LAYER_FLAG_BIT0 1               /* cleared here; set means the position offset is subtracted (panel_layer4_set_window_position) */

/*
 * Clear bit 0 of the layer context's flags and bit 14 of word 1 in the register blocks of the channel, in both
 * halves. The new word is taken from the first half's block of the channel and written to both halves. A
 * channel above 2 (which has no context of its own and uses channel 0's) writes the blocks of channels 0 to 2.
 * No routine in the image calls it.
 */
void panel_layer_clear_word1_bit14(unsigned char channel)
{
    struct layer_context *context;
    unsigned int word1, i;
    unsigned char source_channel;
    switch (channel) {
    case 1:
        context = &panel_layer_context_ch1;
        break;
    case 2:
        context = &panel_layer_context_ch2;
        break;
    default:
        context = &panel_layer_context_ch0;
        break;
    }
    context->flags &= ~LAYER_FLAG_BIT0;
    source_channel = channel;
    if (channel > 2)
        source_channel = 0;
    word1 = panel_channel_blocks_first_half[source_channel][1] & ~0x4000u;
    if (channel > 2) {
        for (i = 0; i <= 2; i++)
            panel_channel_blocks_first_half[i][1] = word1;
    } else
        panel_channel_blocks_first_half[channel][1] = word1;
    if (channel > 2) {
        for (i = 0; i <= 2; i++)
            panel_channel_blocks_second_half[i][1] = word1;
    } else
        panel_channel_blocks_second_half[channel][1] = word1;
}
