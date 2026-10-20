/* 8051_bank2 FUN_CODE_e004 @ 0xe004 (70 B).
 * Callers (byte scan, xref.py): FUN_CODE_60b9 (0x60c4, 0x64f0).
 * Code: read-modify-write of 32-bit controller register 0x0114: v = 9b91(0x114) (local at 0x08EA); bit 0 of v =
 * NOT bit 0x00 (JNB BIT 20h.0: bit set -> ANL #0FEh, clear -> ORL #01h, on the low byte); b317(0x114, v), tail LJMP.
 * The stray MOV A,R4 before the second ?C?LSTXDATA is Keil's own. DAT_BIT_0000 = bit address 0x00. No aids.
 */
extern bit DAT_BIT_0000;
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_e004(void)
{
    unsigned long v;
    v = FUN_CODE_9b91(0x0114);
    if (DAT_BIT_0000) v &= ~1UL; else v |= 1;
    FUN_CODE_b317(0x0114, v);
}
