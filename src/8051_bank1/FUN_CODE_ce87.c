/* 8051_bank1 FUN_CODE_ce87 @ 0xce87 (59 B).
 * Compares IDATA values and returns a code: starts with 0xFF; 1 when the bytes at 0x42 and 0x44 differ; then
 * 2 when the bytes at 0x47 and 0x4C differ, else 3 when the unsigned ints at 0x48 and 0x4E differ, else 4 when the
 * unsigned ints at 0x4A and 0x51 differ (a later result replaces the 1). All operands are read through @R0 / @R1
 * (idata). Callers: LCALL at 0x39F6 and 0xDE50. No aids.
 */
extern unsigned char idata DAT_INTMEM_42, DAT_INTMEM_44, DAT_INTMEM_47, DAT_INTMEM_4c;
extern unsigned int idata DAT_INTMEM_48, DAT_INTMEM_4e, DAT_INTMEM_4a, DAT_INTMEM_51;

unsigned char FUN_CODE_ce87(void)
{
    unsigned char r;
    r = 0xff;
    if (DAT_INTMEM_42 != DAT_INTMEM_44) r = 1;
    if (DAT_INTMEM_47 != DAT_INTMEM_4c) {
        r = 2;
    } else if (DAT_INTMEM_48 != DAT_INTMEM_4e) {
        r = 3;
    } else if (DAT_INTMEM_4a != DAT_INTMEM_51) {
        r = 4;
    }
    return r;
}
