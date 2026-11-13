/* pq_window_set_item4  (FUN_a00f6ecc)
 *
 * Write picture item 4 of the selected picture window.
 * Name basis: descriptive - value unchanged, through the hook when one is set, else to register 0xCF00EF14;
 *   item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6ecc @ 0xa00f6ecc-0xa00f6f10 (17 words), flags -mcpu=v8 -O3 -g.
 * Source form: the u8 parameter is used directly (a separate 'unsigned int v' copy puts the and in %i0 instead of %o1).
 */
#define PICTURE_ITEM_4_SELECTOR 4           /* item number passed to the hook */
#define PICTURE_ITEM_4_REGISTER 0xcf00ef14  /* written when no hook is installed */

extern void (*pq_window_item_hook)(int, unsigned int);

/*
 * Set picture item 4 of the selected picture window to item_value.
 *
 * When pq_window_item_hook is set, it is called with item number 4 and the value and the register is not
 * written; otherwise the value goes to PICTURE_ITEM_4_REGISTER. sys_init_picture_blocks installs
 * ipc_8051_set_option_byte as the hook during start-up.
 *
 * Callers: pq_api_set_window_item (item 4) and pq_fga_handle_command (value 0).
 */
void pq_window_set_item4(unsigned char item_value)
{
  if (pq_window_item_hook != 0)
    pq_window_item_hook(PICTURE_ITEM_4_SELECTOR, item_value);
  else
    *(volatile unsigned int *)PICTURE_ITEM_4_REGISTER = item_value;
}
