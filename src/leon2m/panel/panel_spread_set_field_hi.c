/* panel_spread_set_field_hi  (FUN_a0104e80)
 *
 * Write bits 5..7 of the clock modulation control byte.
 * Note: Nothing calls this copy; panel_spread_configure contains the same steps.
 * Name basis: descriptive - 0xCF012890 / 0xCF012990; no caller
 *
 * Matching notes
 * --------------
 * FUN_a0104e80, flags -mcpu=v8 -O2 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the merged value is an unsigned char local.
 */
/* Control register of the two blocks (the second lies 0x100 above the first). */
#define SPREAD_CTRL_BLOCK0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL_BLOCK1 (*(volatile unsigned int *)0xcf012990)

#define SPREAD_FIELD_LOW_BITS 0x1f      /* bits 0..4 stay as they are */

/*
 * Replace bits 5..7 of the control register with the same bits of value and write the resulting low byte to
 * both blocks. The factory spread-spectrum menu puts its "freq" setting in these bits ((freq << 5) | ...).
 * Nothing calls this copy; panel_spread_set_fields and panel_spread_configure contain the same sequence inline.
 */
void panel_spread_set_field_hi(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL_BLOCK0 & SPREAD_FIELD_LOW_BITS) | (value & ~(unsigned int)SPREAD_FIELD_LOW_BITS);

    SPREAD_CTRL_BLOCK0 = merged;
    SPREAD_CTRL_BLOCK1 = merged;
}
