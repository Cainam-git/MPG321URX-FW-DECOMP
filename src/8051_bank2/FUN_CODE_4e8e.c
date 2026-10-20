/* FUN_CODE_4e8e, 8051_bank2 (update agent), range 0x4E8E..0x4FFA (364 B).
 * Options: OPTIMIZE(8,SPEED) LARGE. Judge: tools/diff8051.judge MATCH, exact None, 364/364.
 * Code facts: returns a bit (carry). LARGE parameters addr (ulong, 0x0907..0x090A, ?C?LSTXDATA at entry), base (uint,
 * memory parameter 0x090B..0x090C) and n (uchar, memory parameter 0x090D); local f at 0x090E. It calls
 * FUN_CODE_af07(addr, base + (n - k) * 2) for k = 1, 2, 3, 6 (the second argument goes to af07's memory parameter
 * 0x091A), and after each call tests the byte DAT_EXTMEM_01e6[DAT_EXTMEM_011b] (uint index): 'g'/'G' sets f bit 0,
 * 'm'/'M' bit 1, 'i'/'I' bit 2, and for k = 6 anything but '~' sets bit 3. Returns (f & 0x0F) == 0x0F.
 * Shape lever: the tested byte is named twice in each || test (Keil reads it once and keeps it in R7); a local
 * 'c = ...; if (c == 'g' || c == 'G')' puts it in R6 (v/4e8e_1.c, 98.4 %).
 * Caller: FUN_CODE_140d (0x1881), a part of FUN_CODE_1000 in the af07 updater module (FUN_CODE_a17e); 4e8e uses no
 * common-entry block, so the bytes do not say whether it sits in that module. Judge key: ?FUN_CODE_4e8e?XD 2311
 * (0x0907). No aids.
 */
extern unsigned int xdata DAT_EXTMEM_011b;
extern unsigned char xdata DAT_EXTMEM_01e6[];
extern void FUN_CODE_af07(unsigned long addr, unsigned int v);
bit FUN_CODE_4e8e(unsigned long addr, unsigned int base, unsigned char n)
{
    unsigned char f;
    f = 0;
    FUN_CODE_af07(addr, base + (n - 1) * 2);
    if (DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'g' || DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'G') f |= 1;
    FUN_CODE_af07(addr, base + (n - 2) * 2);
    if (DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'm' || DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'M') f |= 2;
    FUN_CODE_af07(addr, base + (n - 3) * 2);
    if (DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'i' || DAT_EXTMEM_01e6[DAT_EXTMEM_011b] == 'I') f |= 4;
    FUN_CODE_af07(addr, base + (n - 6) * 2);
    if (DAT_EXTMEM_01e6[DAT_EXTMEM_011b] != '~') f |= 8;
    return (f & 0x0f) == 0x0f;
}
