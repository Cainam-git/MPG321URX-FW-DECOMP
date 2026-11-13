/* panel_spread_set_enable_from_row  (FUN_a0104cb0)
 *
 * Switch the clock modulation on or off as the working panel timing row says.
 * Note: Nothing calls this copy; panel_spread_configure contains the same steps.
 * Name basis: descriptive - bit 26 of the row's first word; no caller
 *
 * Matching notes
 * --------------
 * FUN_a0104cb0, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
/* Control register of the two blocks (the second lies 0x100 above the first); bit 0 is the one this routine sets. */
#define SPREAD_CTRL_BLOCK0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL_BLOCK1 (*(volatile unsigned int *)0xcf012990)

/* Bit 26 of the first word of the active panel timing row (see panel_set_working_row). */
#define PANEL_ROW_SPREAD_BIT 0x4000000

extern unsigned int *panel_working_row_ptr;

/*
 * Copy bit 26 of the active panel timing row into bit 0 of both control registers.
 * Nothing calls this copy; panel_spread_set_rate_and_depth, panel_spread_set_fields and panel_spread_configure
 * contain the same sequence inline.
 */
void panel_spread_set_enable_from_row(void)
{
    if (*panel_working_row_ptr & PANEL_ROW_SPREAD_BIT) {
        SPREAD_CTRL_BLOCK0 |= 1;
        SPREAD_CTRL_BLOCK1 |= 1;
    } else {
        SPREAD_CTRL_BLOCK0 &= ~1u;
        SPREAD_CTRL_BLOCK1 &= ~1u;
    }
}
