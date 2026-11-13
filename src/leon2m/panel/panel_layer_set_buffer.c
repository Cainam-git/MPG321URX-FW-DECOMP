/* panel_layer_set_buffer  (FUN_a010baf4)
 *
 * Store the buffer parameters of a channel layer and program them.
 * Name basis: descriptive - record fields and block words 7..10; used by the first-half window set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010baf4 @ 0xa010baf4-0xa010bdcc (182 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - every block-word store chooses the table in its own if/else (both arms store; the compiler merges the common
 *    load/store tail);
 *  - the stored values are computed before the half test; 'start_pixel <<= 16' comes before stride is computed;
 *  - half is a byte parameter; 'width * 220' is unsigned.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Stored settings of a channel layer (field names shared with the other panel_layer_* files). */
struct layer_context {
    unsigned int base;                  /* +0x00 */
    unsigned int first_half_word;       /* +0x04: buffer address of the first-half part, in 32-byte units */
    unsigned int second_half_word;      /* +0x08: the same for the second-half part */
    unsigned short source_width;        /* +0x0C: pixels per line of the buffer */
    unsigned short source_lines;        /* +0x0E */
    unsigned short first_half_source_width;     /* +0x10: pixels of the buffer line shown in the first half */
    unsigned short second_half_source_width;    /* +0x12 */
    unsigned short window_x, window_width;      /* +0x14 / +0x16 */
    unsigned short first_half_position, second_half_position;   /* +0x18 / +0x1A */
    unsigned short first_half_width, second_half_width;         /* +0x1C / +0x1E */
    unsigned short low_word, high_word;         /* +0x20 / +0x22 */
    unsigned char bits_per_pixel;       /* +0x24: 8, 16 or 32 */
};
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];

/* Words of a channel layer register block written here. */
#define LAYER_WORD_SIZE    7            /* shown width << 16 | lines */
#define LAYER_WORD_STRIDE  8            /* first pixel in the 32-byte unit << 16 | line length in pixels */
#define LAYER_WORD_ADDRESS 9            /* buffer address in 32-byte units, plus a channel bit */
#define LAYER_WORD_LENGTH  10           /* lines * line length * bits per pixel / 128 */

#define LAYER_ADDRESS_BIT_CH1 0x4000000 /* bit 26, set for channel 1 */
#define LAYER_ADDRESS_BIT_CH2 0x8000000 /* bit 27, set for channel 2 */

/* One register per channel and half; bits 16 and up get width * 220 / 320 + 1, limited per channel. */
#define LAYER_REG_90_HALF0 0xd0030090   /* channel 0, limit 0x9FF */
#define LAYER_REG_94_HALF0 0xd0030094   /* channel 1, limit 0x4FF */
#define LAYER_REG_98_HALF0 0xd0030098   /* channel 2, limit 0x6BF */
#define LAYER_REG_90_HALF1 0xd0038090
#define LAYER_REG_94_HALF1 0xd0038094
#define LAYER_REG_98_HALF1 0xd0038098

/* The stored settings of a channel: channels 1 and 2 have their own record, every other number uses
   channel 0's (the same choice as panel_layer_set_output_size). */
static struct layer_context *ctx(unsigned char ch)
{
    struct layer_context *p;
    switch (ch) {
    case 1: p = &panel_layer_context_ch1; break;
    case 2: p = &panel_layer_context_ch2; break;
    default: p = &panel_layer_context_ch0; break;
    }
    return p;
}

/*
 * Store where a channel layer's picture lies in memory and program the layer's register block for one half of
 * the output.
 *
 *   ch              channel layer 0..2
 *   half            0: first half (panel_channel_blocks_first_half), otherwise the second half
 *   width           pixels of the buffer line shown in this half (stored at +0x10 or +0x12)
 *   lines           lines of the buffer (stored at +0x0E)
 *   buffer_address  byte address of the picture; stored in 32-byte units at +0x04 or +0x08
 *
 * Called from panel_channel_layer_setup_window.
 *
 * The line length is source_width rounded up to a whole number of 32-byte units; the low five bits of the
 * address give the first pixel inside the first unit. bits_per_pixel must already be set (it divides).
 */
void panel_layer_set_buffer(unsigned char ch, unsigned char half, unsigned short width, unsigned short lines, unsigned int buffer_address)
{
    struct layer_context *layer;
    unsigned int start_pixel, pixels_per_unit, stride, address_word, reg_value, value;

    layer = ctx(ch);
    start_pixel = (buffer_address & 0x1f) / (layer->bits_per_pixel >> 3);
    if (half == 0) {
        layer->first_half_word = buffer_address >> 5;
        layer->first_half_source_width = width;
    } else {
        layer->second_half_word = buffer_address >> 5;
        layer->second_half_source_width = width;
    }
    layer->source_lines = lines;
    value = width << 16 | lines;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_SIZE] = value; else panel_channel_blocks_second_half[ch][LAYER_WORD_SIZE] = value;
    /* Pixels per 32-byte unit; the line length is rounded up to a multiple of it. */
    pixels_per_unit = 0x20 / (layer->bits_per_pixel >> 3);
    start_pixel <<= 16;
    stride = layer->source_width / pixels_per_unit * pixels_per_unit;
    if (layer->source_width != stride)
        stride = (layer->source_width / pixels_per_unit + 1) * pixels_per_unit;
    value = start_pixel | stride;
    if (half == 0) {
        panel_channel_blocks_first_half[ch][LAYER_WORD_STRIDE] = value;
        address_word = layer->first_half_word;
    } else {
        panel_channel_blocks_second_half[ch][LAYER_WORD_STRIDE] = value;
        address_word = layer->second_half_word;
    }
    if (ch == 1)
        address_word |= LAYER_ADDRESS_BIT_CH1;
    else if (ch == 2)
        address_word |= LAYER_ADDRESS_BIT_CH2;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_ADDRESS] = address_word; else panel_channel_blocks_second_half[ch][LAYER_WORD_ADDRESS] = address_word;
    value = lines * stride * layer->bits_per_pixel >> 7;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_LENGTH] = value; else panel_channel_blocks_second_half[ch][LAYER_WORD_LENGTH] = value;
    reg_value = (unsigned int)width * 220 / 320 + 1;
    switch (ch) {
    case 1:
        if (reg_value > 0x4ff)
            reg_value = 0x4ff;
        if (half == 0)
            R(LAYER_REG_94_HALF0) = reg_value << 16;
        else
            R(LAYER_REG_94_HALF1) = reg_value << 16;
        break;
    case 2:
        if (reg_value > 0x6bf)
            reg_value = 0x6bf;
        if (half == 0)
            R(LAYER_REG_98_HALF0) = reg_value << 16;
        else
            R(LAYER_REG_98_HALF1) = reg_value << 16;
        break;
    case 0:
        if (reg_value > 0x9ff)
            reg_value = 0x9ff;
        if (half == 0)
            R(LAYER_REG_90_HALF0) = reg_value << 16;
        else
            R(LAYER_REG_90_HALF1) = reg_value << 16;
        break;
    }
}
