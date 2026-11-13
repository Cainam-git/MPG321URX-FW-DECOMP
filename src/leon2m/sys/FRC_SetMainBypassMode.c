/* FRC_SetMainBypassMode  (FUN_a01095bc)
 *
 * Switch the bypass of the frame-rate converter for the main picture on or off.
 * Name basis: proven - prints 'FRC_SetMainBypassMode enable' / 'disable' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01095bc @ 0xa01095bc, flags -mcpu=v8 -O3 -g.
 * Source form: the last read-modify-write of both arms is shared code.
 */
#define REG_cf0116d4 (*(volatile unsigned int *)0xcf0116d4)
#define REG_cf011a80 (*(volatile unsigned int *)0xcf011a80)
#define REG_cf011800 (*(volatile unsigned int *)0xcf011800)
#define REG_cf011a00 (*(volatile unsigned int *)0xcf011a00)

extern int dbg_printf(const char *fmt, ...);

/*
 * Switch the bypass of the frame-rate converter for the main picture on (enable != 0) or off, and print which.
 *
 * On: set bit 0 of the registers 0xCF0116D4 and 0xCF011A80, clear bit 0 of 0xCF011800 and 0xCF011A00.
 * Off: clear bit 0 of 0xCF0116D4 and 0xCF011A80.
 *
 * Called by GMDHEnableFRC, with bit 26 of the system configuration word as `enable`. (The off message ends in a
 * space, as in the firmware.)
 */
void FRC_SetMainBypassMode(unsigned char enable)
{
    if (enable) {
        dbg_printf("FRC_SetMainBypassMode enable\r\n");
        REG_cf0116d4 |= 1;
        REG_cf011a80 |= 1;
        REG_cf011800 &= ~1;
        REG_cf011a00 &= ~1;
    } else {
        dbg_printf("FRC_SetMainBypassMode disable \r\n");
        REG_cf0116d4 &= ~1;
        REG_cf011a80 &= ~1;
    }
}
