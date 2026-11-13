/* pq_window_set_item5  (FUN_a00f6f10)
 *
 * Write picture item 5 of the selected picture window.
 * Name basis: descriptive - value unchanged, through the hook when one is set, else to register 0xCF00EF18;
 *   item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6f10 @ 0xa00f6f10-0xa00f6f54 (17 words), flags -mcpu=v8 -O3 -g.
 * Source form: the unsigned char parameter is used directly (a separate 'unsigned int' copy would put the and in %i0 instead of %o1).
 */
extern void (*pq_window_item_hook)(int, unsigned int);

#define PICTURE_ITEM_5 5                     /* item number passed to the hook */
#define PICTURE_ITEM5_REGISTER 0xcf00ef18    /* written when no hook is installed */

/*
 * Set picture item 5 of the selected picture window to value.
 *
 * When pq_window_item_hook is set, it is called with item number 5 and the value and the register is not
 * written; otherwise the value goes to PICTURE_ITEM5_REGISTER. sys_init_picture_blocks installs
 * ipc_8051_set_option_byte as the hook during start-up.
 *
 * Callers: pq_api_set_window_item (item 5) and pq_fga_handle_command (value 0).
 */
void pq_window_set_item5(unsigned char value)
{
  if (pq_window_item_hook != 0)
    pq_window_item_hook(PICTURE_ITEM_5, value);
  else
    *(volatile unsigned int *)PICTURE_ITEM5_REGISTER = value;
}
