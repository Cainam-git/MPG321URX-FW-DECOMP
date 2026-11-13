/* input_is_timing_supported  (FUN_a0105d58)
 *
 * Look a width, height and rate up in the table of supported timings and print the result.
 * Returns: 1 when found
 * Name basis: proven - prints '%d x %d @ %d : Support(%d_%d)'; called from GlobalModeHandler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105d58 @ 0xa0105d58, flags -mcpu=v8 -O3 (no -g: with -g a nop follows the final call).
 * Source form: the row fields are read straight from the table (no row pointer); the rate test is
 * (unsigned int)(rate - f + 9) <= 0x12.
 */

/* A row of input_supported_timing_table (0x12 bytes). Only these three fields are read here. */
struct supported_timing {
    unsigned short h0, h2, h4;
    unsigned short width;                   /* +6 */
    unsigned short h8, ha, hc;
    unsigned short height;                  /* +0xE */
    unsigned short rate;                    /* +0x10 */
};
#define SUPPORTED_TIMING_ROWS 8
extern const struct supported_timing input_supported_timing_table[SUPPORTED_TIMING_ROWS];
extern int dbg_printf(const char *fmt, ...);

/*
 * Search the table for the first row that fits the given timing and return 1 when there is one. A row fits
 * when:
 *   - the width of the row minus the given width is at least 0 and less than a tenth of the row's width;
 *   - the same for the height;
 *   - the row's rate differs from the given rate by at most 9.
 * The result and the row number (8 when no row fits) are printed.
 *
 *   w  width, h  height, f  rate (in the units of the table)
 *
 * Called from GlobalModeHandler. drv_Set3DDEISC searches the same table with the same test.
 */
unsigned char input_is_timing_supported(unsigned short w, unsigned short h, unsigned short f)
{
    unsigned char found = 0;
    unsigned char i;

    for (i = 0; i < SUPPORTED_TIMING_ROWS; i++) {
        if ((unsigned short)(input_supported_timing_table[i].width - w) < input_supported_timing_table[i].width / 10 &&
            (unsigned short)(input_supported_timing_table[i].height - h) < input_supported_timing_table[i].height / 10 &&
            (unsigned int)(input_supported_timing_table[i].rate - f + 9) <= 0x12) {
            found = 1;
            break;
        }
    }
    dbg_printf("\x1b[1;31m%d x %d @ %d : Support(%d_%d)\r\n\x1b[m", w, h, f, found, i);
    return found;
}
