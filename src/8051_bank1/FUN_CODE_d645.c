/* 8051_bank1 FUN_CODE_d645 @ 0xd645 (no usable draft)
 * Twin of FUN_CODE_d61c on the 0x9A00 block ('on' slot XDATA 0xA474); base as the array symbol (see FUN_CODE_d9d1).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_9a00[];
void FUN_CODE_d645(unsigned char reg, unsigned char mask, unsigned char on)
{
    unsigned char *p;
    unsigned char v;
    p = DAT_EXTMEM_9a00;
    p += reg;
    v = *p;
    if (on == 1) v |= mask; else v &= ~mask;
    *p = v;
}
