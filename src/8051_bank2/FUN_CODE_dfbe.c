/* 8051_bank2 FUN_CODE_dfbe @ 0xdfbe (70 B).
 * Callers (byte scan, xref.py): 0x5bc4, 0x5c0b (inside FUN_CODE_573b, a functions.json gap), FUN_CODE_69da (0x6c39),
 * FUN_CODE_b706 (0xb7bc), FUN_CODE_d2fb (0xd382).
 * Code: set bits in a 32-bit controller register: v = 9b91(reg) (local at 0x098C), b317(reg, v | mask) (value into
 * b317's parameter home 0x0992 with ?C?LSTXDATA), tail LJMP. LARGE parameters reg (0x0986) and mask (0x098A..).
 * Operand order matters: `mask | v` loads v first and is 72 B. Prototypes as in the accepted bank-2
 * files (9b91 / b317 register helpers). No aids.
 */
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_dfbe(unsigned int reg, unsigned long mask)
{
    unsigned long v;
    v = FUN_CODE_9b91(reg);
    FUN_CODE_b317(reg, v | mask);
}
