/* FUN_a00c972c (leon2s 0xa00c972c-0xa00c9750, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns 1 when bit 1 of hardware register 0xcf018d00 is set, else 0.
 * Source form: a result byte that starts at 0, returned as r & 1 (as in FUN_a00aec2c).
 */
#define REG_8D00 (*(volatile unsigned int *)0xcf018d00)

unsigned char FUN_a00c972c(void)
{
    unsigned char r = 0;

    if (REG_8D00 & 2)
        r = 1;
    return r & 1;
}
