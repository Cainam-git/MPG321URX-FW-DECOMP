/* 8051_bank2 FUN_CODE_ddbb @ 0xddbb (73 B).
 * Caller (byte scan, xref.py): FUN_CODE_b706 (0xb804).
 * Code: clear bits in a 32-bit controller register: v = 9b91(reg) (local at 0x098C), b317(reg, v & ~mask)
 * (~ = ?C?LNOT FUN_CODE_3412; value into b317's parameter home 0x0992), tail LJMP. LARGE parameters reg (0x0986)
 * and mask (0x0988..0x098B). Counterpart of FUN_CODE_dfbe (v | mask). `~mask & v` gives the same bytes. No aids.
 */
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_ddbb(unsigned int reg, unsigned long mask)
{
    unsigned long v;
    v = FUN_CODE_9b91(reg);
    FUN_CODE_b317(reg, v & ~mask);
}
