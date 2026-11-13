/* panel_layer4_hide  (FUN_a010f724)
 *
 * Mark the fourth layer as hidden and write its position words back.
 * Name basis: descriptive - registers 0xD0032280 / 0xD003A280; unused
 *
 * Matching notes
 * --------------
 * FUN_a010f724 (leon2m 0xa010f724-0xa010f7a4, 128 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the context pointer is initialised to channel 0's and replaced for channel 1.
 */
struct layer_context { unsigned int word_0x00, first_half_word, second_half_word; unsigned char pad0c[0x3e - 0xc]; unsigned char flags, pad3f; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

#define LAYER_FLAG_BIT1 2               /* set by panel_layer4_set_position, cleared here */

/*
 * Clear bit 1 of the layer context's flags and write the context's two words (+4 first half, +8 second half)
 * unchanged to the position registers that panel_layer4_set_position writes: channel 0 to 0xD0032280 /
 * 0xD003A280, any other channel to 0xD0032284 / 0xD003A284. Channel 1 uses the second context, every other value
 * the first. No routine in the image calls it.
 */
void panel_layer4_hide(unsigned char channel)
{
    struct layer_context *context = &panel_layer4_context_ch0;

    if (channel == 1)
        context = &panel_layer4_context_ch1;
    context->flags &= ~LAYER_FLAG_BIT1;
    if (channel == 0) {
        *(volatile unsigned int *)0xd0032280 = context->first_half_word;
        *(volatile unsigned int *)0xd003a280 = context->second_half_word;
    } else {
        *(volatile unsigned int *)0xd0032284 = context->first_half_word;
        *(volatile unsigned int *)0xd003a284 = context->second_half_word;
    }
}
