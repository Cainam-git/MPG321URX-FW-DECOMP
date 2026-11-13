/* reg_read_sync_meter_byte  (FUN_CODE_dd74)
 *
 * Read one register of the sync measurement block.
 *   reg: register
 * Returns: register byte
 * Name basis: descriptive - 8 callers in the standby signal checks (power_check_sync_timing, c0a1, cf38)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd74 @ 0xdd74
 * Options: OPTIMIZE(8,SPEED) (also level 7).
 * Source form: 'ptr += reg; return *ptr;' gives the firmware's ADD to R1 / ADDC to R2; 'ptr[reg]' and '*(ptr + reg)' give
 * ?C?CLDOPTR with a DPTR offset.
 */
#define SYNC_METER_WINDOW 0x9ab0   /* register window of the sync measurement block */

/* Return register reg of the sync measurement block.
 *   reg: offset from SYNC_METER_WINDOW */
unsigned char reg_read_sync_meter_byte(unsigned char reg)
{
    unsigned char *ptr;
    ptr = (unsigned char xdata *)SYNC_METER_WINDOW;
    ptr += reg;
    return *ptr;
}
