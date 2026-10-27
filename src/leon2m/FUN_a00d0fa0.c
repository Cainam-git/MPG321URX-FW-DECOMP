/* FUN_a00d0fa0 (leon2m 0xa00d0fa0-0xa00d0fe8, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores p[1] = 0x88, p[8] = 2, p[9] = 1, p[7] = 0, then stores to p[10] the XOR of 0x50 with p[0..9] (the
 * FUN_a00d0f68 checksum over (p[1] & 0x7f) + 2 = 10 bytes). Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00d0f68 and FUN_a00d0fe8. Source form: the FUN_a00d0f68
 * checksum is a static helper inlined here; GCC folds p[1] from the store, so the loop bound is the constant 10
 * (cmp 10 / bcs).
 */
static unsigned char csum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

void FUN_a00d0fa0(unsigned char *p)
{
    p[1] = 0x88;
    p[8] = 2;
    p[9] = 1;
    p[7] = 0;
    p[10] = csum(p, 0x50);
}
