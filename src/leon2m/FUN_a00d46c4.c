/* leon2m FUN_a00d46c4 @ 0xa00d46c4 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802d290[23]; /* 0xa802d290 */
extern int FUN_a014a2a0(int, int);     /* 0xa014a2a0 */

void FUN_a00d46c4(void)
{
    unsigned char val = DAT_a802d290[0x16];
    if (val > 100)
        val = 100;
    DAT_a802d290[0x16] = val;
    FUN_a014a2a0(1, val);
}
