/* reg_read_sync_meter_word  (FUN_CODE_d9a5)
 *
 * Read a 16-bit value from two registers of the sync measurement block.
 *   reg: low register
 * Returns: 16-bit value
 * Name basis: descriptive - regs 0x12/0x14/0x26 checked against picture size limits by power_check_sync_timing
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d9a5 @ 0xd9a5  Byte-exact with OPTIMIZE(8,SPEED).
 */
#define SYNC_METER_WINDOW 0x9ab0  /* XDATA base of the sync measurement register block */

/*
 * Read a 16-bit value from the sync measurement block: low byte at register 'reg', high byte at 'reg' + 1.
 * Used by power_check_sync_timing for the size and rate limits.
 */
unsigned int reg_read_sync_meter_word(unsigned char reg)
{
    unsigned char *reg_ptr;
    unsigned char lo, hi;

    reg_ptr = (unsigned char xdata *)SYNC_METER_WINDOW;
    reg_ptr += reg;
    lo = *reg_ptr;
    reg_ptr += 1;
    hi = *reg_ptr;
    return ((unsigned int)hi << 8) | lo;
}
