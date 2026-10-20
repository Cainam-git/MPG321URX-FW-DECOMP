/* leon2s FUN_a0098b60 @ 0xa0098b60 (-mcpu=v8 -Os -g)
 * For the port byte p: clears the halfword DAT_a8079054[p], then sets bit 2 of DAT_a80788d2 if p == 0, or bit 3 if
 * p == 1. The compiler places the halfword store in the branch delay slot and hoists the second base address.
 */
extern unsigned short DAT_a8079054[]; /* 0xa8079054 */
extern unsigned char DAT_a80788d2;    /* 0xa80788d2 */

void FUN_a0098b60(unsigned int param_1)
{
    param_1 &= 0xff;
    DAT_a8079054[param_1] = 0;
    if (param_1 == 0) {
        DAT_a80788d2 |= 4;
    } else if (param_1 == 1) {
        DAT_a80788d2 |= 8;
    }
}
