/* FUN_a00d0fe8 (leon2m 0xa00d0fe8-0xa00d10b4, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores p[1] = 0x89 and p[7] = 0xe0; copies three bytes of DAT_a802e1f0 to p[8..10] (from +6 for DAT_a802d2a1 = 2,
 * +9 for 1, +0x12 for 0); then stores to p[11] the XOR of 0x50 with p[0..10] (the FUN_a00d0f68 checksum over (0x89
 * & 0x7f) + 2 = 11 bytes). Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a00d0fa0 and FUN_a00d10b4. Source form: an if/else chain testing 2, 1, 0; the FUN_a00d0f68
 * checksum is a static helper inlined here (GCC folds p[1], so the loop bound is the constant 11).
 */
extern unsigned char DAT_a802d2a1;
extern unsigned char DAT_a802e1f0[];
static unsigned char csum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & 0x7f) + 2;
    unsigned char i;
    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}
void FUN_a00d0fe8(unsigned char *p)
{
    p[1] = 0x89;
    p[7] = 0xe0;
    if (DAT_a802d2a1 == 2) {
        p[8] = DAT_a802e1f0[6];
        p[9] = DAT_a802e1f0[7];
        p[10] = DAT_a802e1f0[8];
    }
    else if (DAT_a802d2a1 == 1) {
        p[8] = DAT_a802e1f0[9];
        p[9] = DAT_a802e1f0[10];
        p[10] = DAT_a802e1f0[11];
    }
    else if (DAT_a802d2a1 == 0) {
        p[8] = DAT_a802e1f0[18];
        p[9] = DAT_a802e1f0[19];
        p[10] = DAT_a802e1f0[20];
    }
    p[11] = csum(p, 0x50);
}
