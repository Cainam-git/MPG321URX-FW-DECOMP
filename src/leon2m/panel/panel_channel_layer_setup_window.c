/* panel_channel_layer_setup_window  (FUN_a01107b8)
 *
 * Set up a channel layer's window across both output halves, split at the middle of the panel.
 * Note: With flags bit 0 set the positions are reflected inside each half. Nothing calls it.
 * Name basis: derived - splits the window at half the panel width and gives each half its buffer address,
 *   position and size; channel layer contexts and blocks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01107b8 @ 0xa01107b8-0xa0110d64 (1452 bytes, 363 words), flags -mcpu=v8 -O3 -g.
 * The static helpers are the firmware's own routines, inlined by the compiler: set_format = panel_layer_set_format
 * (panel_layer_set_format), set_position = panel_layer_set_window_position (panel_layer_set_window_position), strobe_update =
 * panel_layer_strobe_update (panel_layer_strobe_update). set_position and strobe_update also match as standalone routines.
 * set_format here takes unsigned char format/value; the standalone panel_layer_set_format needs unsigned int
 * format/value with unsigned char casts, and no single form matches both places, so the two are separate bodies.
 * Source forms the exact build depends on:
 *  - second_address is set in each arm ('first_address = context->base; if (window_width > first_width)
 *    second_address = context->base + k; else second_address = context->base;'): with 'second_address =
 *    first_address = ...; second_address += k' the register of second_address stays live at the block start
 *    after the post-reload copy propagation and register renaming skips it;
 *  - the block tables are 'volatile unsigned int *const [3]' (constant pointer tables, as in
 *    panel_layer4_setup_window);
 *  - the context fields +0x18/+0x1A/+0x20/+0x22 are plain unsigned short (with the constant tables this gives the
 *    firmware's store order);
 *  - the mirror step computes first_position before second_position; its 'window_x < middle' test is an
 *    unsigned compare;
 *  - the width of the panel is read from the working row three times (panel_working_row_ptr is not held).
 */

/* Stored settings of a channel layer (field names shared with the other panel_layer_* files). */
struct layer_context {
    unsigned int base;                          /* +0x00: buffer address of the picture */
    unsigned char pad4[8];                      /* +0x04 / +0x08: first_half_word, second_half_word */
    unsigned short source_width, source_lines;  /* +0x0C, +0x0E: size of the picture in the buffer */
    unsigned char pad10[4];
    unsigned short window_x, window_width;      /* +0x14, +0x16: left edge and width on the panel; 0 = no window */
    unsigned short first_half_position, second_half_position;  /* +0x18, +0x1A */
    unsigned char pad1c[4];
    unsigned short low_word, high_word;         /* +0x20, +0x22: high_word = lines of the window on the panel */
    unsigned char bits_per_pixel, format, byte_0x26; /* +0x24.. */
    unsigned char pad27[0x17];
    unsigned char flags, pad3f;                 /* +0x3E */
};
/* The working copy of the active panel timing row; only its width is read. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; };
extern struct panel_timing_row *panel_working_row_ptr;
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *const panel_channel_blocks_first_half[3], *const panel_channel_blocks_second_half[3];
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;
extern void panel_layer_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short timer_get_ticks16(void);
#define R(a) (*(volatile unsigned int *)(a))

#define LAST_CHANNEL        2           /* channel numbers above this mean "all three channels" */
#define LAYER_WORD_4        4           /* block word that holds the format */
#define LAYER_WORD_POSITION 5           /* block word: position << 16 | low word */
#define LAYER_FLAG_BIT0     1           /* flags: reflect the positions inside each half */
#define FIRST_HALF  0
#define SECOND_HALF 1

/* Control word of the channel layers in the first half and in the second half of the output. Per channel
   (0..2) two bits: bit 1 + channel and bit 8 + channel. */
#define LAYER_CTRL_HALF0 0xd0030004
#define LAYER_CTRL_HALF1 0xd0038004
#define CTRL_IN_HALF(channel)      (2u << (channel))       /* the window reaches into this half */
#define CTRL_OUTSIDE_HALF(channel) (0x100u << (channel))   /* the window lies wholly in the other half */

/* Block word 4 (as panel_layer_set_format). */
#define WORD4_KEEP_MASK  0xff0000ff     /* bits 8..23 are rebuilt, the rest is kept */
#define WORD4_BIT0       1              /* set on every write */
#define FORMAT_16BPP     0x100          /* bit 8: a 16-bit format; bits 13..15 tell which one */
#define FORMAT_32BPP     0x200          /* bit 9: a 32-bit format */
#define FORMAT_BIT11     0x800          /* together with bit 9 for format 9 */
#define FORMAT_BIT12     0x1000         /* together with bit 9 for format 8 */
#define FORMAT_16BPP_SUBTYPE(n) ((n) << 13)
#define WINDOW_FORMAT    7              /* not one of the listed formats: the plain 32-bit format */

