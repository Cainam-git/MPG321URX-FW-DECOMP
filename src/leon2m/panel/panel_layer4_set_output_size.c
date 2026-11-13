/* panel_layer4_set_output_size  (FUN_a010de54)
 *
 * Program the panel size of one half's part of the fourth layer, with its scaling ratios.
 * Note: The horizontal ratio goes to this half only, the vertical ratio to both halves.
 * Name basis: derived - part width and window lines per half; ratios ((source - 1) << 16) / (window - 1);
 *   called once per half by panel_layer4_setup_window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010de54 @ 0xa010de54-0xa010e0f4 (672 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the horizontal-ratio store and the bit-2 update are written out in each of the four arms (gives
 * the firmware's duplicated compare blocks); the vertical ratio and its compare use 'window_lines =
 * context->high_word' read back after the store (the firmware zero-extends the value again there instead of
 * reusing size << 16; the local keeps the operand order 'cmp source_lines, window_lines').
 */
/* Stored settings of the fourth layer; only the fields used here. */
struct layer_context {
    unsigned int base;                  /* +0x00 */
    unsigned char pad04[8];
    unsigned short source_width;        /* +0x0C: pixels per line of the buffer */
    unsigned short source_lines;        /* +0x0E */
    unsigned short first_half_source_width;     /* +0x10: buffer pixels shown in the first half */
    unsigned short second_half_source_width;    /* +0x12 */
    unsigned short window_x;            /* +0x14 */
    unsigned short window_width;        /* +0x16: pixels on the panel */
    unsigned short first_half_position, second_half_position;   /* +0x18, +0x1A */
    unsigned short first_half_width;    /* +0x1C: panel pixels of the window in the first half */
    unsigned short second_half_width;   /* +0x1E */
    unsigned short low_word;            /* +0x20 */
    unsigned short high_word;           /* +0x22: lines of the window on the panel */
};
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

#define REG(address) (*(volatile unsigned int *)(address))

/* Registers of the fourth layer; channel 0 and channel 1 each have a set in each half. */
#define LAYER4_CH0_WINDOW_SIZE_HALF0     0xd0032030    /* part width << 16 | window lines */
#define LAYER4_CH0_WINDOW_SIZE_HALF1     0xd003a030
#define LAYER4_CH1_WINDOW_SIZE_HALF0     0xd00320a0
#define LAYER4_CH1_WINDOW_SIZE_HALF1     0xd003a0a0
#define LAYER4_CH0_HRATIO_HALF0   0xd0032034    /* buffer pixels per panel pixel, 16.16 */
#define LAYER4_CH0_HRATIO_HALF1   0xd003a034
#define LAYER4_CH1_HRATIO_HALF0   0xd00320a4
#define LAYER4_CH1_HRATIO_HALF1   0xd003a0a4
#define LAYER4_CH0_VRATIO_HALF0   0xd0032038    /* buffer lines per panel line, 16.16 */
#define LAYER4_CH0_VRATIO_HALF1   0xd003a038
#define LAYER4_CH1_VRATIO_HALF0   0xd00320a8
#define LAYER4_CH1_VRATIO_HALF1   0xd003a0a8
#define LAYER4_CH0_CTRL_HALF0     0xd0032004
#define LAYER4_CH0_CTRL_HALF1     0xd003a004
#define LAYER4_CH1_CTRL_HALF0     0xd0032008
#define LAYER4_CH1_CTRL_HALF1     0xd003a008
#define LAYER4_CTRL_LINES_DIFFER  2     /* bit 1: buffer lines and window lines differ */
#define LAYER4_CTRL_WIDTH_DIFFERS 4     /* bit 2: the part's buffer width and panel width differ */

/* Channel 1 has its own context; every other number uses the context of channel 0. */
static struct layer_context *get_context(unsigned char channel)
{
    if (channel != 1) return &panel_layer4_context_ch0;
    return &panel_layer4_context_ch1;
}

/*
 * Program the size on the panel of one half's part of the fourth layer, with its scaling ratios.
 *
 *   channel       0 for the channel-0 registers, any other number for the channel-1 registers
 *   half          0: the first half of the output, otherwise the second
 *   part_width    panel pixels of the window in this half
 *   window_lines  lines of the window on the panel
 *
 * Called twice by panel_layer4_setup_window, once per half, after panel_layer4_set_buffer has stored
 * the part's buffer width. The horizontal ratio is ((source_width - 1) << 16) / (window_width - 1) of the whole
 * window and goes to this half only; the vertical ratio ((source_lines - 1) << 16) / (window_lines - 1) goes to
 * both halves. Each control bit is set when the two sizes it compares differ and cleared when they are equal.
 */
