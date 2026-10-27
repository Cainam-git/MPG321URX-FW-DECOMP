/* FUN_a00d1110 (leon2m 0xa00d1110-0xa00d1184, 116 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores p[1] = 0x93 and p[7] = 0xe0, copies the 13 bytes DAT_a802d274[3..15] to p[8..20], then stores to p[0x15]
 * the XOR of 0x50 with the (p[1] & 0x7f) + 2 bytes at p (the FUN_a00d0f68 checksum). Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a00d10b4 and FUN_a00d1184. Source
 * form: the FUN_a00d0f68 checksum is a static helper inlined here; an int loop counter for the copy.
 */
extern unsigned char DAT_a802d274[];

static unsigned char csum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

void FUN_a00d1110(unsigned char *p)
{
    int i;

    p[1] = 0x93;
    p[7] = 0xe0;
    for (i = 0; i < 13; i++)
        p[8 + i] = DAT_a802d274[3 + i];
    p[0x15] = csum(p, 0x50);
}
