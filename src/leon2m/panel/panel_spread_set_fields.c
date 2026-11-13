/* panel_spread_set_fields  (FUN_a0104eb0)
 *
 * Write both fields of the clock modulation control byte and its enable bit.
 * Note: Nothing calls this copy; panel_spread_configure contains the same steps.
 * Name basis: descriptive - calls the two field routines and the enable routine; no caller
 *
 * Matching notes
 * --------------
 * FUN_a0104eb0, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: the three steps are static helpers that the compiler inlines here.
 */
/* Control register of the two blocks (the second lies 0x100 above the first). */
#define SPREAD_CTRL_BLOCK0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL_BLOCK1 (*(volatile unsigned int *)0xcf012990)

#define SPREAD_FIELD_LO_MASK  0x1e      /* bits 1..4 */
#define SPREAD_FIELD_LOW_BITS 0x1f      /* bits 0..4 */

/* Bit 26 of the first word of the active panel timing row. */
#define PANEL_ROW_SPREAD_BIT 0x4000000

extern unsigned int *panel_working_row_ptr;

/* Same as panel_spread_set_field_lo. */
static void set_bits_1_to_4(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL_BLOCK0 & ~(unsigned int)SPREAD_FIELD_LO_MASK) | (value & SPREAD_FIELD_LO_MASK);

    SPREAD_CTRL_BLOCK0 = merged;
    SPREAD_CTRL_BLOCK1 = merged;
}

/* Same as panel_spread_set_field_hi. */
static void set_bits_5_to_7(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL_BLOCK0 & SPREAD_FIELD_LOW_BITS) | (value & ~(unsigned int)SPREAD_FIELD_LOW_BITS);

    SPREAD_CTRL_BLOCK0 = merged;
    SPREAD_CTRL_BLOCK1 = merged;
}

/* Same as panel_spread_set_enable_from_row. */
static void set_bit_0_from_row(void)
{
    if (*panel_working_row_ptr & PANEL_ROW_SPREAD_BIT) {
        SPREAD_CTRL_BLOCK0 |= 1;
        SPREAD_CTRL_BLOCK1 |= 1;
    } else {
        SPREAD_CTRL_BLOCK0 &= ~1u;
        SPREAD_CTRL_BLOCK1 &= ~1u;
    }
}

/*
 * Write bits 1..4 and bits 5..7 of the control register from the byte value (written to both blocks),
 * then set bit 0 of both from bit 26 of the first word of the active panel timing row.
 * panel_spread_configure runs the same three steps inline (mode 0); nothing calls this copy.
 */
void panel_spread_set_fields(unsigned char value)
{
    set_bits_1_to_4(value);
    set_bits_5_to_7(value);
    set_bit_0_from_row();
}
