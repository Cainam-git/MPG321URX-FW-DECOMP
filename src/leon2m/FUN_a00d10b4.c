/* FUN_a00d10b4 (leon2m 0xa00d10b4-0xa00d1110, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores bit 0 and bits 1..5 (0x3e) of the byte DAT_a802d274[0x10] to p[6] and p[7], then stores to p[8] the XOR of
 * 0x50 with the (p[1] & 0x7f) + 2 bytes at p (the FUN_a00d0f68 checksum). Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a00d0fe8 and FUN_a00d1110. Source form: the
 * FUN_a00d0f68 checksum is a static helper inlined here.
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

void FUN_a00d10b4(unsigned char *p)
{
    p[6] = DAT_a802d274[0x10] & 1;
    p[7] = DAT_a802d274[0x10] & 0x3e;
    p[8] = csum(p, 0x50);
}
