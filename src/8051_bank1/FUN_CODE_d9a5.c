/* 8051_bank1 FUN_CODE_d9a5 @ 0xd9a5
 * 16-bit register read on the 0x9AB0 block: lo = 0x9AB0[reg], hi = 0x9AB0[reg + 1] (pointer += 1), returns hi:lo.
 * Byte-exact with OPTIMIZE(8,SPEED).
 */
unsigned int FUN_CODE_d9a5(unsigned char reg)
{
    unsigned char *p;
    unsigned char lo, hi;
    p = (unsigned char xdata *)0x9ab0;
    p += reg;
    lo = *p;
    p += 1;
    hi = *p;
    return ((unsigned int)hi << 8) | lo;
}
