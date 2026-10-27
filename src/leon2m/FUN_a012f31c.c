/* FUN_a012f31c (leon2m 0xa012f31c-0xa012f3b4, 152 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Finds i, the index of p[10] in the four-byte table DAT_001a5238 (the FUN_a012f2dc search, 0xff when absent), then
 * returns the first k = (i + j) & 3 for j = 1..4 whose table byte has the same bits 2..7 (& 0xfc) as
 * DAT_001a5238[i]; returns i when none does. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a012f2dc and FUN_a012f3b4. Source form: the FUN_a012f2dc search is a static
 * helper inlined here; int result, unsigned int k.
 */
extern const unsigned char DAT_001a5238[];
static unsigned char find(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < 4; i++) {
        unsigned char v = DAT_001a5238[i];
        if (c == v)
            return i;
    }
    return 0xff;
}
int FUN_a012f31c(const unsigned char *p)
{
    unsigned char i = find(p[10]);
    unsigned char j;
    unsigned int k;
    for (j = 1; j <= 4; j++) {
        k = (i + j) & 3;
        if ((DAT_001a5238[k] & 0xfc) == (DAT_001a5238[i] & 0xfc))
            return k;
    }
    return i;
}
