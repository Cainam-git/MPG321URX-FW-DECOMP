/* 8051_bank2 FUN_CODE_dac5 @ 0xdac5 (87 B).
 * Callers (byte scan, xref.py): FUN_CODE_520d (0x522b), FUN_CODE_69da (0x6d64), FUN_CODE_b45f (LJMP 0xb5b1),
 * FUN_CODE_b97a (0xba4e).
 * Code: fill n * 32 bytes of the DATA buffer at 0x22 with val. LARGE parameters val (0x0986), n (0x0987); locals
 * i (0x0988) and p (generic pointer 00:0022 at 0x0989, ?C?CSTOPTR FUN_CODE_31f3 stores). The test i < n * 32 is a
 * signed int compare (XRL #80h). Declaration order matters: i before p gives the firmware's block layout
 * (p before i: 83 B, v/dac5_2.c). DAT_0022 as in FUN_CODE_e373. No aids.
 */
extern unsigned char data DAT_0022[];
void FUN_CODE_dac5(unsigned char val, unsigned char n)
{
    unsigned char i;
    unsigned char *p;
    p = DAT_0022;
    for (i = 0; i < n * 32; i++) p[i] = val;
}
