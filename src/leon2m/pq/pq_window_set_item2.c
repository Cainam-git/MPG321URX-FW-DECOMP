/* pq_window_set_item2  (FUN_a00f6e30)
 *
 * Write picture item 2 of the selected picture window.
 * Name basis: descriptive - value with its sign bit flipped, through the hook when one is set, else to
 *   register 0xCF00EF0C; item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6e30 @ 0xa00f6e30-0xa00f6e88 (22 words), flags -mcpu=v8 -O3 -g.
 * Source form: 'toggled_value = item_value | 0x80; if (item_value & 0x80) toggled_value = item_value & 0x7f' order (if/else arms give an extra and).
 */
#define BIT7 0x80
#define CLEAR_BIT7 0x7f
#define PICTURE_ITEM_2 2
#define PICTURE_ITEM_REG 0xcf00ef0c

extern void (*pq_window_item_hook)(int, unsigned int);

/*
 * Write picture item 2 of the selected picture window.
 * The item value is passed with bit 7 toggled (i.e. inverted). If the hook
 * routine is installed, it is called with (2, toggled_value); otherwise the
 * value is written to the register PICTURE_ITEM_REG.
 * Caller: pq_api_set_window_item.
 */
void pq_window_set_item2(unsigned char item_value)
{
  unsigned char toggled_value;

  /* Toggle bit 7 of the input value. */
  toggled_value = item_value | BIT7;
  if (item_value & BIT7)
    toggled_value = item_value & CLEAR_BIT7;
  if (pq_window_item_hook != 0)
    pq_window_item_hook(PICTURE_ITEM_2, toggled_value);
  else
    *(volatile unsigned int *)PICTURE_ITEM_REG = toggled_value;
}
