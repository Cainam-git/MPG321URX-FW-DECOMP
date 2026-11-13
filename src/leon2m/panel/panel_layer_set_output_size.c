/* panel_layer_set_output_size  (FUN_a010bee4)
 *
 * Store one half's output width and the window lines of a channel layer; program size and scaling.
 * Note: Programs block word 6, the two scaling ratios and the same-size bit of that half.
 * Name basis: derived - context +0x1C / +0x1E (width per half) and +0x22 (lines); block words 6, 0x34 and
 *   0x35; called once per half by panel_channel_layer_setup_window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010bee4 @ 0xa010bee4-0xa010c194 (688 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - after the store of window_lines every use reads high_word (+0x22) back (the firmware zero-extends it again
 *    each time); source_lines is read in place each time;
 *  - block word 1 is read through a pointer chosen by half; the other writes choose the table per statement;
 *  - the equality is written 'layer->source_lines == layer->high_word'.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Stored settings of a channel layer (field names shared with the other panel_layer_* files). */
struct layer_context { unsigned int base; unsigned char pad04[8];
             unsigned short source_width, source_lines;                 /* +0x0C / +0x0E: size of the buffer */
             unsigned short first_half_source_width, second_half_source_width;  /* +0x10 / +0x12 */
             unsigned short window_x, window_width;                     /* +0x14 / +0x16 */
             unsigned short first_half_position, second_half_position;  /* +0x18 / +0x1A */
             unsigned short first_half_width, second_half_width;        /* +0x1C / +0x1E: output width of each part */
             unsigned short low_word, high_word; };                     /* +0x20 / +0x22: high_word = window lines */
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];

/* Words of a channel layer register block written here. */
#define LAYER_WORD_CTRL      1          /* bits 0..9 are rebuilt here */
#define LAYER_WORD_SIZE_OUT  6          /* part width << 16 | window lines */
#define LAYER_WORD_V_RATIO   0x34       /* (source lines - 1) / (window lines - 1), 16.16 */
#define LAYER_WORD_H_RATIO   0x35       /* (source width - 1) / (window width - 1), 16.16 */

#define LAYER_CTRL_WIDER     0x14       /* the part is wider than its source part */
#define LAYER_CTRL_TALLER    0x20       /* the window has more lines than the source */

/* One register per half; one bit per channel, set when the part shows its source at the same size. */
#define LAYER_SAME_SIZE_HALF0 0xd0030008
#define LAYER_SAME_SIZE_HALF1 0xd0038008
#define SAME_SIZE_CH0        0x10000    /* bit 16 */
#define SAME_SIZE_CH1        0x100000   /* bit 20 */
#define SAME_SIZE_CH2        0x1000000  /* bit 24 */

/* The stored settings of a channel: channels 1 and 2 have their own record, every other number uses
   channel 0's. */
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
 * Store the output width of one half's part and the window lines of a channel layer, and program the size,
 * the two scaling ratios and the same-size bit for that half.
 *
 *   ch            channel layer 0..2 (another number uses channel 0's record and leaves the same-size bits alone)
 *   half          0: first half (width at +0x1C), otherwise the second half (+0x1E)
 *   part_width    output width of the part shown in this half
 *   window_lines  stored at +0x22
 *
 * Called from panel_channel_layer_setup_window, once for each half. panel_layer4_set_output_size has the
 * same steps for the fourth layer.
 */
void panel_layer_set_output_size(unsigned char ch, unsigned char half, unsigned short part_width, unsigned short window_lines)
{
    struct layer_context *layer;
    unsigned int part_source_width;
    unsigned int ctrl_word, value, ratio, same_size;
    volatile unsigned int *block;

    layer = ctx(ch);
    if (half == 0) { layer->first_half_width = part_width; part_source_width = layer->first_half_source_width; } else { layer->second_half_width = part_width; part_source_width = layer->second_half_source_width; }
    layer->high_word = window_lines;
    if (half == 0) block = panel_channel_blocks_first_half[ch]; else block = panel_channel_blocks_second_half[ch];
    ctrl_word = block[LAYER_WORD_CTRL] & ~0x3ff;
    if (part_width > part_source_width) ctrl_word |= LAYER_CTRL_WIDER;
    if (layer->high_word > layer->source_lines) ctrl_word |= LAYER_CTRL_TALLER;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_CTRL] = ctrl_word; else panel_channel_blocks_second_half[ch][LAYER_WORD_CTRL] = ctrl_word;
    value = part_width << 16 | layer->high_word;
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_SIZE_OUT] = value; else panel_channel_blocks_second_half[ch][LAYER_WORD_SIZE_OUT] = value;
    ratio = ((layer->source_lines - 1) << 16) / (unsigned int)(layer->high_word - 1);
    if (half == 0) panel_channel_blocks_first_half[ch][LAYER_WORD_V_RATIO] = ratio; else panel_channel_blocks_second_half[ch][LAYER_WORD_V_RATIO] = ratio;
    ratio = ((layer->source_width - 1) << 16) / (unsigned int)(layer->window_width - 1);
    if (half == 0) { panel_channel_blocks_first_half[ch][LAYER_WORD_H_RATIO] = ratio; same_size = R(LAYER_SAME_SIZE_HALF0); }
    else { panel_channel_blocks_second_half[ch][LAYER_WORD_H_RATIO] = ratio; same_size = R(LAYER_SAME_SIZE_HALF1); }
    /* Same size: the part is as wide as its source part and the window has the source's lines. */
    if (part_width == part_source_width && layer->source_lines == layer->high_word) {
        switch (ch) {
        case 0: same_size |= SAME_SIZE_CH0; break;
        case 1: same_size |= SAME_SIZE_CH1; break;
        case 2: same_size |= SAME_SIZE_CH2; break;
        }
    } else {
        switch (ch) {
        case 0: same_size &= ~SAME_SIZE_CH0; break;
        case 1: same_size &= ~SAME_SIZE_CH1; break;
        case 2: same_size &= ~SAME_SIZE_CH2; break;
        }
    }
    if (half == 0) R(LAYER_SAME_SIZE_HALF0) = same_size; else R(LAYER_SAME_SIZE_HALF1) = same_size;
}
