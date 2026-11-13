/* pq_window_set_item0  (FUN_a00f6d80)
 *
 * Write picture item 0 of the selected picture window.
 * Name basis: descriptive - value with its sign bit flipped, through the hook when one is set, else to
 *   register 0xCF00EF04; item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6d80 @ 0xa00f6d80-0xa00f6dd8 (22 words), flags -mcpu=v8 -O3 -g.
 * Source form: the bit 7 toggle is written as an if/else, not as an XOR.
 */
#define ITEM_INDEX 0
#define ITEM_VALUE_BIT7 0x80
#define ITEM_VALUE_MASK 0x7f
#define REG_CF00EF04 0xcf00ef04

extern void (*pq_window_item_hook)(int, unsigned int);

/*
 * Write picture item 0 of the selected picture window.
 * The value's bit 7 is toggled (if set, cleared; if clear, set).
 * If the hook (ipc_8051_set_option_byte) is installed, it is called with item index 0 and the toggled value;
 * otherwise the toggled value is written to REG_CF00EF04.
 * Called by pq_api_set_window_item.
 */
void pq_window_set_item0(unsigned char value)
{
  unsigned char toggled_value;

  toggled_value = value | ITEM_VALUE_BIT7;
  if (value & ITEM_VALUE_BIT7)
    toggled_value = value & ITEM_VALUE_MASK;
  if (pq_window_item_hook != 0)
    pq_window_item_hook(ITEM_INDEX, toggled_value);
  else
    *(volatile unsigned int *)REG_CF00EF04 = toggled_value;
}