/* Update register (as panel_layer_strobe_update). */
#define LAYER_UPDATE      0xd003b000    /* one bit per layer; reads 0 once the hardware has taken the update */
#define UPDATE_ALL_LAYERS 8             /* layer number for all nine bits (0x1FF) */
#define UPDATE_TIMEOUT    100           /* ticks of timer_get_ticks16 */

/* Buffer pixels for part_width panel pixels: source_width * part_width / window_width. */
static unsigned int scale(unsigned short source_width, unsigned int part_width, unsigned short window_width)
{
    return source_width * part_width / window_width;
}

/* Channels 1 and 2 have their own context; every other number uses the context of channel 0. */
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

/* The steps of panel_layer_strobe_update: when panel_layer_update_strobe_enabled is 1, set the layer's bit in the update
   register (0..6: bit 0..6, 7: bit 8, 8: all nine bits) and wait until it reads 0, at most 100 ticks. */
static void strobe_update(unsigned char layer)
{
    unsigned short start;

    if (panel_layer_update_strobe_enabled == 1) {
        if (layer == UPDATE_ALL_LAYERS)
            R(LAYER_UPDATE) = 0x1ff;
        else if (layer == 0)
            R(LAYER_UPDATE) = 1;
        else if (layer == 1)
            R(LAYER_UPDATE) = 2;
        else if (layer == 2)
            R(LAYER_UPDATE) = 4;
        else if (layer == 3)
            R(LAYER_UPDATE) = 8;
        else if (layer == 4)
            R(LAYER_UPDATE) = 0x10;
        else if (layer == 5)
            R(LAYER_UPDATE) = 0x20;
        else if (layer == 6)
            R(LAYER_UPDATE) = 0x40;
        else if (layer == 7)
            R(LAYER_UPDATE) = 0x100;
        start = timer_get_ticks16();
        while (R(LAYER_UPDATE) != 0 && (unsigned short)(timer_get_ticks16() - start) < UPDATE_TIMEOUT)
            ;
    }
}

/* The steps of panel_layer_set_format: keep format, bits per pixel and value in the context, and write the
   format code and the value (bits 16..23) to block word 4 of the channel in both halves. */
