/* FUN_a01231e4 (leon2m 0xa01231e4-0xa0123244, 96 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * With b = DAT_001a3070[c] (c above 1 counting as 0), returns the halfword ((register b + 0x40) << 8 | (register b
 * + 0x41) & 0xff), registers at 0xcf000000 + 4 * index. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a0123184 and FUN_a0123244. Source form: the low register
 * is read into a local first (the firmware reads it first).
 */
extern const unsigned short DAT_001a3070[];
unsigned short FUN_a01231e4(unsigned char c)
{
    unsigned int b, lo;
    unsigned short v;
    if (c > 1)
        c = 0;
    b = DAT_001a3070[c];
    lo = *(volatile unsigned int *)(0xcf000000 | ((b + 0x41) << 2));
    v = (*(volatile unsigned int *)(0xcf000000 | ((b + 0x40) << 2)) << 8) | (lo & 0xff);
    return v;
}
