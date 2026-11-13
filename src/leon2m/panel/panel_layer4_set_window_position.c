/* panel_layer4_set_window_position  (FUN_a010dbc4)
 *
 * Set the window position of the fourth layer.
 * Name basis: derived - position word with the half offset; word 0 of its register blocks; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010dbc4 @ 0xa010dbc4-0xa010dc8c (200 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: 16-bit bit-fields first_half_position / second_half_position, the low_word union view, and the
 * context selector as a static helper with a default-then-override test (the same form as panel_layer_set_window_position).
 */
/* Layer context record (two copies, one per channel); only the fields used here are named. */
struct layer_context {
    unsigned int word_0x00;
    unsigned char pad4[8];
    unsigned short word_0x0c, word_0x0e;
    unsigned char pad10[4];
    unsigned short half_0x14, half_0x16;
    unsigned int first_half_position:16, second_half_position:16;   /* +0x18, +0x1a */
    unsigned char pad1c[4];
    union { struct { unsigned short low_word, high_word; } h; struct { unsigned int low_word:16, high_word:16; } b; } u20;   /* +0x20, +0x22 */
    unsigned char byte_0x24, byte_0x25, byte_0x26;
    unsigned char pad27[0x17];
    unsigned char flags, pad3f;         /* +0x3e: bit 0 set = the position offset is subtracted */
};
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern volatile unsigned int *panel_layer4_blocks_first_half[], *panel_layer4_blocks_second_half[];
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;

/* Channel 1 has its own context; every other value uses channel 0's. */
static struct layer_context *get_context(unsigned char channel)
{
    struct layer_context *context = &panel_layer4_context_ch0;
    if (channel == 1)
        context = &panel_layer4_context_ch1;
    return context;
}

/*
 * Store a window position in the channel's layer context and write it to word 0 of the channel's register
 * block. half 0 sets the first half's position (+0x18) and writes the block from the first half's table; any
 * other half sets the second half's position (+0x1A), shifted by panel_layer_position_offset (subtracted when
 * flag bit 0 of the context is set, else added), and writes the block from the second half's table.
 * The register word is the position in bits 16..31 and low_word in bits 0..15; low_word is also kept in the
 * context at +0x20.
 */
void panel_layer4_set_window_position(unsigned char channel, unsigned char half, unsigned short position, unsigned short low_word)
{
    struct layer_context *context;
    unsigned int value;

    context = get_context(channel);
    if (half == 0) { context->first_half_position = position; value = position; }
    else {
        context->second_half_position = position;
        if (context->flags & 1) value = position - panel_layer_position_offset; else value = position + panel_layer_position_offset;
    }
    context->u20.h.low_word = low_word;
    value = value << 16 | low_word;
    if (half == 0) panel_layer4_blocks_first_half[channel][0] = value; else panel_layer4_blocks_second_half[channel][0] = value;
}
