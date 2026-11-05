/* FUN_a00da288 (leon2s 0xa00da288-0xa00da388, 256 bytes), flags -mcpu=v8 -Os -g.
 * int (void). port = DAT_a8078832. rec = entry DAT_a8078800[port] (11 bytes each) of the 0xb0-byte row
 * ARR_a807a398[port]; b = rec[0], hi = b >> 4, lo = b & 0xf. v = byte of the 0x200-byte ring DAT_a8079f98[port]
 * at index DAT_a807880a[port] & 0x1ff. n = hi - 1, k = n / 2 plus 1 when n is odd, p = rec + k;
 * t = p[1] >> 7, bit = (p[2] & 0x10) != 0. Returns 1 when ARR_a8079c3d[bit] != (v & 0x7f), lo < hi and t == 0,
 * otherwise 0.
 * Source form: v holds the unmasked ring byte (the '& 0x7f' is in the compare); t is computed before bit.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078800[];
extern unsigned short DAT_a807880a[];
extern unsigned char ARR_a807a398[][16][11];
extern unsigned char DAT_a8079f98[][0x200];
extern unsigned char ARR_a8079c3d[];

int FUN_a00da288(void)
{
    unsigned char port = DAT_a8078832;
    unsigned char *rec = (unsigned char *)ARR_a807a398 + port * 0xb0 + DAT_a8078800[port] * 11;
    unsigned char b = rec[0];
    unsigned char hi = b >> 4;
    unsigned int v = DAT_a8079f98[port][DAT_a807880a[port] & 0x1ff];
    unsigned char lo = b & 0xf;
    int n = hi - 1;
    unsigned char k = n / 2;
    unsigned char bit;
    unsigned char *p;
    unsigned char t;

    if (n & 1)
        k = n / 2 + 1;
    p = rec + k;
    t = p[1] >> 7;
    bit = p[2] & 0x10;
    bit = bit != 0;
    if (ARR_a8079c3d[bit] != (v & 0x7f) && lo < hi && t == 0)
        return 1;
    return 0;
}
