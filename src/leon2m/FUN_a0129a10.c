/* leon2m FUN_a0129a10 @ 0xa0129a10 (-mcpu=v8 -O2 -g)
 * Returns bit param_1 of the halfword at 0xa802c9fe: ((int)h >> param_1) & 1. The shift count has no `& 0x1f`
 * mask, and the (int) cast makes GCC emit sra.
 */
extern unsigned short _DAT_a802c9fe; /* 0xa802c9fe */

int FUN_a0129a10(int param_1)
{
    return ((int)_DAT_a802c9fe >> param_1) & 1;
}
