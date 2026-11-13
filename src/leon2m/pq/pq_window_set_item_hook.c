/* pq_window_set_item_hook  (FUN_a00f87b0)
 *
 * Store the hook that receives the picture window items.
 * Name basis: descriptive - word at 0xA802B7B8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f87b0 @ 0xa00f87b0, flags -mcpu=v8 -O2 -g (the section default; -O3 -g and -Os -g give the
 * same bytes).
 */
extern unsigned int pq_window_item_hook;

/*
 * Store the routine that receives picture items 0..5 (pq_window_item_hook).
 *
 *   hook  address of the routine; pq_window_set_item0..5 call it with (item number, value) instead of
 *         writing their register when it is not 0
 *
 * Only caller: sys_init_picture_blocks, which installs ipc_8051_set_option_byte.
 */
void pq_window_set_item_hook(unsigned int hook)

{
  pq_window_item_hook = hook;
  return;
}
