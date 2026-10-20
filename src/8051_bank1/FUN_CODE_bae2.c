/* 8051_bank1 FUN_CODE_bae2 @ 0xbae2 (116 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Selects one XDATA status register by ch (0 -> 0xF03C, 1 -> 0xF044, 2 -> 0xF08C, 3 -> 0xF094, 4 -> 0xF09E,
 * 5 -> 0xF0BB; any other ch leaves the generic pointer at 0) and polls it up to 12000 times for bit 6.
 * Returns 1 (carry) as soon as bit 6 reads set, 0 when the count runs out.
 * Callers: FUN_CODE_482e (0x4A6D) and FUN_CODE_4cb9 (0x4EA7).
 * LARGE: the counter lives in XDATA 0xA4D1..0xA4D2; the register is read through the generic pointer (?C?CLDPTR).
 */
extern unsigned char xdata DAT_EXTMEM_f03c, DAT_EXTMEM_f044, DAT_EXTMEM_f08c, DAT_EXTMEM_f094, DAT_EXTMEM_f09e, DAT_EXTMEM_f0bb;

bit FUN_CODE_bae2(unsigned char ch)
{
    unsigned int n;
    unsigned char *p;

    n = 12000;
    p = 0;
    switch (ch) {
    case 0: p = &DAT_EXTMEM_f03c; break;
    case 1: p = &DAT_EXTMEM_f044; break;
    case 2: p = &DAT_EXTMEM_f08c; break;
    case 3: p = &DAT_EXTMEM_f094; break;
    case 4: p = &DAT_EXTMEM_f09e; break;
    case 5: p = &DAT_EXTMEM_f0bb; break;
    }
    while (n != 0) {
        n--;
        if (*p & 0x40) return 1;
    }
    return 0;
}
