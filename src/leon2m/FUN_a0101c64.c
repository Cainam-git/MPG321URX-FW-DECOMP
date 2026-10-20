/* leon2m FUN_a0101c64 @ 0xa0101c64 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a0109110: same code, other constants.
 */
#define _DAT_cf016118 (*(volatile unsigned int *)0xcf016118)

void FUN_a0101c64(unsigned char param_1)
{
    if (param_1 != 0) {
        _DAT_cf016118 = _DAT_cf016118 | 0x80;
    } else {
        _DAT_cf016118 = _DAT_cf016118 & 0xffffff7f;
    }
}
