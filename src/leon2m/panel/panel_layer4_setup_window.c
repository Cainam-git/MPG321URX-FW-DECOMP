/* panel_layer4_setup_window  (FUN_a0110318)
 *
 * Set up the fourth layer's window across both output halves, split at the middle of the panel.
 * Note: With flags bit 0 set the positions are reflected inside each half. Nothing calls it.
 * Name basis: derived - same steps as panel_channel_layer_setup_window on the fourth-layer contexts and
 *   registers (panel_layer4_set_buffer and the functions beside it)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0110318 @ 0xa0110318-0xa01107b8 (296 words), flags -mcpu=v8 -O3 -g.
 * The static helpers are the firmware's own routines, inlined by the compiler: get_context, set_format (the body of
 * panel_layer4_set_format) and set_position (the body of panel_layer4_set_window_position).
 * Source forms the exact build depends on:
 *  - WRITE_BLOCKS as in panel_layer4_set_gains, with the counter i declared in set_format;
 *  - set_format builds the control word as 'shifted = code << 16; word = code | shifted | 1' (operand order
 *    'or code, shifted');
 *  - 'second_address = first_address = context->base;' then '+=' on each (one load of base, as in
 *    panel_channel_layer_setup_window).
 */
#define REG(address) (*(volatile unsigned int *)(address))

