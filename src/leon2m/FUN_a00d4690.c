/* leon2m FUN_a00d4690 @ 0xa00d4690  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802d290[]; /* 0xa802d290 */
extern int FUN_a014a2a0(int, int);   /* 0xa014a2a0 */

void FUN_a00d4690(void)
{
    unsigned char v = DAT_a802d290[0x15];
    if (v > 100)
        v = 100;
    DAT_a802d290[0x15] = v;
    FUN_a014a2a0(0, v);
}
