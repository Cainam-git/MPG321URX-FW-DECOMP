/* panel_layer_hide  (FUN_a010ed50)
 *
 * Mark a layer as hidden and write its two position words back.
 * Name basis: descriptive - clears bit 1 of record byte +0x3E; unused
 *
 * Matching notes
 * --------------
 * FUN_a010ed50 (leon2m 0xa010ed50-0xa010edbc, 108 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch selecting the context pointer.
 */
struct layer_context { unsigned int word_0x00, first_half_word, second_half_word; unsigned char pad0c[0x3e - 0xc]; unsigned char flags, pad3f; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

#define LAYER_FLAG_BIT1 2               /* set by panel_layer_show_with_flag, cleared here */

/*
 * Clear bit 1 of the layer context's flags and write the context's two words (+4 first half, +8 second half)
 * unchanged to word 9 of the layer's register block in the first and in the second half. Channel 1 and 2 have
 * their own context; any other value uses channel 0's. No routine in the image calls it.
 */
void panel_layer_hide(unsigned char channel)
{
    struct layer_context *context;
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
    context->flags &= ~LAYER_FLAG_BIT1;
    panel_channel_blocks_first_half[channel][9] = context->first_half_word;
    panel_channel_blocks_second_half[channel][9] = context->second_half_word;
}
