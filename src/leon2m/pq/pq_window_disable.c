/* pq_window_disable  (FUN_a00f67d0)
 *
 * Switch picture window 0..3 off.
 * Name basis: derived - bit 0 or 1 of 0xCF00EC80 or 0xCF00ECA8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f67d0 @ 0xa00f67d0-0xa00f6834 (25 words), flags -mcpu=v8 -O3 -g.
 * Source form: the four cases are written as an if-else chain; the masks are 0xfe and 0xfd.
 */
#define WINDOW_ENABLE_REG_0 0xcf00ec80
#define WINDOW_ENABLE_REG_1 0xcf00eca8
#define CLEAR_BIT0_MASK 0xfe
#define CLEAR_BIT1_MASK 0xfd

/*
 * Disable picture window 0..3.
 * window: window index (0..3).
 * Windows 0 / 1 clear bit 0 / 1 of 0xCF00EC80, windows 2 / 3 bit 0 / 1 of 0xCF00ECA8; other numbers do nothing.
 * The AND masks also clear bits 8..31. Unlike pq_window_enable, the second registers (0xCF00EE40 / 0xCF00EE68)
 * are not touched.
 *
 * Callers: pq_api_enable_window, pq_api_enable_channel_window, sys_set_channel_enable, sys_apply_pip_layout,
 * pq_fga_handle_command.
 */
void pq_window_disable(int window)
{
  if (window == 0)
    *(volatile unsigned int *)WINDOW_ENABLE_REG_0 &= CLEAR_BIT0_MASK;
  else if (window == 1)
    *(volatile unsigned int *)WINDOW_ENABLE_REG_0 &= CLEAR_BIT1_MASK;
  else if (window == 2)
    *(volatile unsigned int *)WINDOW_ENABLE_REG_1 &= CLEAR_BIT0_MASK;
  else if (window == 3)
    *(volatile unsigned int *)WINDOW_ENABLE_REG_1 &= CLEAR_BIT1_MASK;
}
