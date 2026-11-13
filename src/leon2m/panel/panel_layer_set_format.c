/* panel_layer_set_format  (FUN_a010c194)
 *
 * Set the pixel format of a channel layer in both output halves.
 * Name basis: derived - bits per pixel and the layer format word; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010c194 @ 0xa010c194, flags -mcpu=v8 -O3 -g.
 * Source form: format and value are unsigned int parameters, read through (unsigned char) casts in the switch and
 * the shift. panel_channel_layer_setup_window holds an inline copy of these steps written with unsigned char
 * parameters; no single form matches both places, so the two are separate bodies. The context is picked by a
 * static helper.
 */

/* Per-channel stored settings; only the three bytes at +0x24..+0x26 are used here. */
struct layer_context {
    unsigned char bytes_0x00_to_0x23[0x24];
    unsigned char bits_per_pixel;   /* +0x24: 8, 16 or 32 */
    unsigned char format;           /* +0x25: format number as passed in */
    unsigned char byte_0x26;        /* +0x26: also held in bits 16..23 of block word 4 */
};
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];

/* Declarations of panel_channel_layer_setup_window, which carries these steps inline; not used here. */
struct panel_timing_row;
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;
extern void panel_layer_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short timer_get_ticks16(void);

#define LAST_CHANNEL 2                  /* channel numbers above this mean "all three channels" */
#define LAYER_WORD_4 4                  /* block word that holds the format */

/* Block word 4: bits 8..23 are rebuilt here, the rest is kept. */
#define WORD4_KEEP_MASK  0xff0000ffu
#define WORD4_BIT0       1              /* set on every write */
#define FORMAT_16BPP     0x100          /* bit 8: a 16-bit format; bits 13..15 tell which one */
#define FORMAT_32BPP     0x200          /* bit 9: a 32-bit format */
#define FORMAT_BIT11     0x800          /* together with bit 9 for format 9 */
#define FORMAT_BIT12     0x1000         /* together with bit 9 for format 8 */
#define FORMAT_16BPP_SUBTYPE(n) ((n) << 13)

/* Channel 1 and 2 have their own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    struct layer_context *context;
    switch (channel) {
    case 1: context = &panel_layer_context_ch1; break;
    case 2: context = &panel_layer_context_ch2; break;
    default: context = &panel_layer_context_ch0; break;
    }
    return context;
}

/*
 * Set the pixel format of a channel layer.
 *
 *   channel  0..2, or a number above 2 for all three channels
 *   format   0: 8 bits per pixel; 1..6: 16-bit formats; 8, 9 and every other number: 32-bit formats
 *   value    goes to byte +0x26 of the context and to bits 16..23 of block word 4
 *
 * The format number, its bits per pixel and the value are kept in the channel's context. Block word 4 is read
 * from the first-half block of the channel (channel 0 when the channel is above 2), its bits 8..23 replaced by the
 * value and the format code, bit 0 set, and the result written to the channel's block in both halves (to all three
 * blocks of both halves when the channel is above 2).
 *
 * No routine calls it directly; panel_channel_layer_setup_window carries the same steps in its own body.
 */
void panel_layer_set_format(unsigned char channel, unsigned int format, unsigned int value)
{
    struct layer_context *context;
    unsigned int word, i;
    unsigned char source_channel;

    context = get_context(channel);
    context->byte_0x26 = value;
    context->format = format;
    source_channel = channel;
    if (channel > LAST_CHANNEL)
        source_channel = 0;
    word = (panel_channel_blocks_first_half[source_channel][LAYER_WORD_4] & WORD4_KEEP_MASK) | ((unsigned char)value << 16);
    switch ((unsigned char)format) {
    case 0: context->bits_per_pixel = 8; break;
    case 1: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(0); break;
    case 2: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(1); break;
    case 3: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(2); break;
    case 4: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(3); break;
    case 5: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(4); break;
    case 6: context->bits_per_pixel = 16; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(5); break;
    case 8: context->bits_per_pixel = 32; word |= FORMAT_32BPP | FORMAT_BIT12; break;
    case 9: context->bits_per_pixel = 32; word |= FORMAT_32BPP | FORMAT_BIT11; break;
    default: context->bits_per_pixel = 32; word |= FORMAT_32BPP; break;     /* also format 7 */
    }
    word |= WORD4_BIT0;
    if (channel > LAST_CHANNEL)
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_first_half[i][LAYER_WORD_4] = word;
    else
        panel_channel_blocks_first_half[channel][LAYER_WORD_4] = word;
    if (channel > LAST_CHANNEL)
        for (i = 0; i <= LAST_CHANNEL; i++)
            panel_channel_blocks_second_half[i][LAYER_WORD_4] = word;
    else
        panel_channel_blocks_second_half[channel][LAYER_WORD_4] = word;
}
