/* panel_layer_refresh_buffer_address  (FUN_a01100a4)
 *
 * Recompute the two buffer address words (base >> 5) of a channel layer and write them.
 * Note: Nothing calls it.
 * Name basis: descriptive - word 9 of the layer's register block in each half receives the buffer address in
 *   32-byte units
 *
 * Matching notes
 * --------------
 * FUN_a01100a4 (leon2m 0xa01100a4-0xa01101a8, 260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch selecting the context pointer (as panel_layer_hide); the flag if/else is written out for each
 * register.
 */
struct layer_context { unsigned int base, first_half_word, second_half_word; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

#define WORD9_FLAG_CH1 0x4000000
#define WORD9_FLAG_CH2 0x8000000

/*
 * Recompute the layer context's two words from its base (+0x00) and write them to word 9 of the layer's
 * register block in the first and in the second half. The first-half word becomes base >> 5; the second-half
 * word becomes (base + ((old second-half word - old first-half word) << 5)) >> 5, so the distance between the two
 * words is kept. Channel 1 ORs WORD9_FLAG_CH1 and channel 2 WORD9_FLAG_CH2 into both values written. Channel 1
 * and 2 have their own context; any other value uses channel 0's. No routine in the image calls it.
 */
void panel_layer_refresh_buffer_address(unsigned char channel)
{
    struct layer_context *context;
    unsigned int second_half_base, value;

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
    second_half_base = context->base + ((context->second_half_word - context->first_half_word) << 5);
    context->first_half_word = context->base >> 5;
    value = context->first_half_word;
    if (channel == 1)
        value |= WORD9_FLAG_CH1;
    else if (channel == 2)
        value |= WORD9_FLAG_CH2;
    panel_channel_blocks_first_half[channel][9] = value;
    context->second_half_word = second_half_base >> 5;
    value = context->second_half_word;
    if (channel == 1)
        value |= WORD9_FLAG_CH1;
    else if (channel == 2)
        value |= WORD9_FLAG_CH2;
    panel_channel_blocks_second_half[channel][9] = value;
}
