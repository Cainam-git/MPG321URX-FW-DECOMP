/* osd_draw_factory_field_value  (FUN_a008a778)
 *
 * Draw the stored value 0xA802AFBA in factory menu field 0x16.
 * Note: No direct caller.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a778, flags -mcpu=v8 -O2 -g.
 * Tail call: the callee returns straight to this routine's caller; the last word is the nop the compiler places
 * behind such a call sequence.
 */

#define FACTORY_ITEM_DUMMY 0x16                 /* factory menu item 22 */

extern unsigned char osd_factory_dummy_value;
extern void osd_draw_factory_number(unsigned char, unsigned short);

/* Draw osd_factory_dummy_value in factory menu item 22 (DUMMY). Nothing in the source calls this routine. */
void osd_draw_factory_field_value(void)
{
    osd_draw_factory_number(FACTORY_ITEM_DUMMY, osd_factory_dummy_value);
}
