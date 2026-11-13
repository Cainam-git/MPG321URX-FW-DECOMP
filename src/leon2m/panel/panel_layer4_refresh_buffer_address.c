/* panel_layer4_refresh_buffer_address  (FUN_a01101a8)
 *
 * Recompute the two buffer address words (base >> 5) of the fourth layer and write them.
 * Note: Nothing calls it.
 * Name basis: descriptive - registers 0xD0032280 / 0xD003A280 (channel 1: +4) receive the buffer address in
 *   32-byte units
 *
 * Matching notes
 * --------------
 * FUN_a01101a8 (leon2m 0xa01101a8-0xa011023c, 148 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the context pointer is initialised to channel 0's and replaced for channel 1.
 */
struct layer_context { unsigned int base, first_half_word, second_half_word; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

/*
 * Recompute the layer context's two words as panel_layer_refresh_buffer_address does (first = base >> 5; second =
 * (base + ((old second - old first) << 5)) >> 5) and write them to the buffer address registers (they take the
 * buffer address in 32-byte units, base >> 5, not a position): the first-half word
 * to 0xD0032280 and the second-half word to 0xD003A280 for channel 0, to 0xD0032284 and 0xD003A284 for any
 * other channel. Channel 1 uses the second context, every other value the first. No routine in the image
 * calls it.
 */
void panel_layer4_refresh_buffer_address(unsigned char channel)
{
    struct layer_context *context = &panel_layer4_context_ch0;

    if (channel == 1)
        context = &panel_layer4_context_ch1;
    context->second_half_word = (context->base + ((context->second_half_word - context->first_half_word) << 5)) >> 5;
    context->first_half_word = context->base >> 5;
    if (channel == 0) {
        *(volatile unsigned int *)0xd0032280 = context->first_half_word;
        *(volatile unsigned int *)0xd003a280 = context->second_half_word;
    } else {
        *(volatile unsigned int *)0xd0032284 = context->first_half_word;
        *(volatile unsigned int *)0xd003a284 = context->second_half_word;
    }
}
