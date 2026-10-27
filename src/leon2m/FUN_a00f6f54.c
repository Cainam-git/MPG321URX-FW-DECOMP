/* FUN_a00f6f54 (leon2m 0xa00f6f54-0xa00f6f7c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes c & 0x7f to the word register 0xcf00ef1c when bit 7 of c is set, otherwise the low byte of ~c. Called by
 * FUN_a01471a0. It lies between FUN_a00f6f10 and FUN_a00f6f7c. Source form: x = ~c as the default, overridden when
 * bit 7 is set (the xnor sits in the branch delay slot).
 */
#define REG (*(volatile unsigned int *)0xcf00ef1c)

void FUN_a00f6f54(unsigned int c)
{
    unsigned char x = ~c;

    if (c & 0x80)
        x = c & 0x7f;
    REG = x;
}
