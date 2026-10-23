/* 8051_bank1 FUN_CODE_d645 @ 0xd645  OPTIMIZE(8,SPEED) LARGE
 * Sets (on == 1) or clears (other on) the bits mask in XDATA 0x9A00 + reg. Same code as FUN_CODE_d61c with
 * another base. Source form: the base is the array symbol DAT_EXTMEM_9a00 (as in FUN_CODE_d9d1).
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
