/* panel_layer4_update_enable_bits  (FUN_a010fe50)
 *
 * Set or clear the fourth layer's bits in both halves, depending on where it lies.
 * Name basis: descriptive - row split of the layer record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010fe50 @ 0xa010fe50-0xa0110084 (141 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two bit updates are static helpers inlined per call; the half parameter picks the register set
 * (macro LAYER4_CTRL_BASE), so every arm builds its own register address and mark_outside after mark_inside tests
 * the channel again (as panel_layer_update_enable_bits); the +0x270 register is written as 'base | 0x270'.
 */
/* Word 0 of the fourth-layer registers in the first half (0xD0032000) or the second half (0xD003A000). */
#define LAYER4_CTRL_BASE(half) ((half) ? 0xd003a000 : 0xd0032000)
#define OUTSIDE_REG_OFFSET 0x270        /* register at base + 0x270 */
#define REG(address) (*(volatile unsigned int *)(address))
#define FIRST_HALF  0
#define SECOND_HALF 1

/* Bits of word 0: bit 1 (channel 0) or bit 2 (channel 1) = the window reaches into this half. */
#define CTRL_CH0_IN_HALF 0x2
#define CTRL_CH1_IN_HALF 0x4
#define CTRL_TOP_BITS    0xe0000000     /* bits 29..31, cleared when a window reaches into this half */
#define CTRL_BIT28       0x10000000     /* set at the same time */
/* Bits of the +0x270 register: bit 0 (channel 0) or bit 1 (channel 1) = the window lies wholly in the other half. */
#define OUTSIDE_CH0 0x1
#define OUTSIDE_CH1 0x2

struct layer_context { unsigned char pad[0x14]; unsigned short window_x, window_width; };
/* The working copy of the active panel timing row; only its width is read. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; };
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;
extern struct panel_timing_row *panel_working_row_ptr;

/* Mark the channel's window as lying outside this half. */
static void mark_outside(int half, unsigned char channel)
{
    if (channel == 1) {
        REG(LAYER4_CTRL_BASE(half)) &= ~CTRL_CH1_IN_HALF;
        REG(LAYER4_CTRL_BASE(half) | OUTSIDE_REG_OFFSET) |= OUTSIDE_CH1;
    } else {
        REG(LAYER4_CTRL_BASE(half)) &= ~CTRL_CH0_IN_HALF;
        REG(LAYER4_CTRL_BASE(half) | OUTSIDE_REG_OFFSET) |= OUTSIDE_CH0;
    }
}

/* Mark the channel's window as reaching into this half. */
static void mark_inside(int half, unsigned char channel)
{
    REG(LAYER4_CTRL_BASE(half)) &= ~CTRL_TOP_BITS;
    if (channel == 1) {
        REG(LAYER4_CTRL_BASE(half)) |= CTRL_BIT28 | CTRL_CH1_IN_HALF;
        REG(LAYER4_CTRL_BASE(half) | OUTSIDE_REG_OFFSET) &= ~OUTSIDE_CH1;
    } else {
        REG(LAYER4_CTRL_BASE(half)) |= CTRL_BIT28 | CTRL_CH0_IN_HALF;
        REG(LAYER4_CTRL_BASE(half) | OUTSIDE_REG_OFFSET) &= ~OUTSIDE_CH0;
    }
}

/*
 * The fourth-layer version of panel_layer_update_enable_bits: set the channel's bits in word 0 and in the +0x270
 * register of both halves from where its window lies against the middle of the panel (half of active_size0 of
 * the working timing row).
 *
 *   channel  1 for channel 1; every other number for channel 0
 *
 *   window starts at or right of the middle    first half: outside, second half: inside
 *   window starts left of it and crosses it    both halves: inside
 *   window ends at or left of the middle       first half: inside, second half: outside
 *
 * Marking a half "inside" also sets bits 28..31 of its word 0 to 1. Nothing in the image calls this routine.
 */
void panel_layer4_update_enable_bits(unsigned char channel)
{
    struct layer_context *context;
    unsigned short middle;

    context = &panel_layer4_context_ch0;
    if (channel == 1) context = &panel_layer4_context_ch1;
    middle = panel_working_row_ptr->active_size0 >> 1;
    if (context->window_x >= middle) {
        mark_outside(FIRST_HALF, channel);
        mark_inside(SECOND_HALF, channel);
    } else if (context->window_x + context->window_width > middle) {
        mark_inside(FIRST_HALF, channel);
        mark_inside(SECOND_HALF, channel);
    } else {
        mark_inside(FIRST_HALF, channel);
        mark_outside(SECOND_HALF, channel);
    }
}
