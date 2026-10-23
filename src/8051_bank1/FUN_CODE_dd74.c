/* 8051_bank1 FUN_CODE_dd74 @ 0xdd74
 * Register read: returns XDATA 0x9AB0[reg] through a generic pointer (R3 = 01, pointer + reg, ?C?CLDPTR at 0x06a4).
 * The pointer form matters: 'p += reg; return *p;' gives the firmware's ADD to R1 / ADDC to R2; 'p[reg]' and
 * '*(p + reg)' give ?C?CLDOPTR with a DPTR offset. 8 call sites (FUN_CODE_d2b4 reads reg 0x29).
 * Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
unsigned char FUN_CODE_dd74(unsigned char reg)
{
    unsigned char *p;
    p = (unsigned char xdata *)0x9ab0;
    p += reg;
    return *p;
}
