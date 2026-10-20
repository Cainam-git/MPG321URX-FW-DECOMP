/* 8051_bank2 FUN_CODE_db76 @ 0xdb76
 * FUN_CODE_abce(XDATA 0x0912, FUN_CODE_e4e9(), 1, 0) (same call form as FUN_CODE_8437's abce(0x06f7, ..., 1, 0); the
 * address is the unsigned long at XDATA 0x071a), then returns 1 when the buffer bytes [2] [1] [0] [7] [6] [5] [4] [11]
 * [10] are 'N' 'V' 'T' 'S' 'C' '_' 'I' 'M' 'G', else 0. Byte-exact with OPTIMIZE(8,SPEED) LARGE (also 7 / 8, SMALL / LARGE: no locals, no tails).
 * FUN_CODE_abce is declared small as in FUN_CODE_8437 (n / f go to DATA 0x0F / 0x10).
 */
extern unsigned char xdata DAT_EXTMEM_0912[];
extern unsigned long FUN_CODE_e4e9(void);
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;

bit FUN_CODE_db76(void)
{
    FUN_CODE_abce(DAT_EXTMEM_0912, FUN_CODE_e4e9(), 1, 0);
    if (DAT_EXTMEM_0912[2] == 0x4e &&
        DAT_EXTMEM_0912[1] == 0x56 &&
        DAT_EXTMEM_0912[0] == 0x54 &&
        DAT_EXTMEM_0912[7] == 0x53 &&
        DAT_EXTMEM_0912[6] == 0x43 &&
        DAT_EXTMEM_0912[5] == 0x5f &&
        DAT_EXTMEM_0912[4] == 0x49 &&
        DAT_EXTMEM_0912[11] == 0x4d &&
        DAT_EXTMEM_0912[10] == 0x47)
    {
        return 1;
    }
    return 0;
}
