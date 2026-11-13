/* panel_spread_configure  (FUN_a0104f48)
 *
 * Configure the clock modulation, or switch it off.
 * Name basis: derived - off for a == 0; rate and depth for mode != 0, else the control fields
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104f48 @ 0xa0104f48-0xa0105150 (130 words), flags -mcpu=v8 -O3 -g.
 * Source form: panel_spread_set_rate_and_depth, panel_spread_set_fields and the three routines
 * panel_spread_set_fields calls (panel_spread_set_field_lo, panel_spread_set_field_hi,
 * panel_spread_set_enable_from_row) are written here as the separately matched routines and inlined by the
 * compiler. Two spellings of the control register are kept: R(SPREAD_CTRL_BLOCK0) with '&= ~1' in the routines
 * written with R(), and the SPREAD_CTRL0 / SPREAD_CTRL1 macros with '~1u' / '~0x1eu' / '~0x1fu' in the others.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Clock modulation: two register blocks, the second 0x100 above the first. Control register: bit 0 on,
   bits 1..4 and 5..7 two fields set from one byte; rate register at +8 (bit 7 set after the value), depth
   register at +0xC. */
#define SPREAD_CTRL_BLOCK0   0xcf012890
#define SPREAD_RATE_BLOCK0   0xcf012898
#define SPREAD_DEPTH_BLOCK0  0xcf01289c
#define SPREAD_CTRL_BLOCK1   0xcf012990
#define SPREAD_RATE_BLOCK1   0xcf012998
#define SPREAD_DEPTH_BLOCK1  0xcf01299c
#define SPREAD_CTRL0 (*(volatile unsigned int *)0xcf012890)
#define SPREAD_CTRL1 (*(volatile unsigned int *)0xcf012990)

#define SPREAD_FIELD_LO_MASK  0x1e      /* bits 1..4 */
#define SPREAD_FIELD_LOW_BITS 0x1f      /* bits 0..4 */

/* Bit 26 of the first word of the active panel timing row: modulation on for this row. */
#define PANEL_ROW_SPREAD_BIT 0x4000000

/* Accepted ranges of the two parameters, and the values that replace anything outside them. */
#define FIRST_MIN       25
#define FIRST_MAX       500
#define FIRST_DEFAULT   100
#define SECOND_MIN      5
#define SECOND_MAX      5000
#define SECOND_DEFAULT  150

extern unsigned int *panel_working_row_ptr;

/* Rate register = 1500 / first, depth register = ((first * second) << 15) / 15000000, in both blocks; then
   bit 0 of both control registers from the panel row. */
void panel_spread_set_rate_and_depth(unsigned short first, unsigned short second)
{
    unsigned char rate_byte, depth_byte;

    if (!(first >= FIRST_MIN && first <= FIRST_MAX))
        first = FIRST_DEFAULT;
    if (!(second >= SECOND_MIN && second <= SECOND_MAX))
        second = SECOND_DEFAULT;
    rate_byte = 1500 / first;
    depth_byte = ((unsigned int)(second * first) << 15) / 15000000;
    R(SPREAD_RATE_BLOCK0) = rate_byte;
    R(SPREAD_DEPTH_BLOCK0) = depth_byte;
    R(SPREAD_RATE_BLOCK0) |= 0x80;
    R(SPREAD_RATE_BLOCK1) = rate_byte;
    R(SPREAD_DEPTH_BLOCK1) = depth_byte;
    R(SPREAD_RATE_BLOCK1) |= 0x80;
    if (*panel_working_row_ptr & PANEL_ROW_SPREAD_BIT) {
        R(SPREAD_CTRL_BLOCK0) |= 1;
        R(SPREAD_CTRL_BLOCK1) |= 1;
    } else {
        R(SPREAD_CTRL_BLOCK0) &= ~1;
        R(SPREAD_CTRL_BLOCK1) &= ~1;
    }
}

/* Bit 0 of both control registers follows the panel row. */
void panel_spread_set_enable_from_row(void)
{
    if (*panel_working_row_ptr & PANEL_ROW_SPREAD_BIT) {
        SPREAD_CTRL0 |= 1;
        SPREAD_CTRL1 |= 1;
    } else {
        SPREAD_CTRL0 &= ~1u;
        SPREAD_CTRL1 &= ~1u;
    }
}

/* Bits 1..4 of the value into both control registers (block 0's register gives the other bits). */
void panel_spread_set_field_lo(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL0 & ~0x1eu) | (value & SPREAD_FIELD_LO_MASK);

    SPREAD_CTRL0 = merged;
    SPREAD_CTRL1 = merged;
}

/* Bits 5..7 of the value into both control registers. */
void panel_spread_set_field_hi(unsigned int value)
{
    unsigned char merged = (SPREAD_CTRL0 & SPREAD_FIELD_LOW_BITS) | (value & ~0x1fu);

    SPREAD_CTRL0 = merged;
    SPREAD_CTRL1 = merged;
}

/* The control byte's bits 1..7 from the value, then bit 0 from the panel row. */
void panel_spread_set_fields(unsigned char value)
{
    panel_spread_set_field_lo(value);
    panel_spread_set_field_hi(value);
    panel_spread_set_enable_from_row();
}

/*
 * Set up the clock modulation of the display output, or switch it off.
 *
 *   mode    not 0: first / second give the rate and the depth (panel_spread_set_rate_and_depth);
 *           0: first is the control byte (bits 1..4 and 5..7, panel_spread_set_fields)
 *   first   0 switches the modulation off in both blocks
 *   second  only used when mode is not 0
 *
 * In both set-up cases bit 0 of the control registers (modulation on) then follows bit 26 of the active panel
 * timing row. nvram_api_set_device_field3 calls it with mode 1 and the stored device field +3 as both values.
 */
void panel_spread_configure(unsigned char mode, unsigned short first, unsigned short second)
{
    if (first != 0) {
        if (mode)
            panel_spread_set_rate_and_depth(first, second);
        else
            panel_spread_set_fields(first);
    } else {
        R(SPREAD_CTRL_BLOCK0) &= ~1;
        R(SPREAD_CTRL_BLOCK1) &= ~1;
    }
}
