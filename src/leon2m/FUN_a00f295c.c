/* FUN_a00f295c (leon2m 0xa00f295c-0xa00f29d4, 120 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * With b = DAT_0019a2ec[c] + k (c above 7 counting as 0), returns the 24-bit value (register b + 2) << 16 |
 * (register b + 1 & 0xff) << 8 | (register b & 0xff), registers at 0xcf000000 + 4 * index. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00f2708 and FUN_a00f29d4.
 */
extern const unsigned short DAT_0019a2ec[];

unsigned int FUN_a00f295c(unsigned char c, unsigned char k)
{
    unsigned int b, v;

    if (c > 7)
        c = 0;
    b = DAT_0019a2ec[c] + k;
    v = *(volatile unsigned int *)(0xcf000000 | ((b + 2) << 2));
    v = (v << 8) | (*(volatile unsigned int *)(0xcf000000 | ((b + 1) << 2)) & 0xff);
    v = (v << 8) | (*(volatile unsigned int *)(0xcf000000 | (b << 2)) & 0xff);
    return v;
}
