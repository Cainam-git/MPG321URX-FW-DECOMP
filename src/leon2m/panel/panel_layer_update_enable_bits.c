/* panel_layer_update_enable_bits  (FUN_a010f8fc)
 *
 * Set or clear a channel layer's enable bits in both halves, depending on where it lies.
 * Name basis: descriptive - bits of 0xD0030004 / 0xD0038004 chosen by the half-width split; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010f8fc @ 0xa010f8fc-0xa010fc74 (222 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two bit updates are static helpers with a switch on the channel, inlined per call; the half
 * parameter picks the register (macro LAYER_CTRL), so every case builds its own register address and the second
 * switch tests the channel again (as panel_layer_set_ctrl_bit8_clear_bit1).
 */
/* Control word of the channel layers in the first half (0xD0030004) or the second half (0xD0038004). */
#define LAYER_CTRL(half) (*(volatile unsigned int *)((half) ? 0xd0038004 : 0xd0030004))
#define FIRST_HALF  0
#define SECOND_HALF 1

/* Per channel (0..2) two bits of the control word: bit 1 + channel and bit 8 + channel. */
#define CTRL_IN_HALF(channel)      (2u << (channel))       /* the window reaches into this half */
#define CTRL_OUTSIDE_HALF(channel) (0x100u << (channel))   /* the window lies wholly in the other half */

struct layer_context { unsigned char pad[0x14]; unsigned short window_x, window_width; };
/* The working copy of the active panel timing row; only its width is read. */
struct panel_timing_row { unsigned int flags; unsigned short half_0x04; unsigned char display_mode, bpc; unsigned short active_size0; };
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern struct panel_timing_row *panel_working_row_ptr;

/* Mark the channel's window as lying outside this half. */
static void mark_outside(int half, unsigned char channel)
{
    switch (channel) {
    case 0:
        LAYER_CTRL(half) |= CTRL_OUTSIDE_HALF(0);
        LAYER_CTRL(half) &= ~CTRL_IN_HALF(0);
        break;
    case 1:
        LAYER_CTRL(half) |= CTRL_OUTSIDE_HALF(1);
        LAYER_CTRL(half) &= ~CTRL_IN_HALF(1);
        break;
    case 2:
        LAYER_CTRL(half) |= CTRL_OUTSIDE_HALF(2);
        LAYER_CTRL(half) &= ~CTRL_IN_HALF(2);
        break;
    }
}

/* Mark the channel's window as reaching into this half. */
static void mark_inside(int half, unsigned char channel)
{
    switch (channel) {
    case 0:
        LAYER_CTRL(half) |= CTRL_IN_HALF(0);
        LAYER_CTRL(half) &= ~CTRL_OUTSIDE_HALF(0);
        break;
    case 1:
        LAYER_CTRL(half) |= CTRL_IN_HALF(1);
        LAYER_CTRL(half) &= ~CTRL_OUTSIDE_HALF(1);
        break;
    case 2:
        LAYER_CTRL(half) |= CTRL_IN_HALF(2);
        LAYER_CTRL(half) &= ~CTRL_OUTSIDE_HALF(2);
        break;
    }
}

/*
 * Set the two bits of a channel layer in the control words of both halves from where its window lies against the
 * middle of the panel (half of active_size0 of the working timing row).
 *
 *   channel  0..2; any other number changes nothing (its context would be channel 0's)
 *
 *   window starts at or right of the middle    first half: outside, second half: inside
 *   window starts left of it and crosses it    both halves: inside
 *   window ends at or left of the middle       first half: inside, second half: outside
 *
 * panel_channel_layer_setup_window uses the same bits but only marks the half a window does not reach.
 * Nothing in the image calls this routine.
 */
void panel_layer_update_enable_bits(unsigned char channel)
{
    struct layer_context *context;
    unsigned short middle;

    switch (channel) {
    case 1: context = &panel_layer_context_ch1; break;
    case 2: context = &panel_layer_context_ch2; break;
    default: context = &panel_layer_context_ch0; break;
    }
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
