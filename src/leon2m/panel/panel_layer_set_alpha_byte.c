/* panel_layer_set_alpha_byte  (FUN_a010c390)
 *
 * Store a byte of a layer and write it to bits 16..23 of block word 4.
 * Name basis: descriptive - record byte +0x26; unused
 *
 * Matching notes
 * --------------
 * FUN_a010c390, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the same form as panel_layer_clear_word1_bit14.
 */
/* Per-channel stored settings; only the byte at +0x26 is used here. */
struct layer_context { unsigned char bytes_0x00_to_0x25[0x26]; unsigned char byte_0x26; };

#define LAST_CHANNEL 2          /* channel numbers above this mean "all three channels" */
#define LAYER_WORD_4 4          /* block word written here */

extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

/*
 * Store value in byte +0x26 of the channel's stored settings (channel 1 and 2 have their own record, every
 * other channel number uses the record of channel 0) and in bits 16..23 of word 4 of its register blocks,
 * with bit 0 of that word set. The other bits of word 4 are taken from the first-half block of the channel
 * (channel 0 when the channel is above 2). The new word goes to both halves; a channel above 2 writes all
 * three blocks of both.
 */
void panel_layer_set_alpha_byte(unsigned char channel, unsigned char value)
{
    struct layer_context *context;
    unsigned int word, i;
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
    context->byte_0x26 = value;
    source_channel = channel;
    if (channel > LAST_CHANNEL)
        source_channel = 0;
    word = (panel_channel_blocks_first_half[source_channel][LAYER_WORD_4] & ~0xff0000u) | (value << 16) | 1;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_first_half[i][LAYER_WORD_4] = word;
    } else
        panel_channel_blocks_first_half[channel][LAYER_WORD_4] = word;
    if (channel > LAST_CHANNEL) {
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_second_half[i][LAYER_WORD_4] = word;
    } else
        panel_channel_blocks_second_half[channel][LAYER_WORD_4] = word;
}
