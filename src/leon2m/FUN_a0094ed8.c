/* leon2m FUN_a0094ed8 @ 0xa0094ed8 (-mcpu=v8 -O2 -g)
 * The key changes:
 * - Made the function `void` (no return value in the assembly)
 * - Corrected the types of the extern functions to match the actual call patterns
 * - Used `DAT_a8025c56 + 1` which naturally promotes to int for the calls, and the `& 0xff` in the first call handles the byte masking
 */
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a8c88(void);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ac388(int);

void FUN_a0094ed8(void)
{
    FUN_a00a93bc((_DAT_a802afec + 0x1e) & 0xff);
    FUN_a00a8c88();
    FUN_a00ac388(1);
    FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
    FUN_a00a9650(DAT_a8025c56 + 1, 0);
    _DAT_a802afec = 0x56;
    FUN_a00a9650(0, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
