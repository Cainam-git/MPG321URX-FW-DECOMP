/* leon2m FUN_a0129aa4 @ 0xa0129aa4  MATCH (-mcpu=v8 -O2 -g)
 * Returns bit param_1 of the 16-bit value at 0xA802CA00 (the value is shifted right by param_1, then masked with 1).
 * The shift count is used unmasked, as in the firmware: the source has no & 0x1F on param_1.
 */
extern unsigned short _DAT_a802ca00; /* 0xa802ca00 */

int FUN_a0129aa4(int param_1)
{
    return (int)_DAT_a802ca00 >> param_1 & 1;
}
