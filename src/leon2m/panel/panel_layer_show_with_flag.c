/* panel_layer_show_with_flag  (FUN_a010eca8)
 *
 * Mark one of the three layers as shown and write its two position words with a flag.
 * Name basis: descriptive - bit 1 of record byte +0x3E; word 9 of the two register blocks; unused
 *
 * Matching notes
 * --------------
 * FUN_a010eca8 (leon2m 0xa010eca8-0xa010ed50, 168 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch selecting the context pointer (as panel_layer_hide); each sum is computed into its own int
 * local before its store, with the context word as the first operand; the line offset is a signed int divided by 32.
 */

/* Layer context record; only the fields used here are named. */
struct layer_context {
    unsigned int word_0x00;
    unsigned int first_half_word;       /* +0x04: base of the word written to the first half's block */
    unsigned int second_half_word;      /* +0x08: base of the word written to the second half's block */
    unsigned short half_0x0c, half_0x0e;
    unsigned char pad10[0x24 - 0x10];
    unsigned char byte_0x24;
    unsigned char pad25[0x3e - 0x25];
    unsigned char flags, pad3f;         /* +0x3e */
};
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[];
extern volatile unsigned int *const panel_channel_blocks_second_half[];

#define LAYER_FLAG_BIT1     2           /* set here, cleared by panel_layer_hide */
#define WORD9_SHOW_FLAG     0x10000000  /* ORed into the offset written to word 9 */

/*
 * Set bit 1 of the layer context's flags, then write word 9 of the layer's register block in each half:
 * the context's first-half word (+4) plus an offset into the first half's block, the second-half word (+8)
 * plus the same offset into the second half's block. The offset is
 * (half_0x0e - 1) * half_0x0c * (byte_0x24 >> 3) / 32 with WORD9_SHOW_FLAG set. panel_layer_hide writes the plain
 * words back without the offset. Channel 1 and 2 have their own context; any other value uses channel 0's.
 * No routine calls it directly.
 */
void panel_layer_show_with_flag(unsigned char channel)
{
    struct layer_context *context;
    int offset, first_half_value, second_half_value;

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
    offset = (int)((context->half_0x0e - 1) * context->half_0x0c * (context->byte_0x24 >> 3)) / 32;
    context->flags |= LAYER_FLAG_BIT1;
    first_half_value = context->first_half_word + (offset | WORD9_SHOW_FLAG);
    panel_channel_blocks_first_half[channel][9] = first_half_value;
    second_half_value = context->second_half_word + (offset | WORD9_SHOW_FLAG);
    panel_channel_blocks_second_half[channel][9] = second_half_value;
}
