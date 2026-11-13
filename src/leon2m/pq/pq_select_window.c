/* pq_select_window  (FUN_a00f63bc)
 *
 * Select the picture window that the following picture settings apply to.
 * Name basis: proven - window index 0..3 into the low bits of 0xCF00EC84 and 0xCF00E980, cached at 0xA802B7B4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f63bc @ 0xa00f63bc-0xa00f6408 (19 words), flags -mcpu=v8 -O3 -g.
 * Leaf. The two hardware registers are volatile; the cache byte is not.
 */
extern unsigned char pq_selected_window;

#define REG_CF00EC84 0xcf00ec84   /* WINDOW_SELECT_A */
#define REG_CF00E980 0xcf00e980   /* WINDOW_SELECT_B */
#define WINDOW_SELECT_MASK 0xfc   /* clear the low 2 bits, keep the upper bits */

/*
 * Select the picture window that the following picture settings apply to.
 * If the requested window differs from the cached one, update the two hardware
 * registers that hold the window selection (low 2 bits) and then cache the new value.
 * The window number is OR-ed in as it is after bits 0..1 are cleared, so only 0..3 stay within those bits.
 * pq_get_selected_window returns the cached value.
 *
 * Callers: the pq_api_* window, table and ACE routines, pq_auto_level_task, pq_fga_handle_command,
 * sys_setup_channel_window, input_channel_bring_up_task, sys_init_picture_blocks.
 */
void pq_select_window(unsigned int window)
{
    if (pq_selected_window != window) {
        /* Update both registers before caching the new window. */
        *(volatile unsigned int *)REG_CF00EC84 = (*(volatile unsigned int *)REG_CF00EC84 & WINDOW_SELECT_MASK) | window;
        *(volatile unsigned int *)REG_CF00E980 = (*(volatile unsigned int *)REG_CF00E980 & WINDOW_SELECT_MASK) | window;
        pq_selected_window = window;
    }
}
