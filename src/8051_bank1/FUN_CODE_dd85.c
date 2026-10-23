/* 8051_bank1 FUN_CODE_dd85 @ 0xdd85..0xdd96 (17 bytes), OPTIMIZE(7,SPEED).
 * Register read on the 0x9A00 block: returns XDATA 0x9A00[reg] through a generic pointer (p += reg; ?C?CLDPTR),
 * the read counterpart of FUN_CODE_d9d1. The base is the array symbol as in FUN_CODE_d9d1.
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xDD85.
 */
extern unsigned char xdata DAT_EXTMEM_9a00[];

unsigned char FUN_CODE_dd85(unsigned char reg)
{
    unsigned char *p;
    p = DAT_EXTMEM_9a00;
    p += reg;
    return *p;
}
