/* panel_layer4_set_position  (FUN_a010f65c)
 *
 * Write the two position words of the fourth layer with a line offset.
 * Name basis: descriptive - registers 0xD0032280 / 0xD003A280; unused
 *
 * Matching notes
 * --------------
 * FUN_a010f65c (leon2m 0xa010f65c-0xa010f724, 200 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the offset is an int local; the | 0x80000000 is written in each register expression.
 */
struct layer_context {
    unsigned int word_0x00, first_half_word, second_half_word;      /* +0x00, +0x04, +0x08 */
    unsigned short half_0x0c, half_0x0e;
    unsigned char pad10[0x24 - 0x10];
    unsigned char byte_0x24;
    unsigned char pad25[0x3e - 0x25];
    unsigned char flags, pad3f;         /* +0x3e */
};
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

#define LAYER_FLAG_BIT1  2              /* set here, cleared by panel_layer4_hide */
#define POSITION_FLAG    0x80000000     /* ORed into the offset written to the position register */

/*
 * Set bit 1 of the layer context's flags and write the position word of the layer to the first and to the
 * second set's register: channel 0 to 0xD0032280 / 0xD003A280, any other channel to 0xD0032284 / 0xD003A284.
 * Each word is the context's first-half word (+4) or second-half word (+8) plus an offset,
 * (half_0x0e - 1) * half_0x0c * (byte_0x24 >> 3) / 32, with POSITION_FLAG set. Channel 1 uses the second
 * context, every other value the first. panel_layer4_hide writes the plain words back. No routine in the image
 * calls it.
 */
void panel_layer4_set_position(unsigned char channel)
{
    struct layer_context *context = &panel_layer4_context_ch0;
    int offset;

    if (channel == 1)
        context = &panel_layer4_context_ch1;
    offset = (int)((context->half_0x0e - 1) * context->half_0x0c * (context->byte_0x24 >> 3)) / 32;
    context->flags |= LAYER_FLAG_BIT1;
    if (channel == 0) {
        *(volatile unsigned int *)0xd0032280 = context->first_half_word + (offset | POSITION_FLAG);
        *(volatile unsigned int *)0xd003a280 = context->second_half_word + (offset | POSITION_FLAG);
    } else {
        *(volatile unsigned int *)0xd0032284 = context->first_half_word + (offset | POSITION_FLAG);
        *(volatile unsigned int *)0xd003a284 = context->second_half_word + (offset | POSITION_FLAG);
    }
}