void panel_layer4_set_output_size(unsigned char channel, unsigned char half, unsigned short part_width, unsigned short window_lines_in)
{
    struct layer_context *context;
    unsigned int compare;
    unsigned int word, ratio, window_lines;

    context = get_context(channel);
    if (half == 0) { context->first_half_width = part_width; compare = context->first_half_source_width; }
    else { context->second_half_width = part_width; compare = context->second_half_source_width; }
    context->high_word = window_lines_in;
    word = part_width << 16 | window_lines_in;
    if (channel == 0) {
        if (half == 0) REG(LAYER4_CH0_WINDOW_SIZE_HALF0) = word; else REG(LAYER4_CH0_WINDOW_SIZE_HALF1) = word;
    } else {
        if (half == 0) REG(LAYER4_CH1_WINDOW_SIZE_HALF0) = word; else REG(LAYER4_CH1_WINDOW_SIZE_HALF1) = word;
    }
    ratio = ((context->source_width - 1) << 16) / (unsigned int)(context->window_width - 1);
    if (channel == 0) {
        if (half == 0) { REG(LAYER4_CH0_HRATIO_HALF0) = ratio; if (part_width == compare) REG(LAYER4_CH0_CTRL_HALF0) &= ~LAYER4_CTRL_WIDTH_DIFFERS; else REG(LAYER4_CH0_CTRL_HALF0) |= LAYER4_CTRL_WIDTH_DIFFERS; }
        else { REG(LAYER4_CH0_HRATIO_HALF1) = ratio; if (part_width == compare) REG(LAYER4_CH0_CTRL_HALF1) &= ~LAYER4_CTRL_WIDTH_DIFFERS; else REG(LAYER4_CH0_CTRL_HALF1) |= LAYER4_CTRL_WIDTH_DIFFERS; }
    } else {
        if (half == 0) { REG(LAYER4_CH1_HRATIO_HALF0) = ratio; if (part_width == compare) REG(LAYER4_CH1_CTRL_HALF0) &= ~LAYER4_CTRL_WIDTH_DIFFERS; else REG(LAYER4_CH1_CTRL_HALF0) |= LAYER4_CTRL_WIDTH_DIFFERS; }
        else { REG(LAYER4_CH1_HRATIO_HALF1) = ratio; if (part_width == compare) REG(LAYER4_CH1_CTRL_HALF1) &= ~LAYER4_CTRL_WIDTH_DIFFERS; else REG(LAYER4_CH1_CTRL_HALF1) |= LAYER4_CTRL_WIDTH_DIFFERS; }
    }
    compare = context->source_lines;
    window_lines = context->high_word;
    ratio = ((compare - 1) << 16) / (window_lines - 1);
    if (channel == 0) {
        REG(LAYER4_CH0_VRATIO_HALF0) = ratio;
        REG(LAYER4_CH0_VRATIO_HALF1) = ratio;
        if (compare == window_lines) { REG(LAYER4_CH0_CTRL_HALF0) &= ~LAYER4_CTRL_LINES_DIFFER; REG(LAYER4_CH0_CTRL_HALF1) &= ~LAYER4_CTRL_LINES_DIFFER; }
        else { REG(LAYER4_CH0_CTRL_HALF0) |= LAYER4_CTRL_LINES_DIFFER; REG(LAYER4_CH0_CTRL_HALF1) |= LAYER4_CTRL_LINES_DIFFER; }
    } else {
        REG(LAYER4_CH1_VRATIO_HALF0) = ratio;
        REG(LAYER4_CH1_VRATIO_HALF1) = ratio;
        if (compare == window_lines) { REG(LAYER4_CH1_CTRL_HALF0) &= ~LAYER4_CTRL_LINES_DIFFER; REG(LAYER4_CH1_CTRL_HALF1) &= ~LAYER4_CTRL_LINES_DIFFER; }
        else { REG(LAYER4_CH1_CTRL_HALF0) |= LAYER4_CTRL_LINES_DIFFER; REG(LAYER4_CH1_CTRL_HALF1) |= LAYER4_CTRL_LINES_DIFFER; }
    }
}
