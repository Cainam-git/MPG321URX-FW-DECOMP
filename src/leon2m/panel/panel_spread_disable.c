/* panel_spread_disable  (FUN_a0101e70)
 *
 * Clear the enable bit of the two clock modulation blocks.
 * Name basis: descriptive - bit 0 of 0xCF012890 and 0xCF012990; unused
 *
 * Matching notes
 * --------------
 * FUN_a0101e70 (leon2m 0xa0101e70-0xa0101e9c, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: two read-modify-writes, block 0 first.
 */
/* Control registers of the two clock modulation blocks; bit 0 switches the modulation on
   (see panel_spread_set_fields). */
#define SPREAD_CTRL_BLOCK0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL_BLOCK1 (*(volatile unsigned int *)0xcf012990)

#define SPREAD_ENABLE 1u

/*
 * Switch the clock modulation off in both blocks; the other bits of each control register keep their value.
 *
 * Nothing in the firmware calls this routine or holds its address.
 */
void panel_spread_disable(void)
{
    SPREAD_CTRL_BLOCK0 &= ~SPREAD_ENABLE;
    SPREAD_CTRL_BLOCK1 &= ~SPREAD_ENABLE;
}
