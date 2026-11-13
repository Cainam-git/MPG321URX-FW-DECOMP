/* panel_spread_set_rate_and_depth  (FUN_a0104d18)
 *
 * Program the rate and depth of the clock modulation.
 * Note: Nothing calls this copy; panel_spread_configure contains the same steps.
 * Name basis: derived - 1500 / a and a * b scaled, to both modulation blocks; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0104d18, flags -mcpu=v8 -O3 -g.
 * Source form: the range tests are written !(x >= lo && x <= hi); an || of two compares gives other code.
 */
/* Rate and depth registers of the two blocks; the control registers lie at -8 from the rate register. */
#define SPREAD_RATE_BLOCK0   0xcf012898
#define SPREAD_DEPTH_BLOCK0  0xcf01289c
#define SPREAD_RATE_BLOCK1   0xcf012998
#define SPREAD_DEPTH_BLOCK1  0xcf01299c
#define SPREAD_CTRL_BLOCK0   0xcf012890
#define SPREAD_CTRL_BLOCK1   0xcf012990

/* Bit 26 of the first word of the active panel timing row. */
#define PANEL_ROW_SPREAD_BIT 0x4000000

/* Accepted ranges of the two parameters, and the values that replace anything outside them. */
#define FIRST_MIN       25
#define FIRST_MAX       500
#define FIRST_DEFAULT   100
#define SECOND_MIN      5
#define SECOND_MAX      5000
#define SECOND_DEFAULT  150

#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int *panel_working_row_ptr;

/*
 * Write two derived bytes to the rate and depth registers of both blocks and refresh bit 0 of their
 * control registers from the panel timing row.
 *
 *   first   25..500, otherwise 100; the rate register gets 1500 / first
 *   second  5..5000, otherwise 150; the depth register gets ((first * second) << 15) / 15000000
 *
 * Both results are stored as bytes. Bit 7 of each rate register is set afterwards. Bit 0 of each control
 * register then follows bit 26 of the first word of the active panel timing row.
 * panel_spread_configure runs the same sequence inline when its mode argument is not 0; nothing calls this copy.
 */
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
