/* leon2m FUN_a00d45f8 @ 0xa00d45f8 (-mcpu=v8 -Os -g)
 * Twin of FUN_a00d4690: same code, other constants.
 */
extern unsigned char DAT_a802d290[]; /* 0xa802d290 */
extern int FUN_a014a11c(int, int);   /* 0xa014a11c */

void FUN_a00d45f8(void)
{
    unsigned char v = DAT_a802d290[0x12];
    if (v > 100)
        v = 100;
    DAT_a802d290[0x12] = v;
    FUN_a014a11c(0, v);
}
