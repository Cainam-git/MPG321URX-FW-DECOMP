/* FUN_a00f14e4 (leon2m 0xa00f14e4-0xa00f154c, 104 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * With b = DAT_a8026a7e[c] + k (c above 3 counting as 0), returns the halfword (register b + 1) << 8 | (register b)
 * & 0xff, registers at 0xcf000000 + 4 * index. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00f1374 and FUN_a00f154c. Source form: the low register is read
 * into a local first.
 */
extern unsigned short DAT_a8026a7e[];

unsigned short FUN_a00f14e4(unsigned char c, unsigned short k)
{
    unsigned int b, lo;

    if (c > 3)
        c = 0;
    b = DAT_a8026a7e[c] + k;
    lo = *(volatile unsigned int *)(0xcf000000 | (b << 2));
    return (*(volatile unsigned int *)(0xcf000000 | ((b + 1) << 2)) << 8) | (lo & 0xff);
}