static void set_format(unsigned char channel, unsigned char format, unsigned char value)
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
    word = (panel_channel_blocks_first_half[source_channel][LAYER_WORD_4] & WORD4_KEEP_MASK) | (value << 16);
    switch (format) {
    case 0: context->bits_per_pixel = 8; break;
    case 1: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(0); break;
    case 2: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(1); break;
    case 3: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(2); break;
    case 4: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(3); break;
    case 5: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(4); break;
    case 6: context->bits_per_pixel = 0x10; word |= FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(5); break;
    case 8: context->bits_per_pixel = 0x20; word |= FORMAT_32BPP | FORMAT_BIT12; break;
    case 9: context->bits_per_pixel = 0x20; word |= FORMAT_32BPP | FORMAT_BIT11; break;
    default: context->bits_per_pixel = 0x20; word |= FORMAT_32BPP; break;
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

/* The steps of panel_layer_set_window_position: the part's left edge in bits 16..31 and low_word in bits 0..15
   of block word 5. In the second half the chip's position offset is added, or subtracted when the positions
   are reflected. */
static void set_position(unsigned char channel, unsigned char half, unsigned short position, unsigned short low_word)
{
    struct layer_context *context;
    unsigned int word;

    context = get_context(channel);
    if (half == 0) { context->first_half_position = position; word = position; }
    else {
        context->second_half_position = position;
        if (context->flags & LAYER_FLAG_BIT0) word = position - panel_layer_position_offset; else word = position + panel_layer_position_offset;
    }
    context->low_word = low_word;
    word = word << 16 | low_word;
    if (half == 0) panel_channel_blocks_first_half[channel][LAYER_WORD_POSITION] = word; else panel_channel_blocks_second_half[channel][LAYER_WORD_POSITION] = word;
}

/*
 * Set up the window of a channel layer on the panel. The output is built by two halves, each driving one half of
 * the panel width; the window is cut at the middle of the panel and each half gets its own part. Despite its name
 * it programs both halves; panel_layer4_setup_window does the same for the fourth layer.
 *
 *   channel  0..2; 1 and 2 have their own context, every other number uses channel 0's context and update bit
 *
 * The context must hold the window (window_x, window_width, high_word = lines), the buffer (base, source_width,
 * source_lines), low_word and the flags. Nothing happens when the window width is 0.
 *
 * Phases, in order:
 *   1. pick the context and the update bit of the channel;
 *   2. a window wholly in one half: mark the other half "outside" in its control word (bit 8 + channel set,
 *      bit 1 + channel cleared);
 *   3. split the window width into the part left of the middle (first_width) and right of it (second_width),
 *      and work out how many buffer pixels each part shows;
 *   4. set the plain 32-bit format (format 7), keeping byte_0x26;
 *   5. buffer address of each part: the second part's pixels follow the first part's in each buffer line;
 *   6. with flags bit 0 set, reflect the positions inside each half (a part at p of width w moves to
 *      middle - w - p); a window that crosses the middle also swaps the two buffer addresses;
 *   7. give each half its buffer address, position and size (panel_layer_set_buffer, set_position,
 *      panel_layer_set_output_size);
 *   8. when panel_layer_update_strobe_enabled is 1, request the update of the channel's layer and wait for it, at most
 *      100 ticks.
 *
 * Nothing in the image calls this routine.
 */
void panel_channel_layer_setup_window(unsigned char channel)
{
    struct layer_context *context;
    unsigned char update_layer;
    int middle;
    unsigned int umiddle;
    unsigned int first_position, second_position, first_width, second_width, first_source_width,
                 second_source_width, first_address, second_address;

    /* 1. Context and update bit. */
    switch (channel) {
    case 1:
        context = &panel_layer_context_ch1;
        update_layer = 1;
        break;
    case 2:
        context = &panel_layer_context_ch2;
        update_layer = 2;
        break;
    default:
        context = &panel_layer_context_ch0;
        update_layer = 0;
        break;
    }
    if (context->window_width == 0)
        return;

    /* 2. Where the window lies against the middle of the panel. */
    umiddle = panel_working_row_ptr->active_size0 >> 1;
    if (context->window_x >= umiddle) {
        /* Wholly right of the middle: nothing in the first half. */
        first_position = umiddle;
        second_position = context->window_x - umiddle;
        switch (channel) {
        case 0: R(LAYER_CTRL_HALF0) |= CTRL_OUTSIDE_HALF(0); R(LAYER_CTRL_HALF0) &= ~CTRL_IN_HALF(0); break;
        case 1: R(LAYER_CTRL_HALF0) |= CTRL_OUTSIDE_HALF(1); R(LAYER_CTRL_HALF0) &= ~CTRL_IN_HALF(1); break;
        case 2: R(LAYER_CTRL_HALF0) |= CTRL_OUTSIDE_HALF(2); R(LAYER_CTRL_HALF0) &= ~CTRL_IN_HALF(2); break;
        }
    } else {
        first_position = context->window_x;
        second_position = 0;
        if (context->window_x + context->window_width <= (panel_working_row_ptr->active_size0 >> 1)) {
            /* Wholly left of the middle: nothing in the second half. */
            switch (channel) {
            case 0: R(LAYER_CTRL_HALF1) |= CTRL_OUTSIDE_HALF(0); R(LAYER_CTRL_HALF1) &= ~CTRL_IN_HALF(0); break;
            case 1: R(LAYER_CTRL_HALF1) |= CTRL_OUTSIDE_HALF(1); R(LAYER_CTRL_HALF1) &= ~CTRL_IN_HALF(1); break;
            case 2: R(LAYER_CTRL_HALF1) |= CTRL_OUTSIDE_HALF(2); R(LAYER_CTRL_HALF1) &= ~CTRL_IN_HALF(2); break;
            }
        }
    }

    /* 3. Width of each part on the panel and in the buffer. */
    middle = panel_working_row_ptr->active_size0 >> 1;
    if (context->window_x + context->window_width > middle) {
        first_width = middle - first_position;
        second_width = context->window_width - first_width;
    } else {
        first_width = context->window_width;
        second_width = 0;
    }
    first_source_width = scale(context->source_width, first_width, context->window_width);
    second_source_width = scale(context->source_width, second_width, context->window_width);

    /* 4. Format. */
    set_format(channel, WINDOW_FORMAT, context->byte_0x26);

    /* 5. Buffer addresses. */
    first_address = context->base;
    if (context->window_width > first_width)
        second_address = context->base + (context->bits_per_pixel >> 3) * first_source_width;
    else
        second_address = context->base;

    /* 6. Reflect the positions inside each half. */
    if (context->flags & LAYER_FLAG_BIT0) {
        if (context->window_x + context->window_width > (middle = panel_working_row_ptr->active_size0 >> 1)) {
            if (context->window_x < (unsigned int)middle) {
                /* The window crosses the middle: the parts also swap their buffer addresses. */
                first_position = (middle - first_width) - first_position;
                second_position = (middle - second_width) - second_position;
                first_address += (context->bits_per_pixel >> 3) * second_source_width;
                second_address = context->base;
            } else {
                second_position = (middle - second_width) - second_position;
            }
        } else {
            first_position = (middle - first_width) - first_position;
        }
    }

    /* 7. Program both halves. */
    panel_layer_set_buffer(channel, FIRST_HALF, first_source_width, context->source_lines, first_address);
    panel_layer_set_buffer(channel, SECOND_HALF, second_source_width, context->source_lines, second_address);
    set_position(channel, FIRST_HALF, first_position, context->low_word);
    set_position(channel, SECOND_HALF, second_position, context->low_word);
    panel_layer_set_output_size(channel, FIRST_HALF, first_width, context->high_word);
    panel_layer_set_output_size(channel, SECOND_HALF, second_width, context->high_word);

    /* 8. Let the hardware take the new settings. */
    strobe_update(update_layer);
}
