/* leon2m FUN_a00d46f8 @ 0xa00d46f8 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802d290[24]; /* 0xa802d290 */
extern int FUN_a014a2a0(int, int);     /* 0xa014a2a0 */

void FUN_a00d46f8(void)
{
    unsigned char v = DAT_a802d290[0x17];
    if (v > 100)
        v = 100;
    DAT_a802d290[0x17] = v;
    FUN_a014a2a0(2, v);
}
