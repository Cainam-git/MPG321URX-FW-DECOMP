/* 8051_bank1 FUN_CODE_9caa @ 0x9caa..0x9d75 (203 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Count-down of the 32-bit value at XDATA 0xA62A. 0x03E7FC18 there means "off": the function returns 0. Otherwise
 * the 16-bit count from FUN_CODE_d94a minus the previous count at XDATA 0xA5E9 is the elapsed value (the new count
 * is stored to 0xA5E9). When the elapsed value is greater than 0xA62A, FUN_CODE_2820 is passed the format at CODE
 * 0x9938 ("Wakeup by timer %08lx %04x\r\n") with 0xA62A and the elapsed value, 0xA62A is set back to 0x03E7FC18
 * and 1 is returned; else the elapsed value is subtracted from 0xA62A and 0 is returned.
 * LARGE local: the elapsed value at XDATA 0xA473; the new count stays in R6:R7. The constant store is ?C?LSTKXDATA
 * with the 4-byte constant inline after the LCALL.
 * Caller: FUN_CODE_3fe7 (LCALL at 0x41D4; a nonzero result sets XDATA 0xA46F = 0x0C there).
 */
extern unsigned long xdata DAT_EXTMEM_a62a;
extern unsigned int xdata DAT_EXTMEM_a5e9;
extern unsigned int FUN_CODE_d94a(void);
extern void FUN_CODE_2820(void *fmt, ...) large;

unsigned char FUN_CODE_9caa(void)
{
    unsigned int el;
    unsigned int now;

    if (DAT_EXTMEM_a62a == 0x03e7fc18)
        return 0;
    now = FUN_CODE_d94a();
    el = now - DAT_EXTMEM_a5e9;
    DAT_EXTMEM_a5e9 = now;
    if (DAT_EXTMEM_a62a < el) {
        FUN_CODE_2820((void code *)0x9938, DAT_EXTMEM_a62a, el);
        DAT_EXTMEM_a62a = 0x03e7fc18;
        return 1;
    }
    DAT_EXTMEM_a62a -= el;
    return 0;
}