/* Stored settings of the fourth layer. */
struct layer_context {
    unsigned int base;                  /* +0x00: buffer address of the picture */
    unsigned char pad04[8];             /* +0x04 / +0x08: first_half_word, second_half_word */
    unsigned short source_width;        /* +0x0C: pixels per line of the buffer */
    unsigned short source_lines;        /* +0x0E */
    unsigned char pad10[4];
    unsigned short window_x;            /* +0x14: left edge of the window on the panel */
    unsigned short window_width;        /* +0x16: pixels on the panel; 0 = no window */
    unsigned short first_half_position, second_half_position;   /* +0x18, +0x1A */
    unsigned char pad1c[4];
    unsigned short low_word;            /* +0x20: bits 0..15 of the position word */
    unsigned short high_word;           /* +0x22: lines of the window on the panel */
    unsigned char bits_per_pixel;       /* +0x24 */
    unsigned char format;               /* +0x25 */
    unsigned char byte_0x26;            /* +0x26 */
    unsigned char pad27[0x17];
    unsigned char flags;                /* +0x3E */
};
/* The first six words of a fourth-layer register block. */
struct layer4_block { unsigned int position, word_1, word_2, word_3, word_4, word_5; };
/* The working copy of the active panel timing row; only its width is read. */
struct panel_timing_row { unsigned char pad00[8]; unsigned short active_size0; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern unsigned char panel_layer_position_offset, panel_layer_update_strobe_enabled;
extern struct panel_timing_row *panel_working_row_ptr;
extern volatile struct layer4_block *const panel_layer4_blocks_first_half[2];
extern volatile struct layer4_block *const panel_layer4_blocks_second_half[2];
extern void panel_layer4_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer4_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short timer_get_ticks16(void);

#define LAST_LAYER4_CHANNEL 1           /* channel numbers above this mean "both channels" */
#define LAYER_FLAG_BIT0     1           /* flags: reflect the positions inside each half (panel_layer4_set_half_width) */
#define FIRST_HALF  0
#define SECOND_HALF 1

/* Word 0 and the +0x270 register of the fourth layer in each half (as panel_layer4_update_enable_bits). */
#define LAYER4_CTRL_HALF0    0xd0032000
#define LAYER4_CTRL_HALF1    0xd003a000
#define LAYER4_OUTSIDE_HALF0 0xd0032270
#define LAYER4_OUTSIDE_HALF1 0xd003a270
#define CTRL_CH0_IN_HALF 0x2            /* word 0: the window reaches into this half */
#define CTRL_CH1_IN_HALF 0x4
#define OUTSIDE_CH0      0x1            /* +0x270: the window lies wholly in the other half */
#define OUTSIDE_CH1      0x2

/* Format step (as panel_layer4_set_format). */
#define LAYER4_CH0_CTRL_HALF0 0xd0032004
#define LAYER4_CH0_CTRL_HALF1 0xd003a004
#define LAYER4_CH1_CTRL_HALF0 0xd0032008
#define LAYER4_CH1_CTRL_HALF1 0xd003a008
#define LAYER4_CTRL_BIT0      1
#define FORMAT_16BPP     0x100
#define FORMAT_32BPP     0x200
#define FORMAT_BIT12     0x1000
#define FORMAT_16BPP_SUBTYPE(n) ((n) << 13)
#define WINDOW_FORMAT    7              /* not one of the listed formats: the plain 32-bit format */
#define WINDOW_BYTE_0x26 0xff

/* Update register (as panel_layer_strobe_update); bit 4 is the one written for this layer. */
#define LAYER_UPDATE      0xd003b000
#define LAYER_UPDATE_BIT4 0x10
#define UPDATE_TIMEOUT    100           /* ticks of timer_get_ticks16 */

/* Write val to field f of the channel's block in table, or of both blocks when the channel is above 1 (uses
   channel and i of the caller). */
#define WRITE_BLOCKS(table, f, val) if (channel > LAST_LAYER4_CHANNEL) { for (i = 0; i <= LAST_LAYER4_CHANNEL; i++) table[i]->f = val; } else table[channel]->f = val

/* Channel 1 has its own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    if (channel != 1) return &panel_layer4_context_ch0;
    return &panel_layer4_context_ch1;
}

/* The steps of panel_layer4_set_format. */
static void set_format(unsigned char channel, unsigned char format, unsigned char value)
{
    unsigned int i;
    struct layer_context *context;
    unsigned int code, word, shifted;

    context = get_context(channel);
    context->byte_0x26 = value;
    context->format = format;
    word = value;
    WRITE_BLOCKS(panel_layer4_blocks_first_half, word_5, word);
    WRITE_BLOCKS(panel_layer4_blocks_second_half, word_5, word);
    switch (format)
    {
    case 1: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(0); break;
    case 2: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(1); break;
    case 3: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(2); break;
    case 4: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(3); break;
    case 5: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(4); break;
    case 6: context->bits_per_pixel = 16; code = FORMAT_16BPP | FORMAT_16BPP_SUBTYPE(5); break;
    case 8: context->bits_per_pixel = 32; code = FORMAT_32BPP | FORMAT_BIT12; break;
    default: context->bits_per_pixel = 32; code = FORMAT_32BPP; break;
    }
    if (channel == 0) { shifted = code << 16; word = code | shifted | LAYER4_CTRL_BIT0; REG(LAYER4_CH0_CTRL_HALF0) = word; REG(LAYER4_CH0_CTRL_HALF1) = word; }
    else { shifted = code << 16; word = code | shifted | LAYER4_CTRL_BIT0; REG(LAYER4_CH1_CTRL_HALF0) = word; REG(LAYER4_CH1_CTRL_HALF1) = word; }
}

/* The steps of panel_layer4_set_window_position: the part's left edge in bits 16..31 and low_word in bits 0..15
   of the position word. In the second half the chip's position offset is added, or subtracted when the
   positions are reflected. */
static void set_position(unsigned char channel, unsigned char half, unsigned short position, unsigned short low_word)
{
    struct layer_context *context;
    unsigned int word;

    context = get_context(channel);
    if (half == 0) { context->first_half_position = position; word = position; }
    else
    {
        context->second_half_position = position;
        if (context->flags & LAYER_FLAG_BIT0) word = position - panel_layer_position_offset; else word = position + panel_layer_position_offset;
    }
    context->low_word = low_word;
    word = word << 16 | low_word;
    if (half == 0) panel_layer4_blocks_first_half[channel]->position = word; else panel_layer4_blocks_second_half[channel]->position = word;
}

static int wider(unsigned short width, unsigned int first_width)
{
    if (width > first_width)
        return 1;
    return 0;
}

/* Buffer pixels for part_width panel pixels: source_width * part_width / window_width. */
static unsigned int scale(unsigned short source_width, unsigned int part_width, unsigned short window_width)
{
    return source_width * part_width / window_width;
}

/*
 * Set up the window of the fourth layer on the panel. The output is built by two halves, each driving one half
 * of the panel width; the window is cut at the middle of the panel and each half gets its own part. This is the
 * fourth-layer counterpart of panel_channel_layer_setup_window (which does the same for the channel layers);
 * despite its name it programs both halves.
 *
 *   channel  0 or 1; each has its own context, registers and register blocks
 *
 * The context must hold the window (window_x, window_width, high_word = lines), the buffer (base, source_width,
 * source_lines), low_word and the flags. Nothing happens when the window width is 0.
 *
 * Steps: mark a half the window does not reach as "outside" (the "inside" bits are not set here); split the window
 * width into the part left of the middle (first_width) and right of it (second_width) and work out how many buffer
 * pixels each part shows; set the 32-bit format; give each half its buffer address, position and size
 * (panel_layer4_set_buffer, set_position, panel_layer4_set_output_size); when panel_layer_update_strobe_enabled is 1,
 * request the update of layer bit 4 and wait for it, at most 100 ticks.
 *
 * With flag bit 0 set, positions are reflected inside each half (a part at p of width w moves to
 * half - w - p) and for a window that crosses the middle the two parts swap their buffer addresses.
 *
 * Nothing in the image calls this routine.
 */
void panel_layer4_setup_window(unsigned char channel)
{
    struct layer_context *context;
    unsigned short window_width, start;
    int middle;
    unsigned int first_position, second_position, first_width, second_width, first_source_width, second_source_width,
                 first_address, second_address;

    context = get_context(channel);
    window_width = context->window_width;
    if (context->window_width == 0) return;
    middle = panel_working_row_ptr->active_size0 >> 1;
    if (context->window_x >= (unsigned int) middle)
    {
        /* Wholly right of the middle: nothing in the first half. */
        second_position = context->window_x - middle;
        first_position = middle;
        if (channel == 1) { REG(LAYER4_CTRL_HALF0) &= ~CTRL_CH1_IN_HALF; REG(LAYER4_OUTSIDE_HALF0) |= OUTSIDE_CH1; }
        else { REG(LAYER4_CTRL_HALF0) &= ~CTRL_CH0_IN_HALF; REG(LAYER4_OUTSIDE_HALF0) |= OUTSIDE_CH0; }
    }
    else
    {
        first_position = context->window_x;
        second_position = 0;
        if (context->window_x + context->window_width <= middle)
        {
            /* Wholly left of the middle: nothing in the second half. */
            if (channel == 1) { REG(LAYER4_CTRL_HALF1) &= ~CTRL_CH1_IN_HALF; REG(LAYER4_OUTSIDE_HALF1) |= OUTSIDE_CH1; }
            else { REG(LAYER4_CTRL_HALF1) &= ~CTRL_CH0_IN_HALF; REG(LAYER4_OUTSIDE_HALF1) |= OUTSIDE_CH0; }
        }
    }
    {
        unsigned short x = context->window_x, width = context->window_width;
        if (x + width > (middle = panel_working_row_ptr->active_size0 >> 1)) { first_width = middle - first_position; second_width = width - first_width; }
        else { first_width = width; second_width = 0; }
    }
    first_source_width = scale(context->source_width, first_width, context->window_width);
    second_source_width = scale(context->source_width, second_width, context->window_width);
    set_format(channel, WINDOW_FORMAT, WINDOW_BYTE_0x26);
    /* The second part's pixels follow the first part's in each buffer line. */
    second_address = first_address = context->base;
    if (wider(context->window_width, first_width)) second_address += (context->bits_per_pixel >> 3) * first_source_width;
    if (context->flags & LAYER_FLAG_BIT0)
    {
        /* Reflect the positions inside each half. */
        unsigned short x = context->window_x, width = context->window_width;
        if (x + width > (middle = panel_working_row_ptr->active_size0 >> 1))
        {
            if ((unsigned int)x < (unsigned int)middle)
            {
                /* The window crosses the middle: the parts also swap their buffer addresses. */
                first_position = (middle - first_width) - first_position;
                second_position = (middle - second_width) - second_position;
                first_address += (context->bits_per_pixel >> 3) * second_source_width;
                second_address = context->base;
            }
            else second_position = (middle - second_width) - second_position;
        }
        else first_position = (middle - first_width) - first_position;
    }
    panel_layer4_set_buffer(channel, FIRST_HALF, first_source_width, context->source_lines, first_address);
    panel_layer4_set_buffer(channel, SECOND_HALF, second_source_width, context->source_lines, second_address);
    set_position(channel, FIRST_HALF, first_position, context->low_word);
    set_position(channel, SECOND_HALF, second_position, context->low_word);
    panel_layer4_set_output_size(channel, FIRST_HALF, first_width, context->high_word);
    panel_layer4_set_output_size(channel, SECOND_HALF, second_width, context->high_word);
    if (panel_layer_update_strobe_enabled == 1)
    {
        REG(LAYER_UPDATE) = LAYER_UPDATE_BIT4;
        start = timer_get_ticks16();
        while (REG(LAYER_UPDATE) != 0 && (unsigned short)(timer_get_ticks16() - start) < UPDATE_TIMEOUT)
            ;
    }
}
