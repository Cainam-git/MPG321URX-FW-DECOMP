/* panel_spread_set_field_lo  (FUN_a0104e50)
 *
 * Write bits 1..4 of the clock modulation control byte.
 * Note: Nothing calls this copy; panel_spread_configure contains the same steps.
 * Name basis: descriptive - 0xCF012890 / 0xCF012990; no caller
 *
 * Matching notes
 * --------------
 * FUN_a0104e50, flags -mcpu=v8 -O2 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the merged value is an unsigned char local.
 */
/* Control register of the two blocks (the second lies 0x100 above the first). */
#define SPREAD_CTRL_BLOCK0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL_BLOCK1 (*(volatile unsigned int *)0xcf012990)

#define SPREAD_FIELD_LO_MASK 0x1e       /* bits 1..4 */

/*
 * Replace bits 1..4 of the control register with the same bits of value and write the resulting low byte to
 * both blocks. The factory spread-spectrum menu builds its register value as (freq << 5) | (ratio * 2) | 1,
 * so bits 1..4 are the part it takes from "ratio".
 * Nothing calls this copy; panel_spread_set_fields and panel_spread_configure contain the same sequence inline.
 */
void panel_spread_set_field_lo(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL_BLOCK0 & ~(unsigned int)SPREAD_FIELD_LO_MASK) | (value & SPREAD_FIELD_LO_MASK);

    SPREAD_CTRL_BLOCK0 = merged;
    SPREAD_CTRL_BLOCK1 = merged;
}
