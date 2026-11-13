/* pq_window_set_item1  (FUN_a00f6dd8)
 *
 * Write picture item 1 of the selected picture window.
 * Name basis: descriptive - value with its sign bit flipped, through the hook when one is set, else to
 *   register 0xCF00EF08; item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6dd8 @ 0xa00f6dd8-0xa00f6e30 (88 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: value = item_value | BIT7 as default, overridden when bit 7 is set (the counterpart of pq_window_set_item6).
 */
#define BIT7 0x80
#define LOWER7 0x7f
#define ITEM_1 1
#define REG_CF00EF08 (*(volatile unsigned int *)0xcf00ef08)

extern void (*pq_window_item_hook)(int, unsigned int);

/*
 * Write picture item 1 of the selected picture window.
 * Flips bit 7 of the item value, then either calls the hook (pq_window_item_hook) with the item number and the
 * transformed value, or writes the transformed value to the register at 0xcf00ef08 when the hook is not set.
 * Caller: pq_api_set_window_item.
 */
void pq_window_set_item1(unsigned char item_value)
{
    unsigned char value;

    value = item_value | BIT7;
    if (item_value & BIT7)
        value = item_value & LOWER7;
    if (pq_window_item_hook)
        pq_window_item_hook(ITEM_1, value);
    else
        REG_CF00EF08 = value;
}
