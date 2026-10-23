/* leon2m FUN_a0109110 @ 0xa0109110 (-mcpu=v8 -O2 -g)
 * p != 0 -> sets bit 7 (0x80) of register 0xCF011AA0; p == 0 -> clears it.
 */
#define _DAT_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)

void FUN_a0109110(unsigned char param_1)
{
    if (param_1 != 0) {
        _DAT_cf011aa0 = _DAT_cf011aa0 | 0x80;
    } else {
        _DAT_cf011aa0 = _DAT_cf011aa0 & 0xffffff7f;
    }
}
