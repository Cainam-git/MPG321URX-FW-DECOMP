/* pq_window_set_item3  (FUN_a00f6e88)
 *
 * Write picture item 3 of the selected picture window.
 * Name basis: descriptive - value unchanged, through the hook when one is set, else to register 0xCF00EF10;
 *   item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6e88 @ 0xa00f6e88-0xa00f6ecc (17 words), flags -mcpu=v8 -O3 -g.
 * Source form: the unsigned char parameter is used directly; a separate 'unsigned int value' copy would put the
 * zero-extension in %i0 instead of %o1.
 */
extern void (*pq_window_item_hook)(int, unsigned int);

#define PICTURE_ITEM_3 3                  /* picture item selector 3 */
#define PICTURE_ITEM3_REGISTER 0xcf00ef10 /* register written when no hook is installed */

/*
 * Set picture item 3 of the selected picture window to value.
 * If pq_window_item_hook is installed, it receives the item selector and the value;
 * otherwise the value is written to the item 3 register.
 * Called from pq_fga_handle_command (DDC/CI calibration command) and pq_api_set_window_item.
 */
void pq_window_set_item3(unsigned char value)
{
  if (pq_window_item_hook != 0)
    pq_window_item_hook(PICTURE_ITEM_3, value);
  else
    *(volatile unsigned int *)PICTURE_ITEM3_REGISTER = value;
}
