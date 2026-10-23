/* 8051_bank1 FUN_CODE_d61c @ 0xd61c
 * Register bit update on the 0x9AB0 block (as FUN_CODE_dd74 / dcd3): v = 0x9AB0[reg]; on == 1 -> v |= mask, else
 * v &= ~mask; write back (tail LJMP ?C?CSTPTR). 'on' is the LARGE parameter slot XDATA 0xA475. Twin of FUN_CODE_d645.
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
void FUN_CODE_d61c(unsigned char reg, unsigned char mask, unsigned char on)
{
    unsigned char *p;
    unsigned char v;
    p = (unsigned char xdata *)0x9ab0;
    p += reg;
    v = *p;
    if (on == 1) v |= mask; else v &= ~mask;
    *p = v;
}
