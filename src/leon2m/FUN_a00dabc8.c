/* leon2m FUN_a00dabc8 @ 0xa00dabc8  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802d290[]; /* 0xa802d290 */
extern int FUN_a01272c8(int);        /* 0xa01272c8 */

void FUN_a00dabc8(void)
{
    if (DAT_a802d290[0x1ea] == 0) {
        FUN_a01272c8(0);
        return;
    }
    FUN_a01272c8(DAT_a802d290[0x1eb]);
}
