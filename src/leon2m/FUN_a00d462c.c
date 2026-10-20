/* leon2m FUN_a00d462c @ 0xa00d462c  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00d46c4: same code, constants swapped; byte-exact.
 */
extern unsigned char DAT_a802d290[23]; /* 0xa802d290 */
extern int FUN_a014a11c(int, int);     /* 0xa014a11c */

void FUN_a00d462c(void)
{
    unsigned char val = DAT_a802d290[0x13];
    if (val > 100)
        val = 100;
    DAT_a802d290[0x13] = val;
    FUN_a014a11c(1, val);
}
