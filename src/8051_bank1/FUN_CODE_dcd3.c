/* 8051_bank1 FUN_CODE_dcd3 @ 0xdcd3 (no usable draft)
 * Register write, twin of FUN_CODE_dd74: XDATA 0x9AB0[reg] = val through a generic pointer (p += reg; tail LJMP
 * ?C?CSTPTR at 0x06ea with A = val). Byte-exact with OPTIMIZE(8,SPEED).
 */
void FUN_CODE_dcd3(unsigned char reg, unsigned char val)
{
    unsigned char *p;
    p = (unsigned char xdata *)0x9ab0;
    p += reg;
    *p = val;
}
