/* 8051_bank2 FUN_CODE_d6d1 @ 0xd6d1 (128 B).
 * Callers (byte scan, xref.py): FUN_CODE_3e68 (0x3f14, 0x3fc8, 0x452f, 0x462f).
 * Code: XDATA 0x0717 (ulong) = XDATA 0x08C9 (ulong) + 0x700; then tail call c60e(a, b, 0x0717 + c / 32)
 * (?C?ULDIV FUN_CODE_3380 by 0x20; b and the sum go to c60e's parameter block 0x0931 / 0x0935, the
 * ?_FUN_CODE_c60e?BYTE block already recorded for the accepted e141). LARGE parameters a (0x0920, R4..R7),
 * b (0x0924), c (0x0928). c60e prototype as in the accepted e141. `c / 32 + 0x0717` gives the same bytes. No aids.
 */
extern unsigned long xdata DAT_EXTMEM_08c9;
extern unsigned long xdata DAT_EXTMEM_0717;
void FUN_CODE_c60e(unsigned long a, unsigned long b, unsigned long c);
void FUN_CODE_d6d1(unsigned long a, unsigned long b, unsigned long c)
{
    DAT_EXTMEM_0717 = DAT_EXTMEM_08c9 + 0x700;
    FUN_CODE_c60e(a, b, DAT_EXTMEM_0717 + c / 32);
}
