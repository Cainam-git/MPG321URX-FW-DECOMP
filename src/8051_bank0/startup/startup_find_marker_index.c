/* startup_find_marker_index  (FUN_CODE_17e2)
 *
 * Return the position of a marker byte in a small table, by clock variant.
 * Name basis: descriptive - marker 0x30 or 0x60; the main routine stores the result plus 1 at XDATA 0xD929
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: the clock-variant-0x20 search is a do-while, the other a for loop, and "not found" is tested once
 * after both (i == 6); the exact build depends on the two loop forms.
 */

#define MARKER_VARIANT_20   0x30    /* searched in startup_marker_bytes_slow_clock */
#define MARKER_OTHER        0x60    /* searched in startup_marker_bytes */
#define MARKER_TABLE_BYTES  6

unsigned char idata startup_marker_bytes[6] _at_ 0x08;
unsigned char idata startup_marker_bytes_slow_clock[6] _at_ 0x0e;
bit startup_is_slow_clock(void);

/* startup_find_marker_index
 *
 * Returns the position (0..5) of the first marker byte in a six-byte IDATA table, or 0 when there is none.  When
 * reg_sys_clock_variant reads 0x20 the table is IDATA 0x0E..0x13 and the marker 0x30; otherwise IDATA 0x08..0x0D
 * and 0x60.  Only caller: startup_boot_main, which stores the result + 1 at XDATA 0xD929.
 *
 * The start-up code clears IDATA 0x01..0x7F, and startup_boot_main calls this routine before any other code, so
 * in this boot loader both tables read 0 and the result is 0.
 */
unsigned char startup_find_marker_index(void)
{
    unsigned char i;
    i = 0;
    if (startup_is_slow_clock()) {
        do { if (startup_marker_bytes_slow_clock[i] == MARKER_VARIANT_20) break; i++; } while (i != MARKER_TABLE_BYTES);
    } else {
        for (i = 0; i != MARKER_TABLE_BYTES; i++) if (startup_marker_bytes[i] == MARKER_OTHER) break;
    }
    if (i == MARKER_TABLE_BYTES) i = 0;     /* not found */
    return i;
}
